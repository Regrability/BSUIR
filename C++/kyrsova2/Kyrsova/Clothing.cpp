//Clothing.cpp
#include "Clothing.h"
Clothing::Clothing() : Item() {
    category = "Clothing";
    size = "NONE";
    material = "NONE";
}
Clothing::Clothing(string name, string category, double value, string size, string material)
    : Item(name, category, value), size(size), material(material) {}

string Clothing::getSize() { return size; }
string Clothing::getMaterial() { return material; }

void Clothing::setSize(string size) { this->size = size; }
void Clothing::setMaterial(string material) { this->material = material; }

ifstream& operator>>(ifstream& input, Clothing& obj)
{
    input >> static_cast<Item&>(obj);
    if (obj.name == "") return input;
    input.ignore();
    getline(input, obj.size, '\t');
    getline(input, obj.material, '\t');
    return input;
}

ofstream& operator<<(ofstream& os, const Clothing& obj) {
    os << static_cast<const Item&>(obj);
    os << obj.size << "\t" << obj.material << "\t";
    return os;
}

istream& operator>>(istream& input, Clothing& obj)
{
    input >> static_cast<Item&>(obj);
    cout << "Enter size: "; obj.size = InputString();
    cout << "Enter material: "; obj.material = InputString();
    return input;
}
ostream& operator<<(ostream& os, Clothing obj)
{
    os << static_cast<const Item&>(obj);
    os << left << setw(13) << obj.size << '|';
    os << left << setw(17) << obj.material << '|';
    return os;

}