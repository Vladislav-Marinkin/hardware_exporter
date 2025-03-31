#pragma once

#ifndef SSACLI_H
#define SSACLI_H

#include "testData.h"
#include "RaidDriveInfo.h"
#include "CommandExecutor.h"
#include "RaidControllerInfo.h"

#include <string>
#include <array>
#include <stdexcept>
#include <regex>
#include <iostream>

class ssacli : private CommandExecutor {
private:
    RaidControllerInfo controllerInfo;
    std::vector<RaidDriveInfo> drivesInfo;

    void parseControllerData(const std::string input);
    std::vector<std::string> splitDrives(const std::string& input);
    void parseDriveData(const std::string input);
public:
    void run();

    RaidControllerInfo getControllerInfo();
    std::vector<RaidDriveInfo> getDrivesInfo();
};

#endif // SSACLI_H
