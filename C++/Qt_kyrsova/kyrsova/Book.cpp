#include "Book.h"
#include <iostream>
#include <ctime>
#include <sstream>


using namespace std;

// Конструктор
Book::Book(const string& title, const string& author, int year)
    : title(title), author(author), year(year) {
}

// Метод для вычисления возраста книги
int Book::calculateBookAge() const {
    time_t now = time(0);
    struct tm ltm = {};
    localtime_s(&ltm, &now); // Безопасная версия localtime
    int currentYear = 1900 + ltm.tm_year;
    return currentYear - year;
}

long long Book::calculateDaysSincePublication() const {
    time_t now = time(0);
    struct tm ltm = {};
    localtime_s(&ltm, &now); // Безопасная версия localtime

    // Количество дней, прошедших с начала года
    int dayOfYear = ltm.tm_yday + 1; // tm_yday дает количество дней с 1 января, начиная с 0

    // Возраст книги в годах
    int age = calculateBookAge();

    // Количество дней, прошедших за полные годы
    long long days = 365 * age + (age / 4); // Добавляем високосные года

    // Добавляем количество дней в текущем году
    days += dayOfYear;

    return days;
}



// Метод для формирования строки с информацией о книге
std::string Book::displayBookInfo() const {
    // Используем stringstream для формирования строки
    std::stringstream info;
    info << "Возраст книги: " << calculateBookAge() << " лет"
         << "\nДней с момента публикации: " << calculateDaysSincePublication() << " дней";
    return info.str(); // Возвращаем строку
}

