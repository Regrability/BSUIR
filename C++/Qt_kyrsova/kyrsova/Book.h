#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
protected:
    std::string title;
    std::string author;
    int year;

public:
    // Конструктор
    Book(const std::string& title, const std::string& author, int year);

    // Методы
    int calculateBookAge() const;
    long long calculateDaysSincePublication() const;
    std::string displayBookInfo() const;
};

#endif // BOOK_H
