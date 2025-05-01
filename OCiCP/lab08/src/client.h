
#include <arpa/inet.h>
#include <iostream>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>

class Client {
private:
    int clientSocket;
    struct sockaddr_in serverAddr;

public:
    Client(const std::string &ip, int port);
    void run();
    std::string getUserInput();
    void sendToServer(const std::string &msg);
    std::string receiveFromServer();
    ~Client();
};


