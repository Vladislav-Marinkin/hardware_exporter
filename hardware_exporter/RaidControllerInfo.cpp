#include "RaidControllerInfo.h"

RaidControllerInfo::RaidControllerInfo() : serialNumber("null"), controllerStatus("null"), controllerTemperatureC(0) {}

std::string RaidControllerInfo::getSerialNumber() const {
    return serialNumber;
}

void RaidControllerInfo::setSerialNumber(const std::string& serial) {
    serialNumber = serial;
}

std::string RaidControllerInfo::getControllerStatus() const {
    return controllerStatus;
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
