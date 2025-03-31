#include "ssacli.h"

RaidControllerInfo ssacli::getControllerInfo() {
    return controllerInfo;
}

std::vector<RaidDriveInfo> ssacli::getDrivesInfo() {
    return drivesInfo;
}

void ssacli::parseControllerData(const std::string input) {
    std::regex serialRegex(R"(Serial Number:\s*(\S+))");
    std::regex statusRegex(R"(Controller Status:\s*(\S+))");
    std::regex temperatureRegex(R"(Controller Temperature \(C\):\s*(\d+))");

    std::smatch match;

    if (std::regex_search(input, match, serialRegex)) {
        controllerInfo.setSerialNumber(match[1].str());
    }

    if (std::regex_search(input, match, statusRegex)) {
        controllerInfo.setControllerStatus(match[1].str());
    }

    if (std::regex_search(input, match, temperatureRegex)) {
        controllerInfo.setControllerTemperatureC(std::stoi(match[1].str()));
    }
}

void ssacli::parseDriveData(const std::string input) {
    // Регулярные выражения для каждого элемента
    std::regex bayRegex(R"(Bay:\s*(\d+))");
    std::regex statusRegex(R"(Status:\s*(\w+))");
    std::regex sizeRegex(R"(Size:\s*([\d\.]+\s*\w+))");
    std::regex serialNumberRegex(R"(Serial Number:\s*([\w\d]+))");
    std::regex wwidRegex(R"(WWID:\s*([\w\d]+))");
    std::regex modelRegex(R"(Model:\s*([^\n]+))");
    std::regex tempRegex(R"(Current Temperature \(C\):\s*(\d+))");

    std::smatch match;
    RaidDriveInfo currentDrive;

    // Разделяем ввод по разделителям
    std::string::const_iterator searchStart(input.cbegin());
    while (std::regex_search(searchStart, input.cend(), match, bayRegex)) {
        currentDrive.setBay(match[1]);

        if (std::regex_search(searchStart, input.cend(), match, statusRegex))
            currentDrive.setStatus(match[1]);

        if (std::regex_search(searchStart, input.cend(), match, sizeRegex))
            currentDrive.setSize(match[1]);

        if (std::regex_search(searchStart, input.cend(), match, serialNumberRegex))
            currentDrive.setSerialNumber(match[1]);

        if (std::regex_search(searchStart, input.cend(), match, wwidRegex))
            currentDrive.setWwid(match[1]);

        if (std::regex_search(searchStart, input.cend(), match, modelRegex))
            currentDrive.setModel(match[1]);

        if (std::regex_search(searchStart, input.cend(), match, tempRegex))
            currentDrive.setTemperature(std::stoi(match[1]));

        drivesInfo.push_back(currentDrive);

        searchStart = match.suffix().first;
    }
}

void ssacli::run()
{
    controllerInfo = RaidControllerInfo();
    drivesInfo = std::vector<RaidDriveInfo>();
#ifdef NDEBUG
    std::string controllerInfoOutput;
    std::string diskInfoOutput;

    try {
        controllerInfoOutput = runCommand("/opt/raidutils/ssacli ctrl all show detail");
        diskInfoOutput = runCommand("/opt/raidutils/ssacli ctrl slot=0 pd all show detail");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error executing the command, trying with sudo: " << e.what() << std::endl;
        try {
            controllerInfoOutput = runCommandWithSudo("/opt/raidutils/ssacli ctrl all show detail");
            diskInfoOutput = runCommandWithSudo("/opt/raidutils/ssacli ctrl slot=0 pd all show detail");
        }
        catch (const std::runtime_error& e) {
            std::cerr << "Error executing the command with sudo: " << e.what() << std::endl;
        }
    }
#else
    testData _testData;
    std::string controllerInfoOutput = _testData.getSsacliControllerTestData();
    std::string diskInfoOutput = _testData.getSsacliDiskTestData();
#endif

    parseControllerData(controllerInfoOutput);
    parseDriveData(diskInfoOutput);
}
