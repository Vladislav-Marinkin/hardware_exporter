#include "ControllerParser.h"

ControllerParser::ControllerParser(const std::string& configFilePath)
{
    std::ifstream file(configFilePath);

    if (file.is_open()) {
        //file >> config;
    }
    else {
        std::cerr << "Failed to load config file!" << std::endl;
    }
}

void ControllerParser::parseData(const std::string& controllerType, const std::string& output)
{

}

//void ControllerParser::parseRegexs(const json& regexs, const std::string& output)
//{
//
//}
