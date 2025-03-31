#pragma once

#ifndef FANDRIVEINFO_H
#define FANDRIVEINFO_H

#include <string>

class FanDriveInfo
{
private:
	std::string name;
	std::string status;
	std::string rpm;
	float temperatureC = 0;

public:
    // Геттеры
    const std::string& getName() const;
    const std::string& getStatus() const;
    const std::string& getRpm() const;
    float getTemperatureC() const;

    // Сеттеры
    void setName(const std::string& name);
    void setStatus(const std::string& status);
    void setRpm(const std::string& rpm);
    void setTemperatureC(float temperatureC);
};

#endif // FANDRIVEINFO_H