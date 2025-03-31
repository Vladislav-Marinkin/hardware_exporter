#include "HttpServer.h"

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

        HttpServer server(ip, port);
        server.start();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
