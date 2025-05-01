#include "tools.h"

int process_count() {
    int process_count = 0; // Счетчик процессов
    DIR* proc_dir = opendir("/proc");
    if (proc_dir != NULL) {
        struct dirent* entry;


        while ((entry = readdir(proc_dir)) != NULL) {
            // Проверяем, является ли элемент каталогом
            struct stat file_stat;
            char file_path[256];
            strncpy(file_path, "/proc/", sizeof(file_path));
            strncat(file_path, entry->d_name, sizeof(file_path) - strlen(file_path) - 1);

            if (stat(file_path, &file_stat) == 0 && S_ISDIR(file_stat.st_mode)) {
                // Проверяем, является ли имя каталога числом (идентификатором процесса)
                int pid = atoi(entry->d_name);
                if (pid != 0) {
                    process_count++; // Увеличиваем счетчик процессов
                }
            }
        }

        closedir(proc_dir);
    } else {
        printf("Failed to open /proc directory.\n");
    }
    return process_count;
}

float covert_bytes_to_gigabytes(float n)
{
    return (n / 1024.0 / 1024.0 / 1024.0);
}

void read_sysfs_file(const char *path, char **buffer) {
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", path);
        return;
    }

    *buffer = (char *)malloc(50 * sizeof(char));
    if (*buffer == NULL) {
        printf("Error allocating memory.\n");
        fclose(file);
        return;
    }

    fgets(*buffer, 50, file);

    fclose(file);
}

void do_ramka(int start, int end, char* title)
{
    int i;
    char choice = 'a';

    for (i = START_ROW; i < LENGTH_ROW; i++) {mvprintw(start, i, "-");}
    mvprintw(start, CENTER, "%s", title);
    for (i = START_ROW; i < LENGTH_ROW; i++) {mvprintw(start + 1, i, "-");}
    for (i = START_ROW; i < LENGTH_ROW; i++) {mvprintw(end, i, "-");}
    for (i = start + 2; i < end; i++) {mvprintw(i, START_ROW, "|");}
    for (i = start + 2; i < end; i++) {mvprintw(i, LENGTH_ROW - 1, "|");}

    attroff(COLOR_PAIR(GREEN_COLOR));
    attron(COLOR_PAIR(BLUE_COLOR));
    mvprintw(end+1, LEFT_CENTER, "Enter 'q' to exit modul");
    attroff(COLOR_PAIR(BLUE_COLOR));
    attron(COLOR_PAIR(GREEN_COLOR));

    while(choice != 'q')
        {choice = getch();} // Ввод символа с клавиатуры}

}
