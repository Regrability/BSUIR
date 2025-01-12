#pragma once
#include <iostream>
using namespace std;

class String {
 private:
    char* str;

 public:
    String();
    explicit String(const char* s); 
    String(const String& other); 
    ~String();
    void vvod_str();
    char* convert20() const;
    String operator+(const char* other);
    String operator+(const String& other);
    friend String operator+(const char* str, const String& other);
    String operator+=(const String& other);
    String operator+=(const char s);
    String& operator=(const String& other);  // Перегрузка оператора присваивания
    String& operator=(const char* s);  
    bool operator>(const String& other);
    bool operator<(const String& other);
    char operator[](int index);
    char* operator()() const;
    String operator()(int start, int end);
    friend ostream& operator<<(ostream& os, const String& obj);
};
