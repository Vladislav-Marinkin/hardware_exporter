#pragma once
#include "CommandExecutor.h"
#include "FanDriveInfo.h"
#include "RaidDriveInfo.h"
#include "RaidControllerInfo.h"

#include "testData.h"

#include <string>
#include <array>
#include <stdexcept>
#include <regex>
#include <iostream>

using string = std::string;
using string_vector = std::vector<string>;
using RaidDriveVector = std::vector<RaidDriveInfo>;
using FanDriveVector = std::vector<FanDriveInfo>;

class parser : private CommandExecutor
{
public:
	template <typename T>
	void run(string_vector& regex, string_vector& commands, T& data);

private:
	template <typename T>
	void parse(string& output, string_vector& regex, T& data);
};
