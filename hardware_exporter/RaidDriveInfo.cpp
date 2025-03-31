#include "RaidDriveInfo.h"

std::string RaidDriveInfo::normalizeSpaces(const std::string& input)
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

std::string RaidDriveInfo::getBay() const {
    return bay;
}

std::string RaidDriveInfo::getStatus() const {
    return status;
}

std::string RaidDriveInfo::getSize() const {
    return normalizeSpaces(size);
}

std::string RaidDriveInfo::getSerialNumber() const {
    return normalizeSpaces(serialNumber);
}

std::string RaidDriveInfo::getWwid() const {
    return wwid;
}

std::string RaidDriveInfo::getModel() const {
    return normalizeSpaces(model);
}

int RaidDriveInfo::getTemperature() const {
    return temperature;
}

void RaidDriveInfo::setBay(const std::string& newBay) {
    bay = newBay;
}

void RaidDriveInfo::setStatus(const std::string& newStatus) {
    status = newStatus;
}

void RaidDriveInfo::setSize(const std::string& newSize) {
    size = newSize;
}

void RaidDriveInfo::setSerialNumber(const std::string& newSerialNumber) {
    serialNumber = newSerialNumber;
}

void RaidDriveInfo::setWwid(const std::string& newWwid) {
    wwid = newWwid;
}

void RaidDriveInfo::setModel(const std::string& newModel) {
    model = newModel;
}

void RaidDriveInfo::setTemperature(int newTemperature) {
    temperature = newTemperature;
}