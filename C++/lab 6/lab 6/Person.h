#pragma once
#define MAX_SIZE  10
#include "MyVvod.h"
#include <iostream>
#include <cstdlib>
#include "MyString.h"
#include <iomanip> 
using namespace std;

class Person
{
protected:
    String last_name;
    String first_name;
    int birth_year;

public:
    Person();
    Person(String last_name, String first_name, int birth_year);
    ~Person();
    String get_last_name() const;
    void set_last_name(String last_name);
    String get_first_name() const;
    void set_first_name(String first_name);
    int get_birth_year() const;
    void set_birth_year(int birth_year);
    void virtual shapka() = 0;
    void virtual ChangeField() = 0;
    string virtual GetFileName() = 0;
    string virtual GetFileNameBin() = 0;
    friend istream& operator>>(istream& is, Person& obj);
    friend ostream& operator<<(ostream& os, const Person& obj);
    friend ifstream& operator>>(ifstream& is, Person& obj);
    friend ofstream& operator<<(ofstream& os, const Person& obj);
    friend fstream& operator>>(fstream& is, Person& obj);
    friend fstream& operator<<(fstream& os, const Person& obj);
};