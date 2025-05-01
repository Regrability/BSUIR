#include "server.h"
#include <filesystem>
#include <unistd.h>

using namespace std;

MyServer::MyServer(int port) {
  serverFD = socket(AF_INET, SOCK_STREAM, 0);
  if (serverFD == -1) {
    lock_guard<mutex> lock(coutMutex);
    cerr << "Socket creation failed" << endl;
    exit(EXIT_FAILURE);
  }

  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(port);
  serverAddr.sin_addr.s_addr = INADDR_ANY;

  if (bind(serverFD, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {
    lock_guard<mutex> lock(coutMutex);
    cerr << "Socket binding failed" << endl;
    exit(EXIT_FAILURE);
  }

  if (listen(serverFD, 5) == -1) {
    lock_guard<mutex> lock(coutMutex);
    cerr << "Listening on socket failed" << endl;
    exit(EXIT_FAILURE);
  }

  cout << "Server initialized and ready." << endl;
}

void MyServer::run() {
  if (fcntl(serverFD, F_SETFL, O_NONBLOCK) < 0) {
    lock_guard<mutex> lock(coutMutex);
    cerr << "Setting non-blocking mode failed" << endl;
    exit(EXIT_FAILURE);
  }

  while (running) {
    int clientFD = accept(serverFD, NULL, NULL);
    if (clientFD == -1) {
      if (errno == EWOULDBLOCK || errno == EAGAIN) {
        usleep(1000);
        continue;
      } else {
        lock_guard<mutex> lock(coutMutex);
        cerr << "Accepting connection failed" << endl;
        exit(EXIT_FAILURE);
      }
    }

    {
      lock_guard<mutex> lock(coutMutex);
      cout << currentTime() << " Client connected" << endl;
    }

    thread clientThread(
        [this](int clientFD) {
          this->handleClient(clientFD);
        },
        clientFD);
    lock_guard<mutex> lock(clientHandlersMutex);
    clientHandlers.push_back(move(clientThread));
  }
}

void MyServer::handleClient(int clientFD) {
  bool clientRunning = true;
  while (clientRunning) {
    string msg = recvFromClient(clientFD);
    if (msg.empty()) {
      break;
    }
    processMessage(msg, clientFD, &clientRunning);
  }
}

void MyServer::processMessage(string &msg, int clientFD, bool *clientRunning) {
  string response;
  if (msg.substr(0, 4) == "ECHO") {
    response = msg.substr(5);
  } else if (msg.substr(0, 4) == "QUIT") {
    lock_guard<mutex> lock(coutMutex);
    cout << currentTime() << " Client disconnected" << endl;
    *clientRunning = false;
    close(clientFD);
    return;
  } else if (msg.substr(0, 4) == "INFO") {
    response = readFileContent("/home/rlinux/Kocherov/ОСиСП/LAB08/src/serverInfo.txt");
  } else if (msg.substr(0, 2) == "CD") {
    switchDirectory(msg.substr(3), clientFD);
    return;
  } else if (msg.substr(0, 4) == "LIST") {
    response = listDir(".", "");
  } else if (msg[0] == '@') {
    handleFileOps(msg.substr(1), clientFD, clientRunning);
    return;
  } else {
    response = "Unknown command";
  }
  sendToClient(clientFD, response);
}

string MyServer::listDir(const string &path, const string &prefix) {
  string result;
  for (const auto &entry : filesystem::directory_iterator(path)) {
    if (entry.is_directory()) {
      result += prefix + entry.path().filename().string() + "/\n";
    } else if (entry.is_symlink()) {
      auto target = filesystem::read_symlink(entry.path());
      result += prefix + entry.path().filename().string() + " --> ";
      if (filesystem::is_regular_file(target)) {
        result += " " + target.filename().string() + "\n";
      } else if (filesystem::is_symlink(target)) {
        result += "> " + target.filename().string() + "\n";
      }
    } else if (entry.is_regular_file()) {
      result += prefix + entry.path().filename().string() + "\n";
    }
  }
  return result;
}

void MyServer::handleFileOps(const string &filename, int clientFD, bool *clientRunning) {
  ifstream file(filename);
  if (!file.is_open()) {
    string response = "File opening error";
    sendToClient(clientFD, response);
  } else {
    string line;
    while (getline(file, line)) {
      processMessage(line, clientFD, clientRunning);
      if (!*clientRunning) {
        break;
      }
    }
  }
}

string MyServer::readFileContent(const string &filePath) {
  lock_guard<mutex> lock(fileMutex);
  ifstream file(filePath);
  if (!file.is_open()) {
    return "File opening error";
  }
  stringstream buffer;
  buffer << file.rdbuf();
  file.close();
  return buffer.str();
}

void MyServer::switchDirectory(const string &path, int clientFD) {
  string response;
  filesystem::path rootPath = "/home/rlinux/Kocherov/ОСиСП/LAB08/";

  if (path.empty()) {
    response = "Invalid path";
  } else {
    filesystem::path fsPath(path);
    if (!filesystem::exists(fsPath) || !filesystem::is_directory(fsPath)) {
      response = "Not a directory";
    } else {
      filesystem::path relativePath = filesystem::relative(fsPath, rootPath);

      if (relativePath.string().find("..") != string::npos) {
        response = "Cannot change directory outside the root";
      } else {
        error_code ec;
        filesystem::current_path(fsPath, ec);
        if (ec) {
          response = "Directory change error";
        } else {
          response = "Directory changed";
        }
      }
    }
  }
  sendToClient(clientFD, response);
}

string MyServer::currentTime() const {
  auto now = chrono::system_clock::now();
  auto now_c = chrono::system_clock::to_time_t(now);
  char buffer[100];
  strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&now_c));
  return string(buffer);
}

void MyServer::sendToClient(int clientFD, const string &msg) {
  uint32_t msgSize = htonl(msg.size());
  if (write(clientFD, &msgSize, sizeof(msgSize)) == -1) {
    lock_guard<mutex> lock(coutMutex);
    cerr << "Sending response size error" << endl;
    return;
  }

  if (write(clientFD, msg.c_str(), msg.size()) == -1) {
    lock_guard<mutex> lock(coutMutex);
    cerr << "Sending response error" << endl;
  }
}

string MyServer::recvFromClient(int clientFD) {
  uint32_t msgSize;
  if (read(clientFD, &msgSize, sizeof(msgSize)) == -1) {
    lock_guard<mutex> lock(coutMutex);
    cerr << "Reading command size error" << endl;
    return "";
  }
  msgSize = ntohl(msgSize);

  char *buffer = new char[msgSize + 1];
  int bytesRead = read(clientFD, buffer, msgSize);
  if (bytesRead == -1) {
    lock_guard<mutex> lock(coutMutex);
    cerr << "Reading command error" << endl;
    delete[] buffer;
    return "";
  }
  buffer[msgSize] = '\0';

  string msg(buffer, msgSize);
  delete[] buffer;

  return msg;
}

MyServer::~MyServer() {

  lock_guard<mutex> lock(clientHandlersMutex);
  for (auto &thread : clientHandlers) {
    if (thread.joinable()) {
      thread.join();
    }
  }
  close(serverFD);
}
