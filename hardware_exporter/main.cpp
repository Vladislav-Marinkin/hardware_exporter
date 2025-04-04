﻿#ifdef NDEBUG
#include "HttpServer.h"
#else
#include "HttpServer.h"
#include "parser.h"
#endif

int main(int argc, char* argv[]) {
    int opt;
    std::string ip = "0.0.0.0";
    int port = 8080;

    try {
        while ((opt = getopt(argc, argv, "i:p:")) != -1) {
            switch ((char)opt) {
            case 'i':
                ip = optarg;
                break;
            case 'p':
                port = std::stoi(optarg);
                break;
            default:
                std::cerr << "Usage: " << argv[0] << " -i <IP> -p <PORT>\n";
                exit(EXIT_FAILURE);
            }
        }
#ifdef NDEBUG
        HttpServer server(ip, port);
        server.start();
#else
        HttpServer server(ip, port);
        server.start();

        //parser parser;

        //parser.run();
#endif
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
