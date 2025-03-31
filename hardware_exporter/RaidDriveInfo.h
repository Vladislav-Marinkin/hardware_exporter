#pragma once

#ifndef RAIDDRIVEINFO_H
#define RAIDDRIVEINFO_H

#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>

class RaidDriveInfo {
private:
    std::string bay;
    std::string status;
    std::string size;
    std::string serialNumber;
    std::string wwid;
    std::string model;
    int temperature;

    static std::string normalizeSpaces(const std::string& input);

public:
    // Геттеры
    std::string getBay() const;
    std::string getStatus() const;
    std::string getSize() const;
    std::string getSerialNumber() const;
    std::string getWwid() const;
    std::string getModel() const;
    int getTemperature() const;

    // Сеттеры
    void setBay(const std::string& newBay);
    void setStatus(const std::string& newStatus);
    void setSize(const std::string& newSize);
    void setSerialNumber(const std::string& newSerialNumber);
    void setWwid(const std::string& newWwid);
    void setModel(const std::string& newModel);
    void setTemperature(int newTemperature);
};

#endif // RAIDDRIVEINFO_H