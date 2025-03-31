#pragma once

#include "controllerTypeParser.h"
#include "ipmitool.h"
#include "adaptec.h"
#include "ssacli.h"
#include "lsi.h"

#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <vector>

#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H

class HttpServer
{
public:
    HttpServer(const std::string& ip, int port);
    void start();

private:
    std::string controllerType;

    ipmitool _ipmitool;
    adaptec _adaptec;
    ssacli _ssacli;
    lsi _lsi;

    std::string ip_;
    int port_;
    int server_fd, new_socket;
    void handle_request(int client_socket);
    void send_metrics(int client_socket);
    std::string generateRaidMetrics(RaidControllerInfo controllerInfo, std::vector<RaidDriveInfo> drivesInfo, std::string controllerType);
    std::string generateFanMetrics(std::vector<FanDriveInfo> fanInfoList);
    std::string to_uppercase(const std::string& str);
};

#endif // HTTP_SERVER_H