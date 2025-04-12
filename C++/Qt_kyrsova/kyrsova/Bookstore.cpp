#include "Bookstore.h"
#include <iostream>
#include <sstream>

using namespace std;

// Конструктор
BookStore::BookStore(const string& title, const string& author, int year, double price)
    : Book(title, author, year), price(price) {
    discountPrice();
}

// Метод для уменьшения стоимости книги
void BookStore::discountPrice() {
    if (calculateBookAge() > 5) {
        price *= 0.8; // Скидка 20%
    }
}

// Метод для формирования строки с информацией о книге в магазине
string BookStore::displayBookStoreInfo() const {
    // Используем stringstream для формирования строки
    stringstream info;
    // Добавляем информацию из базового класса Book
    info << displayBookInfo();
    // Добавляем информацию о цене
    info << "\nЦена со скидкой: " << price << " BYN";
    return info.str(); // Возвращаем строку
}

