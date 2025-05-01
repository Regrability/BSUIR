CC = gcc
CFLAGS = -Wall -Wextra -pthread -lrt -std=c11
SRC_DIR = src
BUILD_DIR = build

all: $(BUILD_DIR)/main

$(BUILD_DIR)/main: $(SRC_DIR)/main.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $(SRC_DIR)/main.c

run: $(BUILD_DIR)/main
	$<

clean:
	rm -rf $(BUILD_DIR)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
