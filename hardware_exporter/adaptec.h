#pragma once

#ifndef ADAPTEC_H
#define ADAPTEC_H

#include "testData.h"
#include "RaidDriveInfo.h"
#include "CommandExecutor.h"
#include "RaidControllerInfo.h"

#include <string>
#include <array>
#include <stdexcept>
#include <regex>
#include <iostream>

class adaptec : private CommandExecutor
{
private:
    RaidControllerInfo controllerInfo;
    std::vector<RaidDriveInfo> drivesInfo;

    void parseControllerData(const std::string input);
    void parseDriveData(const std::string input);
public:
    void run();

    RaidControllerInfo getControllerInfo();
    std::vector<RaidDriveInfo> getDrivesInfo();
};

#endif // ADAPTEC_H