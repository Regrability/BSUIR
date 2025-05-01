#include "MyPrint.h"

void shapka()
{
    clear(); // Очистка экрана
    refresh(); // Обновление экрана
    int i;
    attroff(COLOR_PAIR(GREEN_COLOR));
    attron(COLOR_PAIR(BLUE_COLOR));
    for (i = START_ROW; i < LENGTH_ROW; i++) {mvprintw(1, i, "-");}
    mvprintw(1, CENTER, "System Information");
    for (i = START_ROW; i < LENGTH_ROW; i++) {mvprintw(2, i, "-");}

    mvprintw(3, CENTER - 5, "[1] - Kernel Infomation ");
    mvprintw(4, CENTER - 5, "[2] - User Infomation ");
    mvprintw(5, CENTER - 5, "[3] - Memory && Processes Infomation ");
    mvprintw(6, CENTER - 5, "[4] - Disk Infomation ");
    mvprintw(7, CENTER - 5, "[5] - CPU Infomation ");
    mvprintw(8, CENTER - 5, "[6] - Motherboard and Bios Infomation ");
    mvprintw(9, CENTER - 5, "[7] - Real Time Clock Infomation ");
    mvprintw(10, CENTER - 5, "[8] - Display Infomation ");
    mvprintw(11, CENTER - 5, "[9] - IP Infomation ");
    mvprintw(12, CENTER - 5, "[0] - Batery Infomation ");
    mvprintw(13, CENTER - 5, "[q] - Exit programm ");

    for (i = 3; i < 14; i++) {mvprintw(i, START_ROW, "|");}
    for (i = 3; i < 14; i++) {mvprintw(i, LENGTH_ROW - 1, "|");}
    for (i = START_ROW; i < LENGTH_ROW; i++) {mvprintw(14, i, "-");}
    attroff(COLOR_PAIR(BLUE_COLOR));
    attron(COLOR_PAIR(GREEN_COLOR));

}

void print_battery_info() {

    clear(); // Очистка экрана
    refresh(); // Обновление экрана

    FILE *file;
    char buffer[128];
    int energyNow, energyFull, voltage;

    file = fopen("/sys/class/power_supply/BAT0/energy_now", "r");
    if (file == NULL) {
        printf("Failed to open file /sys/class/power_supply/BAT0/energy_now\n");
        return;
    }
    fgets(buffer, 128, file);
    energyNow = atoi(buffer);
    fclose(file);

    file = fopen("/sys/class/power_supply/BAT0/energy_full", "r");
    if (file == NULL) {
        printf("Failed to open file /sys/class/power_supply/BAT0/energy_full\n");
        return;
    }
    fgets(buffer, 128, file);
    energyFull = atoi(buffer);
    fclose(file);

    file = fopen("/sys/class/power_supply/BAT0/voltage_now", "r");
    if (file == NULL) {
        printf("Failed to open file /sys/class/power_supply/BAT0/voltage_now\n");
        return;
    }
    fgets(buffer, 128, file);
    voltage = atoi(buffer);
    fclose(file);

    float chargeLevel = ((float)energyNow / energyFull) * 100;


    mvprintw(3, LEFT_CENTER, "Current battery charge:");
    attron(A_BOLD);
    mvprintw(3, RIGHT_CENTER, "%.2f%%\n", chargeLevel);  // Вывод текущего заряда аккумулятора в процентах
    attroff(A_BOLD);

    mvprintw(4, LEFT_CENTER, "Maximum battery charge: ");
    attron(A_BOLD);
    mvprintw(4, RIGHT_CENTER, "%d mWh\n", energyFull); // Вывод максимального заряда аккумулятора в милливатт-часах
    attroff(A_BOLD);

    mvprintw(5, LEFT_CENTER, "Current battery voltage: ");
    attron(A_BOLD);
    mvprintw(5, RIGHT_CENTER, "%d mV\n", voltage); // Вывод текущего напряжения аккумулятора в милливольтах
    attroff(A_BOLD);

    do_ramka(1, 6, "Battery Information");

}

