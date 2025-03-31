#include "ipmitool.h"

void ipmitool::parseFanDrive(const std::string input) {
    std::vector<std::string> lines;
    std::istringstream stream(input);
    std::string line;

    while (std::getline(stream, line)) {
        if (!line.empty()) {
            lines.push_back(line);
        }
    }

    std::regex fanLineRegex(R"(^\s*(.+?)\s*\|\s*([\w\d]+)\s*\|\s*(\w+)\s*\|\s*([\d.]+)\s*\|\s*(\d+)?(?:\s*RPM)?)");

    for (const std::string& line : lines) {
        std::smatch match;
        if (std::regex_match(line, match, fanLineRegex)) {
            FanDriveInfo currentFan;
            currentFan.setName(match[1]);

            currentFan.setStatus(match[3]);

            if (match[4].matched)
                currentFan.setTemperatureC(std::stof(match[4]));

            if (match[5].matched) {
                currentFan.setRpm(match[5]);
            }
            else {
                currentFan.setRpm("0");
            }

            fanDrivesInfo.push_back(currentFan);
        }
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
