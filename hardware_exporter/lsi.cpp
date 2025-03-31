#include "lsi.h"

RaidControllerInfo lsi::getControllerInfo() {
    return controllerInfo;
}

std::vector<RaidDriveInfo> lsi::getDrivesInfo() {
    return drivesInfo;
}

void lsi::parseControllerData(const std::string input) {
    std::regex serialRegex(R"(Serial Number:\s*(\S+))");
    std::regex statusRegex(R"(State\s*:\s*(\S+))");
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

void lsi::parseDriveData(const std::string input) {
    // Регулярные выражения для каждого элемента
    std::regex bayRegex(R"(Slot Number:\s*(\d+))");
    std::regex statusRegex(R"(Firmware state:\s*([^\(,]+))");
    std::regex sizeRegex(R"(Raw Size:\s*([\d\.]+\s*\w+))");
    std::regex serialNumberRegex(R"(WWN:\s*([\w\d]+))");
    std::regex wwidRegex(R"(SAS Address\(0\):\s*(0x[\da-fA-F]+))");
    std::regex modelRegex(R"(Inquiry Data:\s*([^\n]+))");
    std::regex tempRegex(R"(Drive Temperature :(\d+)C)");

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

void lsi::run()
{
    controllerInfo = RaidControllerInfo();
    drivesInfo = std::vector<RaidDriveInfo>();
#ifdef NDEBUG
    std::string controllerInfoOutput;
    std::string diskInfoOutput;

    try {
        controllerInfoOutput = runCommand("/opt/raidutils/MegaCli64 -LDInfo -Lall -aALL");
        diskInfoOutput = runCommand("sudo /opt/raidutils/MegaCli64 -PDList -Aall");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error executing the command, trying with sudo: " << e.what() << std::endl;
        try {
            controllerInfoOutput = runCommandWithSudo("/opt/raidutils/MegaCli64 -LDInfo -Lall -aALL");
            diskInfoOutput = runCommandWithSudo("sudo /opt/raidutils/MegaCli64 -PDList -Aall");
        }
        catch (const std::runtime_error& e) {
            std::cerr << "Error executing the command with sudo: " << e.what() << std::endl;
        }
    }
#else
    testData _testData;
    std::string controllerInfoOutput = _testData.getLSIControllerTestData();
    std::string diskInfoOutput = _testData.getLSIDiskTestData();
#endif

    parseControllerData(controllerInfoOutput);
    parseDriveData(diskInfoOutput);
}