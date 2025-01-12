//Item.cpp
#include "Item.h"
Item::Item() {
    name = "NONE";
    value = 0.0;}
Item::Item(string name, string category, double value)
    : name(name), category(category), value(value) {}

string Item::getName() { return name; }
string Item::getCategory() { return category; }
double Item::getValue() { return value; }
void Item::setName(string name) { this->name = name; }
void Item::setCategory(string category) { this->category = category; }
void Item::setValue(double value) { this->value = value; }
string Item::GetFileName() { return ""; }

ifstream& operator>>(ifstream& input, Item& obj)
{
    string buf;
    double buf1;
    getline(input, obj.name, '\t');
    if (obj.name == "") return input;
    input >> buf;
    locale::global(std::locale("C"));
    buf1 = stod(buf);
    obj.value = buf1;
    return input;
}

ofstream& operator<<(ofstream& os, const Item& obj) {
    os << obj.name << "\t" << obj.value << "\t";
    return os;
}
istream& operator>>(istream& input, Item& obj)
{
    cout << "Use English leangvitch" << endl;
    cout << "Enter name: "; obj.name = InputString();
    cout << "Enter value ($): "; obj.value = InputDouble(0, 10000);
    return input;
}
ostream& operator<<(ostream& os, Item obj)
{
    os << '|' << left << setw(13) << obj.name << '|';
    os << left << setw(14) << obj.value << '|';
    return os;

}