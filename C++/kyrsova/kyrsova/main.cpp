//main.cpp
#include "Menu.h"

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251); // ���� � ������� � ��������� 1251
    read_conversation_from_file_to_list();
    Run();
    return 0;
}