CC = gcc
CFLAGS_DEBUG = -std=c11 -g2 -ggdb -W -Wall -Wextra
CFLAGS_RELEASE = -std=c11 -W -Wall -Wextra -Werror
.SUFFIXES:
.SUFFIXES: .c .o

DEBUG = ./build/debug
RELEASE = ./build/release
OUT_DIR = $(DEBUG)

vpath %.c src
vpath %.h src
vpath %.o $(OUT_DIR)

ifeq ($(MODE), release)
    CFLAGS = $(CFLAGS_RELEASE)
    OUT_DIR = $(RELEASE)
    vpath %.o $(RELEASE)
else
    CFLAGS = $(CFLAGS_DEBUG)
endif

objects = $(OUT_DIR)/main.o
prog = $(OUT_DIR)/test

all: $(prog)

$(prog): $(objects)
	$(CC) $(CFLAGS) $^ -o $@

$(OUT_DIR)/%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY: clean

clean:
	@rm -rf $(DEBUG)/* $(RELEASE)/* test
