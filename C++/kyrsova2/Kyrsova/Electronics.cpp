//Electronics.cpp
#include "Electronics.h"
Electronics::Electronics() : Item() {
    category = "Electronics";
    brand = "NONE";
    model = "NONE";}
Electronics::Electronics(string name, string category, double value, string brand, string model)
    : Item(name, category, value), brand(brand), model(model) {}


string Electronics::getBrand() { return brand; }
string Electronics::getModel() { return model; }

void Electronics::setBrand(string brand) { this->brand = brand; }
void Electronics::setModel(string model) { this->model = model; }


ifstream& operator>>(ifstream& input, Electronics& obj)
{
    input >> static_cast<Item&>(obj);
    if (obj.name == "") return input;
    input.ignore();
    getline(input, obj.brand, '\t'); 
    getline(input, obj.model, '\t');
    return input;
}

ofstream& operator<<(ofstream& os, const Electronics& obj) {
    os << static_cast<const Item&>(obj);
    os << obj.brand << "\t" << obj.model << "\t";
    return os;
}
istream& operator>>(istream& input, Electronics& obj)
{
    input >> static_cast<Item&>(obj);
    cout << "Enter brand: "; obj.brand = InputString();
    cout << "Enter model: ";  obj.model = InputStringwithINT();
    return input;
}
ostream& operator<<(ostream& os, Electronics obj)
{
    os << static_cast<const Item&>(obj);
    os << left << setw(13) << obj.brand << '|';
    os << left << setw(17) << obj.model << '|';
    return os;
}