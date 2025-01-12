#include <iostream>
#include <string>
using namespace std;

class String {
 private:
    char* str;

 public:
    String();
    explicit  String(const char* s);
    String(const String& other);
    ~String();
    char* GetSTR();
    void vvod_str();
    String operator+(const char* other);
    String operator+(const String& other);
    friend String operator+(const char* str, const String& other);
    String operator+=(const String& other);
    bool operator>(const String& other);
    bool operator<(const String& other);
    char operator[](int index);
    char* operator()();
    String operator()(int start, int end);
};
int strlengt(const char* s);
void strcopy(char* dest, const char* src);
void strconnection(char* dest, const char* src);