void print_kernel_info() {

    clear(); // Очистка экрана
    refresh(); // Обновление экрана

    struct utsname system_info;//структура, которая содержит информацию о системе
    uname(&system_info);//используется для получения информации о системе и заполняет переданную ей структуру

    mvprintw(3, LEFT_CENTER, "System: ");
    attron(A_BOLD);
    mvprintw(3, RIGHT_CENTER, "%s", system_info.sysname);
    attroff(A_BOLD);

    mvprintw(4, LEFT_CENTER, "Node: ");
    attron(A_BOLD);
    mvprintw(4, RIGHT_CENTER, "%s", system_info.nodename);//дистрибутив
    attroff(A_BOLD);

    mvprintw(5, LEFT_CENTER, "Release: ");
    attron(A_BOLD);
    mvprintw(5, RIGHT_CENTER, "%s", system_info.release);//версия ядра
    attroff(A_BOLD);

    mvprintw(6, LEFT_CENTER, "Version: ");
    attron(A_BOLD);
    mvprintw(6, RIGHT_CENTER, "%s", system_info.version);//дополнительная информация
    attroff(A_BOLD);

    mvprintw(7, LEFT_CENTER, "Machine: ");
    attron(A_BOLD);
    mvprintw(7, RIGHT_CENTER, "%s", system_info.machine);//архитектура
    attroff(A_BOLD);

    do_ramka(1, 8, "Kernel Information");
}

void print_display_info()
{
    Display *display = XOpenDisplay(NULL);
    if (display == NULL) {
        fprintf(stderr, "Error opening display\n");
        return;
    }

    int screenCount = ScreenCount(display);

    XCloseDisplay(display);

    clear(); // Очистка экрана
    refresh(); // Обновление экрана

    mvprintw(3, LEFT_CENTER, "Number of screens: ");
    attron(A_BOLD);
    mvprintw(3, RIGHT_CENTER, "%d", screenCount);
    attroff(A_BOLD);

    for (int screenNum = 0; screenNum < screenCount; ++screenNum) {
        Screen *screen = ScreenOfDisplay(display, screenNum);
        if (screen == NULL) {
            fprintf(stderr, "Error getting information for screen %d\n", screenNum);
            continue;
        }

        int width = WidthOfScreen(screen);
        int height = HeightOfScreen(screen);

        mvprintw(screenNum + 4, LEFT_CENTER, "Screen resolution %d:", screenNum);
        attron(A_BOLD);
        mvprintw(screenNum + 4, RIGHT_CENTER, "%d x %d\n", width, height);
        attroff(A_BOLD);
    }

   do_ramka(1, screenCount + 5, "Display Information");

}

void print_user_info() {

    clear(); // Очистка экрана
    refresh(); // Обновление экрана

    uid_t uid = getuid(); // Получение идентификатора текущего пользователя
    struct passwd *user_info = getpwuid(uid); // Получение информации о пользователе


    if (user_info == NULL)
    {
        perror("ERROR WITH ACCES SYSTEM");
        return;
    }

    mvprintw(3, LEFT_CENTER, "User Name: ");
    attron(A_BOLD);
    mvprintw(3, RIGHT_CENTER, "%s", user_info->pw_name); // Вывод имени пользователя
    attroff(A_BOLD);

    mvprintw(4, LEFT_CENTER, "User ID  :");
    attron(A_BOLD);
    mvprintw(4, RIGHT_CENTER, "%d", user_info->pw_uid); // Вывод идентификатора пользователя
    attroff(A_BOLD);

    mvprintw(5, LEFT_CENTER, "Home Directory: ");
    attron(A_BOLD);
    mvprintw(5, RIGHT_CENTER, "%s", user_info->pw_dir); // Вывод домашнего каталога пользователя
    attroff(A_BOLD);

    mvprintw(6, LEFT_CENTER, "Shell   :");
    attron(A_BOLD);
    mvprintw(6, RIGHT_CENTER, "%s", user_info->pw_shell); // Вывод оболочки пользователя
    attroff(A_BOLD);

    do_ramka(1, 7, "User Information");
}


