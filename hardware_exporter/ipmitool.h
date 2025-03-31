#pragma once

#ifndef IPMITOOL_H
#define IPMITOOL_H

#include "testData.h"
#include "FanDriveInfo.h"
#include "CommandExecutor.h"

#include <string>
#include <array>
#include <stdexcept>
#include <regex>
#include <iostream>

class ipmitool : private CommandExecutor
{
private:
    std::vector<FanDriveInfo> fanDrivesInfo;

    void parseFanDrive(const std::string input);

public:
    void run();

    std::vector<FanDriveInfo> getFanDrivesInfo();
};

#endif // IPMITOOL_H