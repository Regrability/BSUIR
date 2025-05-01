CXX = g++
CXXFLAGS = -W -Wall -Wno-unused-parameter -Wno-unused-variable -std=c++17
BUILD_DIR = build/debug
RELEASE_DIR = build/release
SRC_DIR = src

all: server client

server: $(BUILD_DIR)/s_main.o $(BUILD_DIR)/server.o
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/server $(BUILD_DIR)/s_main.o $(BUILD_DIR)/server.o

client: $(BUILD_DIR)/c_main.o $(BUILD_DIR)/client.o
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/client $(BUILD_DIR)/c_main.o $(BUILD_DIR)/client.o

release: CXXFLAGS += -O2
release: BUILD_DIR = $(RELEASE_DIR)
release: server client

$(BUILD_DIR)/s_main.o: $(SRC_DIR)/s_main.cpp $(SRC_DIR)/server.h | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/s_main.cpp -o $(BUILD_DIR)/s_main.o

$(BUILD_DIR)/c_main.o: $(SRC_DIR)/c_main.cpp $(SRC_DIR)/client.h | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/c_main.cpp -o $(BUILD_DIR)/c_main.o

$(BUILD_DIR)/server.o: $(SRC_DIR)/server.cpp $(SRC_DIR)/server.h | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/server.cpp -o $(BUILD_DIR)/server.o

$(BUILD_DIR)/client.o: $(SRC_DIR)/client.cpp $(SRC_DIR)/client.h | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/client.cpp -o $(BUILD_DIR)/client.o

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)/*.o $(BUILD_DIR)/server $(BUILD_DIR)/client $(RELEASE_DIR)/*.o $(RELEASE_DIR)/server $(RELEASE_DIR)/client
