#include "CommandExecutor.h"

std::string CommandExecutor::runCommand(const std::string& command)
{
    std::array<char, 128> buffer;
    std::string errorOutput;
    std::string result;

    // ��������� ����� ��� ���������� �������
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) {
        throw std::runtime_error("Error executing the command");
    }

    // ������ ����� ������� � ��������� ��� � ���������
    while (fgets(buffer.data(), buffer.size(), pipe) != nullptr) {
        result += buffer.data();
    }

    // ������ ������ �� stderr, ���� ��� ����
    FILE* errorPipe = popen((command + " 2>&1").c_str(), "r");
    if (errorPipe) {
        while (fgets(buffer.data(), buffer.size(), errorPipe) != nullptr) {
            errorOutput += buffer.data();
        }
        fclose(errorPipe);
    }

    // ���� � stderr ���� ������, ����������� ����������
    if (!errorOutput.empty()) {
        throw std::runtime_error("Error executing the command: " + errorOutput);
    }

    // ��������� ����
    fclose(pipe);

    return result;
}

std::string CommandExecutor::runCommandWithSudo(const std::string& command)
{
    std::string sudoCommand = "sudo " + command;
    return runCommand(sudoCommand);
}
