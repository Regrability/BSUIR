#define _GNU_SOURCE
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdbool.h>

const char *get_file_type(const char *path);
void list_directory(const char *name, ssize_t include_links, ssize_t include_files, ssize_t include_dirs, bool is_first_call);

int main(int argc, char *argv[]) {
    const char *dir_path = "./";  // Путь по умолчанию - текущая директория
    ssize_t option;
    int include_links = 0, include_dirs = 0, include_files = 0;
    int dir_path_index = 2;
    bool is_first_call = true;

    while ((option = getopt(argc, argv, "ldf")) != -1) {
        switch (option) {
        case 'l':
            include_links = 1;
            break;
        case 'd':
            include_dirs = 1;
            break;
        case 'f':
            include_files = 1;
            break;
        default:
            fprintf(stderr, "Использование: %s [директория] [-l] [-d] [-f]\n", argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    dir_path_index = optind;
    if (dir_path_index < argc) {
        dir_path = argv[dir_path_index];
    }

    if (!(include_links || include_dirs || include_files)) {
        include_links = include_dirs = include_files = 1;
    }

    list_directory(dir_path, include_files, include_dirs, include_links, is_first_call);
    return 0;
}

const char *get_file_type(const char *path) {
    struct stat sb;
    if (lstat(path, &sb) == -1) {
        perror("lstat");
        return "Не удалось получить информацию о файле";
    }
    switch (sb.st_mode & S_IFMT) {
        case S_IFDIR:
            return "Директория";
        case S_IFLNK:
            return "Символическая ссылка";
        case S_IFREG:
            return "Обычный файл";
        default:
            return "Неизвестный тип файла";
    }
}

void list_directory(const char *name, ssize_t include_files, ssize_t include_dirs, ssize_t include_links, bool is_first_call) {
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(name)))
        return;

    if (is_first_call && include_dirs == 1) {
        printf("Содержимое директории: %s\n", name);
        is_first_call = false;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
            char path[1024];
            snprintf(path, sizeof(path), "%s/%s", name, entry->d_name);
            if (include_dirs) {
                const char *file_type = get_file_type(path);
                printf("%s: %s\n", path, file_type);
            }
            list_directory(path, include_files, include_dirs, include_links, is_first_call);
        } else {
            char path[1024];
            snprintf(path, sizeof(path), "%s/%s", name, entry->d_name);
            const char *file_type = get_file_type(path);
            if ((include_links && (entry->d_type == DT_LNK)) ||
                (include_dirs && (entry->d_type == DT_DIR)) ||
                (include_files && (entry->d_type == DT_REG)) ||
                (!include_links && !include_dirs && !include_files))
            {
                printf("%s: %s\n", path, file_type);
            }
        }
    }

    closedir(dir);
}