void print_realTimeClock_info() {

    clear(); // Очистка экрана
    refresh(); // Обновление экрана

    int rtc_fd = open("/dev/rtc", O_RDONLY);
    if (rtc_fd == -1) {
        perror("Error opening RTC");
        return;
    }

    struct rtc_time rtc;
    if (ioctl(rtc_fd, RTC_RD_TIME, &rtc) == -1) {
        perror("Error reading RTC");
        close(rtc_fd);
        return;
    }
    close(rtc_fd);

    mvprintw(3, LEFT_CENTER, "Year: ");
    attron(A_BOLD);
    mvprintw(3, RIGHT_CENTER, "%d", rtc.tm_year + 1900);
    attroff(A_BOLD);

    mvprintw(4, LEFT_CENTER, "Month: ");
    attron(A_BOLD);
    mvprintw(4, RIGHT_CENTER, "%d", rtc.tm_mon + 1);
    attroff(A_BOLD);

    mvprintw(5, LEFT_CENTER, "Day: ");
    attron(A_BOLD);
    mvprintw(5, RIGHT_CENTER, "%d", rtc.tm_mday);
    attroff(A_BOLD);

    mvprintw(6, LEFT_CENTER, "Hour:");
    attron(A_BOLD);
    mvprintw(6, RIGHT_CENTER, "%d", rtc.tm_hour);
    attroff(A_BOLD);

    mvprintw(7, LEFT_CENTER, "Minute:");
    attron(A_BOLD);
    mvprintw(7, RIGHT_CENTER, "%d", rtc.tm_min);
    attroff(A_BOLD);

    mvprintw(8, LEFT_CENTER, "Second:");
    attron(A_BOLD);
    mvprintw(8, RIGHT_CENTER, "%d", rtc.tm_sec);
    attroff(A_BOLD);

    do_ramka(1, 9, "RTC Information:");

}

void print_memory_info() {

    clear(); // Очистка экрана
    refresh(); // Обновление экрана

    struct sysinfo mem_info;


    if (sysinfo(&mem_info) == -1)
    {
        perror("ERROR WITH SYSTEM ACCES");
        return;
    }


    mvprintw(3, LEFT_CENTER, "Total RAM: ");
    attron(A_BOLD);
    mvprintw(3, RIGHT_CENTER, "%.2f GB", covert_bytes_to_gigabytes(mem_info.totalram)); // Вывод общего объема оперативной памяти
    attroff(A_BOLD);

    mvprintw(4, LEFT_CENTER, "Free RAM:");
    attron(A_BOLD);
    mvprintw(4, RIGHT_CENTER, "%.2f GB", covert_bytes_to_gigabytes(mem_info.freeram));   // Вывод объема свободной памяти
    attroff(A_BOLD);

    mvprintw(5, LEFT_CENTER, "Used RAM:");
    attron(A_BOLD);
    mvprintw(5, RIGHT_CENTER, "%.2f GB", covert_bytes_to_gigabytes(mem_info.totalram - mem_info.freeram)); // Вывод объема используемой памяти
    attroff(A_BOLD);

    mvprintw(6, LEFT_CENTER, "Num active process: ");
    attron(A_BOLD);
    mvprintw(6, RIGHT_CENTER, "%d", process_count()); // Вывод объема используемой памяти
    attroff(A_BOLD);

    do_ramka(1, 7, "Memory Information");
}


