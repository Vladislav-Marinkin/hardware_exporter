#include "ipmitool.h"

void ipmitool::parseFanDrive(const std::string input)
{
    // Регулярные выражения для каждого элемента
    std::regex nameRegex(R"(System Fan\s*(\w+))");
    std::regex statusRegex(R"(System Fan\s*\w+\s*\|\s*\w+\s*\|\s*(\w+))");
    std::regex tempRegex(R"(System Fan\s*\w+\s*\|\s*\w+\s*\|\s*\w+\s*\|\s*([\d.]+))");
    std::regex rpmRegex(R"(System Fan\s*\w+\s*\|\s*\w+\s*\|\s*\w+\s*\|\s*[\d.]+\s*\|\s*(\d+)\s*RPM)");

    std::smatch match;

    // Разделяем ввод по разделителям
    std::string::const_iterator searchStart(input.cbegin());
    while (std::regex_search(searchStart, input.cend(), match, nameRegex)) {
        FanDriveInfo currentFan;

        currentFan.setName(match[1]);

        if (std::regex_search(searchStart, input.cend(), match, statusRegex))
            currentFan.setStatus(match[1]);

        if (std::regex_search(searchStart, input.cend(), match, tempRegex))
            currentFan.setTemperatureC(std::stof(match[1]));

        if (std::regex_search(searchStart, input.cend(), match, rpmRegex))
            currentFan.setRpm(match[1]);

        fanDrivesInfo.push_back(currentFan);

        searchStart = match.suffix().first;
    }

}

void ipmitool::run()
{
    fanDrivesInfo = std::vector<FanDriveInfo>();
#ifdef NDEBUG
    std::string infoOutput;

    try {
        infoOutput = runCommand("ipmitool sdr type Fan");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error executing the command, trying with sudo: " << e.what() << std::endl;
        try {
            infoOutput = runCommandWithSudo("ipmitool sdr type Fan");
        }
        catch (const std::runtime_error& e) {
            std::cerr << "Error executing the command with sudo: " << e.what() << std::endl;
        }
    }
#else
    testData _testData;
    std::string infoOutput = _testData.getFanDriveData();
#endif

    parseFanDrive(infoOutput);
}

std::vector<FanDriveInfo> ipmitool::getFanDrivesInfo()
{
    return fanDrivesInfo;
}
