#include "adaptec.h"

void adaptec::parseControllerData(const std::string input)
{
    std::regex serialRegex(R"(Controller Serial Number\s*:\s*(\S+))");
    std::regex statusRegex(R"(Controller Status\s*:\s*(\S+))");
    std::regex temperatureRegex(R"(Current Temperature\s*:\s*(\d+))");

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

void adaptec::parseDriveData(const std::string input)
{
    // Регулярные выражения для каждого элемента
    std::regex bayRegex(R"(Device\s*#(\d+))");
    std::regex statusRegex(R"(State\s*:\s*(\w+))");
    std::regex sizeRegex(R"(Total Size\s*:\s*([\d\.]+\s*\w+))");
    std::regex serialNumberRegex(R"(Serial number\s*:\s*([\w\d]+))");
    std::regex wwidRegex(R"(Device #\d+[\s\S]*?Attached SAS Address\s*:\s*([\w\d]+))");
    std::regex modelRegex(R"(Device #\d+[\s\S]*?Model\s*:\s*([^\n]+))");
    std::regex tempRegex(R"(Device #\d+[\s\S]*?Temperature\s*:\s*(\d+))");

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

void adaptec::run()
{
    controllerInfo = RaidControllerInfo();
    drivesInfo = std::vector<RaidDriveInfo>();
#ifdef NDEBUG
    std::string infoOutput;

    try {
        infoOutput = runCommand("/opt/raidutils/arcconf getconfig 1");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error executing the command, trying with sudo: " << e.what() << std::endl;
        try {
            infoOutput = runCommandWithSudo("/opt/raidutils/arcconf getconfig 1");
        }
        catch (const std::runtime_error& e) {
            std::cerr << "Error executing the command with sudo: " << e.what() << std::endl;
        }
    }
#else
    testData _testData;
    std::string infoOutput = _testData.getAdaptecTestData();
#endif

    parseControllerData(infoOutput);
    parseDriveData(infoOutput);
}

RaidControllerInfo adaptec::getControllerInfo()
{
	return controllerInfo;
}

std::vector<RaidDriveInfo> adaptec::getDrivesInfo()
{
	return drivesInfo;
}
