#include <algorithm>
#include <atomic>
#include <chrono>
#include <cstring>
#include <ctime>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <mutex>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <thread>
#include <unistd.h>
#include <unordered_map>
#include <vector>


using namespace std;

class MyServer {
  int serverFD;
  struct sockaddr_in serverAddr;
  vector<thread> clientHandlers;
  atomic<bool> running;
  mutex coutMutex;
  mutex fileMutex;
  mutex clientHandlersMutex;

public:

  MyServer(int port);
  void run();
  void handleClient(int clientFD);
  void processMessage(string &msg, int clientFD, bool *clientRunning);
  string readFileContent(const string &filePath);
  void switchDirectory(const string &path, int clientFD);
  int getServerFD() const { return serverFD; }
  string currentTime() const;
  void shutdown() { running = false; }
  string listDir(const string &path, const string &prefix);
  void sendToClient(int clientFD, const string &msg);
  string recvFromClient(int clientFD);
  void handleFileOps(const string &cmd, int clientFD, bool *clientRunning);
  ~MyServer();
};
