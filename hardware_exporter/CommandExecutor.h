#pragma once
#include <array>
#include <string>
#include <stdexcept>

class CommandExecutor
{
public:
	static std::string runCommand(const std::string& command);
	static std::string runCommandWithSudo(const std::string& command);
};

