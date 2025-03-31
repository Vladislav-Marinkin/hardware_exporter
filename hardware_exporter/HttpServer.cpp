#include "HttpServer.h"

HttpServer::HttpServer(const std::string& ip, int port) : ip_(ip), port_(port) {
    controllerTypeParser controllerTypeParser;
    controllerType = controllerTypeParser.getControllerType();
}

void HttpServer::start() {
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Создание сокета
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Настройка адреса
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(ip_.c_str());
    address.sin_port = htons(port_);

    // Привязка сокета к адресу
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Прослушивание порта
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    std::cout << "Listening on IP " << ip_ << " and port " << port_ << "...\n";

    // Принимаем соединение и обрабатываем запрос
    while (true) {
        if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            continue;
        }

        std::thread(&HttpServer::handle_request, this, new_socket).detach();
    }
}

void HttpServer::handle_request(int client_socket) {
    char buffer[1024] = { 0 };
    read(client_socket, buffer, sizeof(buffer));

    std::cout << "Request received:\n" << buffer << std::endl;

    // Проверка на запрос по пути /metrics
    std::string request(buffer);
    size_t pos = request.find("GET /metrics");

    if (pos != std::string::npos) {
        // Если запрос на /metrics, отправляем данные
        send_metrics(client_socket);
    }
    else {
        // Ответ для всех других путей
        std::string response = "HTTP/1.1 404 Not Found\r\n";
        response += "Content-Type: text/html; charset=UTF-8\r\n";
        response += "Connection: close\r\n";
        response += "\r\n";
        response += "<html><body><h1>404 Not Found</h1></body></html>";

        send(client_socket, response.c_str(), response.size(), 0);
    }

    // Закрытие соединения
    close(client_socket);
}

void HttpServer::send_metrics(int client_socket) {
    _ipmitool.run();
    std::vector<FanDriveInfo> fanDriveInfo = _ipmitool.getFanDrivesInfo();
    std::string fan_metrics = generateFanMetrics(fanDriveInfo);

    std::string raid_metrics;

#ifdef NDEBUG
    if (controllerType == "Adaptec") {
        _adaptec.run();
        RaidControllerInfo controllerInfo = _adaptec.getControllerInfo();
        std::vector<RaidDriveInfo> drivesInfo = _adaptec.getDrivesInfo();

        raid_metrics += generateRaidMetrics(controllerInfo, drivesInfo, controllerType);
    }
    if (controllerType == "HP") {
        _ssacli.run();
        RaidControllerInfo controllerInfo = _ssacli.getControllerInfo();
        std::vector<RaidDriveInfo> drivesInfo = _ssacli.getDrivesInfo();

        raid_metrics += generateRaidMetrics(controllerInfo, drivesInfo, controllerType);
    }
    if (controllerType == "LSI") {
        _lsi.run();
        RaidControllerInfo controllerInfo = _lsi.getControllerInfo();
        std::vector<RaidDriveInfo> drivesInfo = _lsi.getDrivesInfo();

        raid_metrics += generateRaidMetrics(controllerInfo, drivesInfo, controllerType);
    }
#else
    _adaptec.run();
    _ssacli.run();
    _lsi.run();

    raid_metrics += generateRaidMetrics(_adaptec.getControllerInfo(), _adaptec.getDrivesInfo(), "Adaptec");
    raid_metrics += generateRaidMetrics(_ssacli.getControllerInfo(), _ssacli.getDrivesInfo(), "Hewlett-Packard");
    raid_metrics += generateRaidMetrics(_lsi.getControllerInfo(), _lsi.getDrivesInfo(), "LSI");
#endif

    std::string response = "HTTP/1.1 200 OK\r\n";
    response += "Content-Type: text/plain; charset=UTF-8\r\n";
    response += "Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0\r\n";
    response += "Connection: close\r\n";
    response += "\r\n";
    response += fan_metrics;
    response += raid_metrics;

    // Отправка данных клиенту
    send(client_socket, response.c_str(), response.size(), 0);
    std::cout << "Metrics sent.\n";
}

