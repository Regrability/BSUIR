#ifndef TOOLS_H_
#define TOOLS_H_

#include <ncurses.h> // Заголовочный файл для работы с ncurses - библиотекой для управления текстовым окном в терминале
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <dirent.h> // Заголовочный файл для работы с каталогами и файлами в них
#include <unistd.h> // Заголовочный файл для работы с POSIX API, такими как системные вызовы, форкинг процессов и т.д.
#include <pwd.h> // Заголовочный файл для работы с информацией о пользователях
#include <fcntl.h> // Заголовочный файл для работы с файловыми дескрипторами
#include <ifaddrs.h> // Заголовочный файл для получения списка сетевых интерфейсов
#include <netdb.h> // Заголовочный файл для работы с сетевыми функциями и структурами данных

#include <sys/socket.h> // Заголовочный файл для работы с сокетами
#include <net/if.h> // Заголовочный файл для работы с сетевыми интерфейсами
#include <sys/utsname.h> // Заголовочный файл для получения информации о системе
#include <sys/stat.h> // Заголовочный файл для работы со структурой stat, которая содержит информацию о файле
#include <sys/sysinfo.h> // Заголовочный файл для получения информации о системе
#include <sys/statvfs.h> // Заголовочный файл для получения информации о файловой системе
#include <sys/types.h> // Заголовочный файл для определения системных типов данных
#include <sys/ioctl.h> // Заголовочный файл для работы с вводом/выводом
#include <linux/rtc.h> // Заголовочный файл для работы с часами реального времени
#include <X11/Xlib.h> // Заголовочный файл для работы с X Window System


#define LENGTH_ROW 155
#define CENTER 80
#define LEFT_CENTER 70
#define RIGHT_CENTER 100
#define START_ROW 25
#define GREEN_COLOR 1
#define RED_COLOR 2
#define BLUE_COLOR 3


int process_count();
float covert_bytes_to_gigabytes(float n);
void read_sysfs_file(const char *path, char **buffer);
void do_ramka();


#endif
