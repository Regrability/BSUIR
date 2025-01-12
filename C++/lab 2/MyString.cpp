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
    *dest = '\0'; // ��������� ����������� ������� ������
}
void strconnection(char* dest, const char* src)
{
    // ������� ����� ������ dest
    while (*dest != '\0') {
        ++dest;
    }
    *dest = ' ';
    ++dest;
    // �������� ������� �� src � ����� dest
    while (*src != '\0') {
        *dest = *src;
        ++dest;
        ++src;
    }

    // ��������� ����������� ������� ������
    *dest = '\0';
}
// ������������
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
// ����������
String::~String()
{
        delete[] str;
}



char* String::GetSTR() 
{
        return this->str;
}
//�����������
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

    // ����������
    // 
    // ���������� ��������� �������� (+)
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


    // ���������� ��������� ���������� ������������ (+=)
    String String:: operator+=(const String& other) {
        int length = strlengt(this->str) + strlengt(other.str);
        char* result = new char[length + 2];
        strcopy(result, this->str);
        strconnection(result, other.str);
        delete[] str;
        str = result;
        return *this;
    }
    // ���������� ��������� "������" (>)
    bool String:: operator>(const String& other)
    {
        if (strlengt(this->str) > strlengt(other.str))
            return true;
        else return false;

    }
    // ���������� ��������� "������" (<)
    bool String:: operator<(const String& other) {
        if (strlengt(this->str) < strlengt(other.str))
            return true;
        else return false;
    }
    // ���������� ��������� ���������� ([])
    char String:: operator[](int index) {
        return this->str[index];
    }
    // ���������� ��������� ������ ������� ()
    char* String:: operator()() {
        return this->str;
    }
    // ���������� ��������� ������ ������� � ����� ����������� (int, int)
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
