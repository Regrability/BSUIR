#ifndef BOOKSTORE_H
#define BOOKSTORE_H

#include "Book.h"

class BookStore : public Book {
private:
    double price;

public:
    // Конструктор
    BookStore(const std::string& title, const std::string& author, int year, double price);

    // Методы
    void discountPrice();
    std::string displayBookStoreInfo() const;
};

#endif // BOOKSTORE_H
