#include "client.h"
#include <csignal>
#include <iostream>
#include <cstdlib>

Client *clientPtr;

void handleSignal(int signum) {
    delete clientPtr;
    exit(signum);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <server_ip> <port>" << std::endl;
        return 1;
    }

    std::string ip = argv[1];
    int port = std::stoi(argv[2]);

    clientPtr = new Client(ip, port);
    std::signal(SIGINT, handleSignal);
    clientPtr->run();

    return 0;
}