std::string HttpServer::generateRaidMetrics(RaidControllerInfo controllerInfo, std::vector<RaidDriveInfo> drivesInfo, std::string controllerType)
{
    std::string metrics;

    std::string status_upper = to_uppercase(controllerInfo.getControllerStatus());

    metrics += "# HELP controller_temperature_c Controller temperature in Celsius\n";
    metrics += "# TYPE controller_temperature_c gauge\n";
    metrics += "controller_temperature_c{serial=\"" + controllerInfo.getSerialNumber() + "\",type=\"" + controllerType + "\"} " + std::to_string(controllerInfo.getControllerTemperatureC()) + "\n";

    metrics += "# HELP controller_status Controller status (1 = OK, 0 = Not OK)\n";
    metrics += "# TYPE controller_status gauge\n";
    int status_value = (status_upper == "OK" || status_upper == "OPTIMAL") ? 1 : 0;
    metrics += "controller_status{serial=\"" + controllerInfo.getSerialNumber() + "\",type=\"" + controllerType + "\",status=\"" + status_upper + "\"} " + std::to_string(status_value) + "\n";

    metrics += "# HELP drive_temperature_c Drive temperature in Celsius\n";
    metrics += "# TYPE drive_temperature_c gauge\n";
    for (const auto& drive : drivesInfo) {
        status_upper = to_uppercase(drive.getStatus());
        metrics += "drive_temperature_c{bay=\"" + drive.getBay() + "\",serial=\"" + drive.getSerialNumber() + "\",wwid=\"" + drive.getWwid() + "\",model=\"" + drive.getModel() + "\"} " + std::to_string(drive.getTemperature()) + "\n";
    }

    metrics += "# HELP drive_status Drive status (1 = OK, 0 = Not OK)\n";
    metrics += "# TYPE drive_status gauge\n";
    for (const auto& drive : drivesInfo) {
        status_upper = to_uppercase(drive.getStatus());
        int drive_status_value = (status_upper == "OK" || status_upper == "ONLINE" || status_upper == "GOOD") ? 1 : 0;
        metrics += "drive_status{bay=\"" + drive.getBay() + "\",serial=\"" + drive.getSerialNumber() + "\",wwid=\"" + drive.getWwid() + "\",model=\"" + drive.getModel() + "\",status=\"" + status_upper + "\"} " + std::to_string(drive_status_value) + "\n";
    }

    return metrics;
}

std::string HttpServer::generateFanMetrics(std::vector<FanDriveInfo> fanInfoList)
{
    std::string metrics;

    metrics += "# HELP fan_temperature_c Cooler temperature in Celsius\n";
    metrics += "# TYPE fan_temperature_c gauge\n";
    for (const auto& fan : fanInfoList) {
        metrics += "fan_temperature_c{name=\"" + fan.getName() + "\"} " + std::to_string(fan.getTemperatureC()) + "\n";
    }

    metrics += "# HELP fan_status Cooler status (1 = OK, 0 = Not OK)\n";
    metrics += "# TYPE fan_status gauge\n";
    for (const auto& fan : fanInfoList) {
        int status_value = (to_uppercase(fan.getStatus()) == to_uppercase("ok")) ? 1 : 0;
        metrics += "fan_status{name=\"" + fan.getName() + "\",status=\"" + fan.getStatus() + "\"} " + std::to_string(status_value) + "\n";
    }

    metrics += "# HELP fan_rpm Cooler RPM speed\n";
    metrics += "# TYPE fan_rpm gauge\n";
    for (const auto& fan : fanInfoList) {
        metrics += "fan_rpm{name=\"" + fan.getName() + "\"} " + fan.getRpm() + "\n";
    }

    return metrics;
}

std::string HttpServer::to_uppercase(const std::string& str)
{
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), [](unsigned char c) { return std::toupper(c); });
    return result;
}
