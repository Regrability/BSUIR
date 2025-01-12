#include "MyString.h"
int strlengt(const char* s)
{
    int ch = 0, i = 0;
    while (s[i] != '\0')
    {
        ch++;
        i++;
    }

    return ch;
}
void strcopy(char* dest, const char* src)
{
    while (*src != '\0') {
        *dest = *src;
        ++dest;
        ++src;
    }
    *dest = '\0'; // Добавляем завершающий нулевой символ
}
void strconnection(char* dest, const char* src)
{
    // Находим конец строки dest
    while (*dest != '\0') {
        ++dest;
    }
    // Копируем символы из src в конец dest
    while (*src != '\0') {
        *dest = *src;
        ++dest;
        ++src;
    }

    // Добавляем завершающий нулевой символ
    *dest = '\0';
}
// Конструкторы
String::String() : str(nullptr) {};
String::String(const char* s) 
{
        int length = strlengt(s);
        str = new char[length + 1];
        strcopy(str, s);
}
String::String(const String& other)
{
        int length = strlengt(other.str);
        str = new char[length + 1];
        strcopy(str, other.str);
}
// Деструктор
String::~String()
{
        delete[] str;
}
//инструменты
void String::vvod_str()
{
        char* buff = new char[80];
        char x = NULL;
        int i = 0;
        while ((x = getchar()) != '\n')
        {
            buff[i] = x;
            i++;
        }
        buff[i] = '\0';
        i++;
        this->str = new char[i];
        strcopy(this->str, buff);
}
char* String::convert20() const
{
    char* buff = new char[20];
    strcopy(buff, this->str);
    return buff;
}

    // Перегрузки
    // 
    // Перегрузка оператора сложения (+)
    String String:: operator+(const char* other)
    {
        int length = strlengt(this->str) + strlengt(other);
        char* result = new char[length + 2];
        strcopy(result, this->str);
        strconnection(result, other);
        return String(result);
    }
    String String:: operator+(const String& other) {
        int length = strlengt(this->str) + strlengt(other.str);
        char* result = new char[length + 2];
        strcopy(result, this->str);
        strconnection(result, other.str);
        return String(result);
    }
    String operator+(const char* str, const String& other)
    {
        size_t length = strlen(str) + strlen(other.str);
        char* result = new char[length + 1];
        strcpy_s(result, length + 1, str);
        strcat_s(result, length + 1, other.str);
        return String(result);
    }


    // Перегрузка оператора добавления присваивания (+=)
    String String:: operator+=(const String& other) {
        int length = strlengt(this->str) + strlengt(other.str);
        char* result = new char[length + 2];
        strcopy(result, this->str);
        strconnection(result, other.str);
        delete[] str;
        str = result;
        return *this;
    }
    String String:: operator+=(const char c) {
        int length = strlengt(this->str) + 1;
        char* result = new char[length + 2];
        strcopy(result, this->str);
        char* buf = new char[2];
        buf[0] = c;
        buf[1] = '\0';
        strconnection(result, buf);
        delete[] str;
        str = result;
        return *this;
    }

    //перегрузка операторов присваивания
    String& String::operator=(const String& other) {
        delete[] str;
        str = new char[strlengt(other.str) + 1];
        strcopy(str, other.str);
        return *this;
    }
    String& String::operator=(const char* s) {
        int length = strlengt(s);
        str = new char[length + 1];
        strcopy(str, s);
        str[length] = '\0';
        return *this;
    }
    bool String::operator==(String& other) {
        if (strlengt(str) == strlengt(other.str)) 
        {
            int  i = 0;
            while (str[i] != '\0')
            {
                if (str[i] != other.str[i])
                {
                    return false;
                }
                i++;
            }
            return true;
        }
        return false;
    }
    bool String::operator==(const char* other) {
        if (strlengt(str) == strlengt(other))
        {
            int  i = 0;
            while (str[i] != '\0')
            {
                if (str[i] != other[i])
                {
                    return false;
                }
                i++;
            }
            return true;
        }
        return false;
    }
    // Перегрузка оператора "больше" (>)
    bool String:: operator>(const String& other)
    {
        if (strlengt(this->str) > strlengt(other.str))
        {
            for (int i = 0; i < strlengt(other.str); i++)
            {
                if (str[i] == other[i])
                {
                    i++;
                }
                else if (str[i] > other[i])
                {
                    return true;
                }
                else if (str[i] < other[i])
                {
                    return false;
                }
            }
        }
        else
        {
            for (int i = 0; i < strlengt(this->str); i++)
            {
                if (str[i] == other[i])
                {
                    i++;
                }
                else if (str[i] > other[i])
                {
                    return true;
                }
                else if (str[i] < other[i])
                {
                    return false;
                }
            }
        }
        if (strlengt(this->str) > strlengt(other.str)){ return true; }
        else { return false; }
        return true;
    }
    // Перегрузка оператора "меньше" (<)
    bool String:: operator<(const String& other) {
        if (strlengt(this->str) > strlengt(other.str))
        {
            for (int i = 0; i < strlengt(other.str); i++)
            {
                if (str[i] == other[i])
                {
                    i++;
                }
                else if (str[i] < other[i])
                {
                    return true;
                }
                else if (str[i] > other[i])
                {
                    return false;
                }
            }
        }
        else
        {
            for (int i = 0; i < strlengt(this->str); i++)
            {
                if (str[i] == other[i])
                {
                    i++;
                }
                else if (str[i] < other[i])
                {
                    return true;
                }
                else if (str[i] > other[i])
                {
                    return false;
                }
            }
        }
        if (strlengt(this->str) > strlengt(other.str)) { return true; }
        else { return false; }
        return true;
    }
    // Перегрузка оператора индексации ([])
    char String:: operator[](int index) const {
        return this->str[index];
    }
    // Перегрузка оператора вызова функции ()
    char* String:: operator()() const{
        return this->str;
    }
    // Перегрузка оператора вызова функции с двумя аргументами (int, int)
    String String:: operator()(int start, int end)
    {
        int length = end - start + 1;
        char* result = new char[length];
        for (int i = 0; i < length; i++)
        {
            result[i] = this->str[start];
            start++;
        }
        result[length] = '\0';
        return String(result);
    }
    ostream& operator<<(std::ostream& os, const String& str)
    {
        os << str.str;
        return os;
    }


