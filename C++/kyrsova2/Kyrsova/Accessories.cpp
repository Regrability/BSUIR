//Accessories.cpp
#include "Accessories.h"
Accessories::Accessories() : Clothing(){
    style = "NONE";
    brand = "NONE";

}
Accessories::Accessories(string name, string category, double value, string size, string material, string style, string brand)
    : Clothing(name, category, value, size, material), style(style), brand(brand) {}

string Accessories::getStyle() { return style; }
string Accessories::getBrand() { return brand; }

void Accessories::setStyle(string style) { this->style = style; }
void Accessories::setBrand(string brand) { this->brand = brand; }


void Accessories::Shapka()
{
    cout << "Accessories:" << endl;
    cout << string(98, '-') << endl;
    cout << '|' << left << setw(13) << "Name" << '|';
    cout << left << setw(14) << "Value ($)" << '|';
    cout << left << setw(13) << "Size" << '|';
    cout << left << setw(17) << "Material" << '|';
    cout << left << setw(17) << "Style" << '|';
    cout << left << setw(17) << "Brand" << '|' << endl;
    cout << string(98, '-') << endl;
}

void Accessories::ChangeField()
{
    cout << "Enter field to change" << endl;
    cout << "1.Name" << endl;
    cout << "2.Value ($)" << endl;
    cout << "3.Size" << endl;
    cout << "4.Material" << endl;
    cout << "5.Style" << endl;
    cout << "6.Brand" << endl;
    int choice = InputINT(1, 6);
    switch (choice) {
    case 1:
        cout << "Enter name: "; name = InputString();
        break;
    case 2:
        cout << "Enter value ($): "; value = InputDouble(0, 10000);
        break;
    case 3:
        cout << "Enter size: "; size = InputString();
        break;
    case 4:
        cout << "Enter material: "; material = InputString();
        break;
    case 5:
        cout << "Enter style: "; style = InputString();
        break;
    case 6:
        cout << "Enter brand:";  brand = InputString();
        break;
    }
}

string Accessories::GetFileName()
{
    return "Accessories.txt";
}

ifstream& operator>>(ifstream& input, Accessories& obj)
{
    input >> static_cast<Clothing&>(obj);
    if (obj.name == "") return input;
    getline(input, obj.style, '\t'); 
    getline(input, obj.brand, '\n'); 
    return input; 
}
ofstream& operator<<(ofstream& os, const Accessories& obj) {
    os << static_cast<const Clothing&>(obj); 
    os << obj.style << "\t" << obj.brand << "\n";
    return os;
}
istream& operator>>(istream& input, Accessories& obj)
{
    system("cls");
    cout << "ENTER ACCESSORIES" << endl;
    input >> static_cast<Clothing&>(obj); 
    cout << "Enter style: "; obj.style = InputString();
    cout << "Enter brand:";  obj.brand = InputString();
    system("cls");
    return input;
}
ostream& operator<<(ostream& os, Accessories obj)
{
    os << static_cast<const Clothing&>(obj);
    os << left << setw(17) << obj.style << '|';
    os << left << setw(17) << obj.brand << '|' << endl;
    cout << string(98, '-') << endl;
    return os;

}