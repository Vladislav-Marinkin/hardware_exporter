#include "RaidControllerInfo.h"

std::string RaidControllerInfo::normalizeSpaces(const std::string& input)
{
    std::istringstream iss(input);
    std::ostringstream oss;
    std::string word;
    bool first = true;

    while (iss >> word) {
        if (!first) {
            oss << ' ';
        }
        oss << word;
        first = false;
    }

    return oss.str();
}

RaidControllerInfo::RaidControllerInfo() : serialNumber("null"), controllerStatus("null"), controllerTemperatureC(0) {}

std::string RaidControllerInfo::getSerialNumber() const {
    return normalizeSpaces(serialNumber);
}

void RaidControllerInfo::setSerialNumber(const std::string& serial) {
    serialNumber = serial;
}

std::string RaidControllerInfo::getControllerStatus() const {
    return normalizeSpaces(controllerStatus);
}

void RaidControllerInfo::setControllerStatus(const std::string& status) {
    controllerStatus = status;
}

int RaidControllerInfo::getControllerTemperatureC() const {
    return controllerTemperatureC;
}

void RaidControllerInfo::setControllerTemperatureC(int temperature) {
    controllerTemperatureC = temperature;
}