void print_disk_info() {

    clear(); // Очистка экрана
    refresh(); // Обновление экрана

    struct statvfs stat;

    // Получение информации о файловой системе
    if (statvfs("/", &stat) == -1) {
        perror("ERROR WITH ACCES FILE SYSTEM");
        return;
    }

    mvprintw(3, LEFT_CENTER, "Total disk space: ");
    attron(A_BOLD);
    mvprintw(3, RIGHT_CENTER, "%.2f GB", covert_bytes_to_gigabytes(stat.f_blocks * stat.f_frsize)); // Вывод общего объема памяти
    attroff(A_BOLD);

    mvprintw(4, LEFT_CENTER, "Free space:");
    attron(A_BOLD);
    mvprintw(4, RIGHT_CENTER, "%.2f GB", covert_bytes_to_gigabytes(stat.f_bfree * stat.f_frsize));   // Вывод объема свободной памяти
    attroff(A_BOLD);

    mvprintw(5, LEFT_CENTER, "Used space:");
    attron(A_BOLD);
    mvprintw(5, RIGHT_CENTER, "%.2f GB", covert_bytes_to_gigabytes(stat.f_blocks * stat.f_frsize - stat.f_bfree * stat.f_frsize));//Вывод объема используемой памяти
    attroff(A_BOLD);

    do_ramka(1, 6, "Disk Information");

}

 void print_motherboardAndBios_info()
 {
    char *board_vendor = NULL;
    char *board_name = NULL;
    char *bios_vendor = NULL;
    char *bios_version = NULL;

    read_sysfs_file("/sys/devices/virtual/dmi/id/board_vendor", &board_vendor);
    read_sysfs_file("/sys/devices/virtual/dmi/id/board_name", &board_name);
    read_sysfs_file("/sys/devices/virtual/dmi/id/bios_vendor", &bios_vendor);
    read_sysfs_file("/sys/devices/virtual/dmi/id/bios_version", &bios_version);

    clear(); // Очистка экрана
    refresh(); // Обновление экрана

    int i;

    mvprintw(3, LEFT_CENTER, "Vendor: ");
    attron(A_BOLD);
    mvprintw(3, RIGHT_CENTER, "%s", board_vendor);
    attroff(A_BOLD);

    mvprintw(4, LEFT_CENTER, "Name:");
    attron(A_BOLD);
    mvprintw(4, RIGHT_CENTER, "%s", board_name);
    attroff(A_BOLD);


    for (i = START_ROW; i < LENGTH_ROW; i++) {mvprintw(5, i, "-");}
    mvprintw(6, CENTER, "BIOS Information");
    for (i = START_ROW; i < LENGTH_ROW; i++) {mvprintw(7, i, "-");}

    mvprintw(8, LEFT_CENTER, "Vendor: ");
    attron(A_BOLD);
    mvprintw(8, RIGHT_CENTER, "%s", bios_vendor);
    attroff(A_BOLD);

    mvprintw(9, LEFT_CENTER, "Name:");
    attron(A_BOLD);
    mvprintw(9, RIGHT_CENTER, "%s", bios_version);
    attroff(A_BOLD);


    do_ramka(1, 10, "Motherboard Information");

    free(board_vendor);
    free(board_name);
    free(bios_vendor);
    free(bios_version);

 }

void print_cpu_info() {

    FILE* cpuinfo = fopen("/proc/cpuinfo", "r");
    if (cpuinfo == NULL) {
        printf("Failed to open /proc/cpuinfo\n");
        return;
    }

    char line[256];
    char model[256];
    char frequency[256];
    int cores = 0;

    while (fgets(line, sizeof(line), cpuinfo)) {
        if (strncmp(line, "model name", 10) == 0) {
            char* model_ptr = strchr(line, ':');
            if (model_ptr != NULL) {
                strncpy(model, model_ptr + 2, sizeof(model) - 1);
                model[sizeof(model) - 1] = '\0';
            }
        } else if (strncmp(line, "cpu MHz", 7) == 0) {
            char* frequency_ptr = strchr(line, ':');
            if (frequency_ptr != NULL) {
                strncpy(frequency, frequency_ptr + 2, sizeof(frequency) - 1);
                frequency[sizeof(frequency) - 1] = '\0';
            }
        } else if (strncmp(line, "cpu cores", 9) == 0) {
            char* cores_ptr = strchr(line, ':');
            if (cores_ptr != NULL) {
                cores = atoi(cores_ptr + 2);
            }
        }
    }
    fclose(cpuinfo);

    clear(); // Очистка экрана
    refresh(); // Обновление экрана

    mvprintw(3, LEFT_CENTER, "CPU Model: ");
    attron(A_BOLD);
    mvprintw(3, RIGHT_CENTER, "%s", model);  // Вывод модели ЦПУ
    attroff(A_BOLD);

    mvprintw(4, LEFT_CENTER, "CPU Frequency(MHz):");
    attron(A_BOLD);
    mvprintw(4, RIGHT_CENTER, "%s", frequency); // Вывод частоты ЦПУ в мегагерцах
    attroff(A_BOLD);

    mvprintw(5, LEFT_CENTER, "CPU Cores::");
    attron(A_BOLD);
    mvprintw(5, RIGHT_CENTER, "%d", cores); // Вывод количества ядер ЦПУ используемой памяти
    attroff(A_BOLD);

    do_ramka(1, 6, "CPU Information");

}

