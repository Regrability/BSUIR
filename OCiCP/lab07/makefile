# Определение компилятора и флагов
CC = gcc
CFLAGS = -Wall -Wextra -pthread -lrt -std=c11

# Каталоги
SRC_DIR = src
BUILD_DIR = build

# Список исходных файлов
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

# Соответствующие объектные файлы в каталоге build
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_FILES))

# Исполняемые файлы
EXECUTABLES = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%, $(SRC_FILES))

# Правило по умолчанию
all: $(EXECUTABLES)

# Правило для сборки исполняемых файлов
$(BUILD_DIR)/%: $(BUILD_DIR)/%.o | $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@

# Правило для сборки объектных файлов
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Создание каталога build, если его нет
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Очистка
clean:
	rm -rf $(BUILD_DIR)/*
	rm -f *.bin

# Файлы для которых не нужно создавать правила
.PHONY: all clean
