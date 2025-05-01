#include "client.h"

Client::Client(const std::string &ip, int port) {
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0) {
        std::cerr << "Socket creation failed" << std::endl;
        exit(EXIT_FAILURE);
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip.c_str(), &serverAddr.sin_addr) <= 0) {
        std::cerr << "Invalid address" << std::endl;
        exit(EXIT_FAILURE);
    }

    if (connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Connection failed" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Client::run() {
    while (true) {
        std::string command = getUserInput();
        sendToServer(command);
        std::string response = receiveFromServer();
        std::cout << response << std::endl;
    }
}

std::string Client::getUserInput() {
    std::cout << "> ";
    std::string input;
    std::getline(std::cin, input);
    return input;
}

void Client::sendToServer(const std::string &msg) {
    uint32_t msgSize = htonl(msg.size());
    if (write(clientSocket, &msgSize, sizeof(msgSize)) < 0) {
        std::cerr << "Failed to send message size" << std::endl;
        close(clientSocket);
        exit(EXIT_FAILURE);
    }

    if (write(clientSocket, msg.c_str(), msg.size()) < 0) {
        std::cerr << "Failed to send message" << std::endl;
        close(clientSocket);
        exit(EXIT_FAILURE);
    }
}

std::string Client::receiveFromServer() {
    uint32_t size;
    if (read(clientSocket, &size, sizeof(size)) < 0) {
        std::cerr << "Failed to receive message size" << std::endl;
        close(clientSocket);
        exit(EXIT_FAILURE);
    }
    size = ntohl(size);

    char *buffer = new char[size + 1];
    if (read(clientSocket, buffer, size) <= 0) {
        std::cerr << "Server closed connection" << std::endl;
        delete[] buffer;
        close(clientSocket);
        exit(EXIT_FAILURE);
    }
    buffer[size] = '\0';

    std::string response(buffer);
    delete[] buffer;
    return response;
}

Client::~Client() {
    close(clientSocket);
}