void print_IP_info() {
    struct ifaddrs *ifaddr, *ifa;
    char host[NI_MAXHOST];

    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        return;
    }
    clear(); // Очистка экрана
    refresh(); // Обновление экрана

    struct utsname system_info;//структура, которая содержит информацию о системе
    uname(&system_info);//используется для получения информации о системе и заполняет переданную ей структуру

    int i = 0;

    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL)
            continue;

        if (ifa->ifa_addr->sa_family == AF_INET) {
            if (getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in), host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST) == 0) {
                mvprintw(i+3, LEFT_CENTER, "Interface: %s\tAddress: %s\n", ifa->ifa_name, host);
                i++;
            }
        }
    }
    do_ramka(1, i + 4, "IP Information");
    freeifaddrs(ifaddr);
}

void switch_info(char choice){
    switch(choice)
        {
            case '1':
                print_kernel_info();
                break;
            case '2':
                print_user_info();
                break;
            case '3':
                print_memory_info();
                break;
            case '4':
                print_disk_info();
                break;
            case '5':
                print_cpu_info();
                break;
            case '6':
                print_motherboardAndBios_info();
                break;
            case '7':
                print_realTimeClock_info();
                break;
            case '8':
                print_display_info();
                break;
            case '9':
                print_IP_info();
                break;
            case '0':
                print_battery_info();
                break;
            case 'q':
                attroff(COLOR_PAIR(GREEN_COLOR));
                attron(COLOR_PAIR(RED_COLOR));
                mvprintw(15, CENTER - 5, "Exiting program... ");
                attroff(COLOR_PAIR(RED_COLOR));
                attron(COLOR_PAIR(GREEN_COLOR));
                break;
            default:
                attroff(COLOR_PAIR(GREEN_COLOR));
                attron(COLOR_PAIR(RED_COLOR));
                mvprintw(15, CENTER - 5, "Invalid Input ");
                refresh(); // Обновление экрана перед выводом сообщения
                attroff(COLOR_PAIR(RED_COLOR));
                attron(COLOR_PAIR(GREEN_COLOR));
                sleep(1); // Задержка выполнения на 1 секунду
                break ;
        }
}

void menu_sys_info() {

    char choice = 'a';
    while(choice != 'q')
    {
        shapka();
        choice = getch(); // Ввод символа с клавиатуры
        switch_info(choice);
    }
}

void processArguments(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-kernel") == 0) {
             switch_info('1');
        } else if (strcmp(argv[i], "-user") == 0) {
             switch_info('2');
        } else if (strcmp(argv[i], "m&p") == 0) {
             switch_info('3');
        } else if (strcmp(argv[i], "-disk") == 0) {
             switch_info('4');
        } else if (strcmp(argv[i], "-gpu") == 0) {
             switch_info('5');
        } else if (strcmp(argv[i], "-m&b") == 0) {
             switch_info('6');
        } else if (strcmp(argv[i], "-rtc") == 0) {
             switch_info('7');
        } else if (strcmp(argv[i], "-display") == 0) {
             switch_info('8');
        } else if (strcmp(argv[i], "-ip") == 0) {
             switch_info('9');
        } else if (strcmp(argv[i], "-batery") == 0) {
             switch_info('0');

        } else {
            clear(); // Очистка экрана
            refresh(); // Обновление экрана

            attroff(COLOR_PAIR(GREEN_COLOR));

            attron(COLOR_PAIR(RED_COLOR));
            mvprintw(15, CENTER - 5, "Invalid Argument ");
            attroff(COLOR_PAIR(RED_COLOR));


            attron(COLOR_PAIR(BLUE_COLOR));
            mvprintw(16, LEFT_CENTER, "Enter 'q' to exit modul");
            attroff(COLOR_PAIR(BLUE_COLOR));

            attron(COLOR_PAIR(GREEN_COLOR));

            char choice = 'a';
            while(choice != 'q')
                {choice = getch();} // Ввод символа с клавиатуры}
        }
    }
}
