#include "MyPrint.h"

int main(int argc, char *argv[]) {

    initscr();
    start_color();//цветовой режим

    // Инициализация цветовых пар
    init_pair(GREEN_COLOR, COLOR_GREEN, COLOR_BLACK);
    init_pair(RED_COLOR, COLOR_RED, COLOR_BLACK);
    init_pair(BLUE_COLOR, COLOR_BLUE, COLOR_BLACK);

    cbreak(); // вводимые символы немедленно передаются программе, без ожидания нажатия на Enter
    noecho(); // отключаем отображение вводимых символов
    curs_set(0); // скрываем курсор

    attron(COLOR_PAIR(GREEN_COLOR));

    if (argc <= 1){
        menu_sys_info();}
    else {
        processArguments(argc, argv);}

    attroff(COLOR_PAIR(GREEN_COLOR));

    getch();
    endwin();

    return 0;
}
