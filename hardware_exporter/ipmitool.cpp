#include "ipmitool.h"

int extractNumber(const std::string& str) {
    std::string numStr;
    bool foundNumber = false;

    for (char c : str) {
        if (std::isdigit(c) || c == '.') {
            numStr.push_back(c);
            foundNumber = true;
        }
        else if (foundNumber) {
            break;
        }
    }

    if (!numStr.empty()) {
        try {
            double value = std::stod(numStr);
            if (numStr.find('.') != std::string::npos) {
                value *= 120;
            }
            return static_cast<int>(value);
        }
        catch (...) {
            return 0;
        }
    }
    return 0;
}

void ipmitool::parseFanDrive(const std::string input) {
    std::vector<std::string> lines;
    std::istringstream stream(input);
    std::string line;

    while (std::getline(stream, line)) {
        if (!line.empty() && line.find("Fully Redundant") == std::string::npos && line.find("Device Present") == std::string::npos && line.find("DutyCycle") == std::string::npos) {
        //if (!line.empty()) {
            lines.push_back(line);
        }
    }

    //std::regex fanLineRegex(R"(^\s*(.+?)\s*\|\s*([\w\d]+)\s*\|\s*(\w+)\s*\|\s*([\d.]+)\s*\|\s*(\d+)?(?:\s*RPM)?)");
    //std::regex fanLineRegex(R"(^\s*(.+?)\s*\|\s*([\w\d]+)\s*\|\s*(\w+)\s*\|\s*([\d.]+)?\s*\|\s*(\d+)?(?:\s*RPM|\s*percent)?)");
    //std::regex fanLineRegex(R"(^\s*(.+?)\s*\|\s*([\w\d]+)\s*\|\s*(\w+)\s*\|\s*([\d.]+)?\s*\|\s*(\d+)?(?:\s*RPM)?)");
    //std::regex fanLineRegex(R"(^\s*(.+?)\s*\|\s*([\w\d]+)\s*\|\s*(\w+)\s*\|\s*([\d.]+)?\s*\|\s*(\d+)?\s*(?:RPM)?)");
    //std::regex fanLineRegex(R"(^\s*(.+?)\s*\|\s*([\w\d]+)\s*\|\s*(\w+)\s*\|\s*([\d.]+)?\s*\|\s*([\d.]+)?(?:\s*RPM| percent)?)");
    //std::regex fanLineRegex(R"(^\s*(.+?)\s*\|\s*([\w\d]+)\s*\|\s*(\w+)\s*\|\s*([\d.]+)?\s*\|\s*([\d.]+)?(?:\s*RPM|\s*percent\s*)?)");
    //std::regex fanLineRegex(R"(([^|]+)\s*\|[^|]+\|\s*(\w+)\s*\|[^|]+\|\s*([0-9]+\.?[0-9]*)\s*(RPM|percent)?)");
    //std::regex fanLineRegex(R"(([\w\s]+)\s*\|\s*([0-9A-Fa-f]{2}h)\s*\|\s*(ok|fail)\s*\|\s*([\d.]+)\s*\|\s*(\d+\.\d+\s*percent|\d+\s*RPM))");
    //std::regex fanLineRegex(R"(([\w\s]+)\s*\|\s*([0-9A-Fa-f]{2}h)\s*\|\s*(ok|fail)\s*\|\s*([\d.]+)\s*\|\s*(\d+\.\d+\s*percent,\s*|\d+\s*RPM))");
    //std::regex fanLineRegex(R"(([\w\s]+)\s*\|\s*([0-9A-Fa-f]{2}h)\s*\|\s*(ok|fail)\s*\|\s*([\d.]+)\s*\|\s*(\d+\.\d+)\s*(percent|RPM)?)");
    //std::regex fanLineRegex(R"(([\w\s]+)\s*\|\s*([0-9A-Fa-f]{2}h)\s*\|\s*(ok|fail)\s*\|\s*([\d.]+)\s*\|\s*(\d+(\.\d+)?)\s*percent,)");
    //std::regex fanLineRegex(R"(^\s*(.+?)\s*\|\s*([\w\d]+)\s*\|\s*(\w+)\s*\|\s*([\d.]+)\s*\|\s*(\d+(\.\d+)?\s*)?)");
    //std::regex fanLineRegex(R"(^\s*(.+?)\s*\|\s*([\w\d]+)\s*\|\s*(\w+)\s*\|\s*([\d.]+)\s*\|\s*(.*?)\s*$)");
    
    //std::regex fanLineRegex(R"(^\s*(.+?)\s*\|\s*([\w\d]+)\s*\|\s*(\w+)\s*\|\s*([\d.]+)\s*\|\s*(.*?)\s*$)");
    std::regex fanLineRegex(R"(^\s*(.+?)\s*\|\s*([\w\d]+)\s*\|\s*(\w+)\s*\|\s*([\d.]+)\s*\|\s*(.*?)\s*$)");

    for (const std::string& line : lines) {
        std::smatch match;
        if (std::regex_match(line, match, fanLineRegex)) {
            FanDriveInfo currentFan;
            currentFan.setName(match[1]);

            currentFan.setStatus(match[3]);

            if (match[4].matched)
                currentFan.setTemperatureC(std::stof(match[4]));

            if (match[5].matched) {
                currentFan.setRpm(std::to_string(extractNumber(match[5])));
            }
            else {
                currentFan.setRpm("0.0");
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
