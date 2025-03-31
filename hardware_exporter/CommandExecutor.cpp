#include "CommandExecutor.h"

std::string CommandExecutor::runCommand(const std::string& command)
{
    std::array<char, 128> buffer;
    std::string result;

    // ���������� stderr � stdout
    std::string fullCommand = command + " 2>&1";

    FILE* pipe = popen(fullCommand.c_str(), "r");
    if (!pipe) {
        throw std::runtime_error("Error executing the command");
    }

    // ������ ����������� �����
    while (fgets(buffer.data(), buffer.size(), pipe) != nullptr) {
        result += buffer.data();
    }

    int returnCode = pclose(pipe);

    // �������� ���� �������� (�� �������)
    if (returnCode != 0) {
        throw std::runtime_error("Command failed (code " + std::to_string(returnCode) + "): " + result);
    }

    return result;
}

std::string CommandExecutor::runCommandWithSudo(const std::string& command)
{
    std::string sudoCommand = "sudo " + command;
    return runCommand(sudoCommand);
}
