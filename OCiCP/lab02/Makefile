CC = gcc
CFLAGS = -W -Wall -Wextra -std=c11 -Wno-unused-parameter
SRC_DIR = ./src
BUILD_DIR = ./build/debug

.PHONY: all clean

all: parent child

parent: $(BUILD_DIR)/parent

child: $(BUILD_DIR)/child

$(BUILD_DIR)/parent: $(SRC_DIR)/parent.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@

$(BUILD_DIR)/child: $(SRC_DIR)/child.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(BUILD_DIR)/parent $(BUILD_DIR)/child

$(BUILD_DIR):
	mkdir -p $@
