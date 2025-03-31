#pragma once
#include "CommandExecutor.h"

//#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <map>

//using json = nlohmann::json;

class ControllerParser {
public:
    ControllerParser(const std::string& configFilePath);
    void parseData(const std::string& controllerType, const std::string& output);

private:
    //json config;

    //void parseRegexs(const json& regexs, const std::string& output);

};

