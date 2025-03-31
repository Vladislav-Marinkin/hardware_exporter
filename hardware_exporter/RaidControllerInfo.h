#pragma once

#ifndef RAIDCONTROLLERINFO_H
#define RAIDCONTROLLERINFO_H

#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>

class RaidControllerInfo
{
private:
    std::string serialNumber;
    std::string controllerStatus;
    int controllerTemperatureC = 0;

    static std::string normalizeSpaces(const std::string& input);

public:
    RaidControllerInfo();

    std::string getSerialNumber() const;
    void setSerialNumber(const std::string& serial);

    std::string getControllerStatus() const;
    void setControllerStatus(const std::string& status);

    int getControllerTemperatureC() const;
    void setControllerTemperatureC(int temperature);
};

#endif // RAIDCONTROLLERINFO_H
