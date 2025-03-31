#pragma once
#include "CommandExecutor.h"

#include <iostream>
#include <regex>

class controllerTypeParser : private CommandExecutor
{
private:
	std::string parseControllerType(const std::string input);
public:
	std::string getControllerType();
};

