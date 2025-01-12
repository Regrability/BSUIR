#pragma once
#define MAX_SIZE  10
#include "MyVvod.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip> 
using namespace std;
class Person
{
protected:
    string last_name;
    string first_name;
    int birth_year;

public:
    Person();
    Person(string last_name, string first_name, int birth_year);
    ~Person();
    string get_last_name() const;
    void set_last_name(string last_name);
    string get_first_name() const;
    void set_first_name(string first_name);
    int get_birth_year() const;
    void set_birth_year(int birth_year);
    void virtual shapka() {};
    void virtual ChangeField() {};
    friend istream& operator>>(istream& is, Person& obj);
    friend ostream& operator<<(ostream& os, const Person& obj);
};