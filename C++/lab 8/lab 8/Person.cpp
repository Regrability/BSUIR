#include "Person.h"

Person::Person()
    : last_name("NONE"), first_name("NONE"), birth_year(0) {}

Person::Person(String last_name, String first_name, int birth_year)
    : last_name(last_name), first_name(first_name), birth_year(birth_year) {}

Person::~Person() {}

String Person::get_last_name() const { return this->last_name; }
void Person::set_last_name(String last_name) { this->last_name = last_name; }

String Person::get_first_name() const { return first_name; }
void Person::set_first_name(String first_name) { this->first_name = first_name; }

int Person::get_birth_year() const { return birth_year; }
void Person::set_birth_year(int birth_year) { this->birth_year = birth_year; }

istream& operator>>(istream& is, Person& obj)
{
    cout << "Enter last name: ";
    obj.last_name = InputString();
    cout << "Enter first name: ";
    obj.first_name = InputString();
    cout << "Enter birth year: ";
    obj.birth_year = InputINT(1900, 2023);
    return is;
}

ostream& operator<<(ostream& os, const Person& obj)
{
    os << '|' << left << setw(13) << obj.last_name << '|';
    os << left << setw(14) << obj.first_name << '|';
    os << left << setw(13) << obj.birth_year << '|';
    return os;
}

ifstream& operator>>(ifstream& is, Person& obj)
{
    string buf;
    char c;
    obj.last_name = "";
    obj.first_name = "";
    while (is.get(c) && c != '\t') {
        obj.last_name += c;
    }
    while (is.get(c) && c != '\t') {
        obj.first_name += c;
    }
    is >> buf;
    obj.birth_year = stoi(buf);
    return is;
}

ofstream& operator<<(ofstream& os, const Person& obj) {
    os << obj.last_name() << "\t" << obj.first_name() << "\t" << obj.birth_year << "\t";
    return os;
}

fstream& operator>>(fstream& is, Person& obj)
{
    char* buf = new char[20];
    // Чтение фамилии
    is.read(buf, 20);
    obj.last_name = buf;
    // Чтение имени
    is.read(buf, 20);
    obj.first_name = buf;
    // Чтение года рождения
    is.read(reinterpret_cast<char*>(&obj.birth_year), sizeof(obj.birth_year));
    delete[] buf;
    return is;
}

fstream& operator<<(fstream& os, const Person& obj)
{
    char* buf = new char[20];
    // Запись фамилии
    buf = obj.last_name.convert20();
    os.write(buf, 20);
    // Запись имени
    buf = obj.first_name.convert20();
    os.write(buf, 20);
    // Запись года рождения
    os.write((char*)&obj.birth_year, sizeof(obj.birth_year));
    delete[] buf;
    return os;
}