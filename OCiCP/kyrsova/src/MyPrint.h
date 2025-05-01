#ifndef MYPRINT_H_
#define MYPRINT_H_

#include "tools.h"

void print_IP_info();
void print_disk_info();
void print_memory_info();
void print_cpu_info();
void print_motherboardAndBios_info();
void print_realTimeClock_info();
void print_display_info();
void print_kernel_info();
void print_user_info();
void print_battery_info();
void shapka();

void menu_sys_info();
void processArguments(int argc, char *argv[]);
void switch_info(char choice);

#endif
