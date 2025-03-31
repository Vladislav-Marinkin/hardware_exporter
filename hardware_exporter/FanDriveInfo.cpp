#include "FanDriveInfo.h"

const std::string& FanDriveInfo::getName() const 
{
    return name;
}

const std::string& FanDriveInfo::getStatus() const 
{
    return status;
}

const std::string& FanDriveInfo::getRpm() const 
{
    return rpm;
}

float FanDriveInfo::getTemperatureC() const 
{
    return temperatureC;
}

void FanDriveInfo::setName(const std::string& name)
{
    this->name = name;
}

void FanDriveInfo::setStatus(const std::string& status)
{
    this->status = status;
}

void FanDriveInfo::setRpm(const std::string& rpm)
{
    this->rpm = rpm;
}

void FanDriveInfo::setTemperatureC(float temperatureC)
{
    this->temperatureC = temperatureC;
}
