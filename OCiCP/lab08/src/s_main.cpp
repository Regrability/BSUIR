#include "server.h"


int main(int argc, char* argv[]) {
  if (argc != 2) {
    cout << "Welcome to the educational server 'myserver'. myserver started on port 8080." << endl;
    cout << "If you want to start the server on a different port, run: ./server <port_number>" << endl;
  } else {
    cout << "Welcome to the educational server 'myserver'." << endl;
  }
  int port = 8080;

  if (argc == 2) {
    port = stoi(argv[1]);
  }


  MyServer server(port);

  int opt = 1;
  if (setsockopt(server.getServerFD(), SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
    cerr << "Error setting socket options" << endl;
    exit(EXIT_FAILURE);
  }


  thread inputThread([&server]() {
    string line;
    while (getline(cin, line)) {
      if (line == "quit") {
        server.shutdown();
        break;
      } else {
        cout << "Unknown command: " << line << endl;
      }
    }
  });


  server.run();
  inputThread.join();


  cout << "Server stopped." << endl;


  return 0;

}
