#include "Person.h"

Person::Person()
    : last_name("NONE"), first_name("NONE"), birth_year(0) {}
Person::Person(string last_name, string first_name, int birth_year)
    : last_name(last_name), first_name(first_name), birth_year(birth_year) {}
Person:: ~Person() {}

string Person::get_last_name() const { return this->last_name; }
void   Person::set_last_name(string last_name) { this->last_name = last_name; }

string Person::get_first_name() const { return first_name; }
void   Person::set_first_name(string first_name) { this->first_name = first_name; }

int    Person::get_birth_year() const { return birth_year; }
void   Person::set_birth_year(int birth_year) { this->birth_year = birth_year; }
istream& operator>>(istream& is, Person& obj)
{
    cout << "Enter last name: "; obj.last_name = InputString();
    cout << "Enter first name: "; obj.first_name = InputString();
    cout << "Enter birth year: "; obj.birth_year = InputINT(1900, 2023);
    return is;
}

ostream& operator<<(ostream& os, const Person& obj)
{
    os << '|' << left << setw(13) << obj.last_name << '|';
    os << left << setw(14) << obj.first_name << '|';
    os << left << setw(13) << obj.birth_year << '|';
    return os;
}

