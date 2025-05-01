TARGET = SysInfo
CC = gcc
CFLAGS = -W -Wall -Wextra -std=c11 -lncurses -I/usr/include/X11
LDFLAGS = -lX11
.PHONY: clean

PREF_SRC = ./src/
PREF_OBJ = ./build/debug/

SRC = $(wildcard $(PREF_SRC)*.c)
OBJ = $(patsubst $(PREF_SRC)%.c, $(PREF_OBJ)%.o, $(SRC))

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) -o $(TARGET)

$(PREF_OBJ)%.o: $(PREF_SRC)%.c
	$(CC) $(CFLAGS) -D_GNU_SOURCE -c $< -o $@

clean:
	rm -f $(TARGET) $(PREF_OBJ)*.o
