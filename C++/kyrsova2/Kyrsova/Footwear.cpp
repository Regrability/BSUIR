//Footwear.cpp
#include "Footwear.h"
Footwear::Footwear() : Clothing() {
    type = "NONE";
    color = "NONE";
}
Footwear::Footwear(string name, string category, double value, string size, string material, string type, string color)
    : Clothing(name, category, value, size, material), type(type), color(color) {}

string Footwear:: getType() { return type; }
string Footwear::getColor() { return color; }

void Footwear::setType(string type) { this->type = type; }
void Footwear::setColor(string color) { this->color = color; }

void Footwear::Shapka()
{
    cout << "Footwear:" << endl;
    cout << string(98, '-') << endl;
    cout << '|' << left << setw(13) << "Name" << '|';
    cout << left << setw(14) << "Value ($)" << '|';
    cout << left << setw(13) << "Size" << '|';
    cout << left << setw(17) << "Material" << '|';
    cout << left << setw(17) << "Type" << '|';
    cout << left << setw(17) << "Color" << '|' << endl;
    cout << string(98, '-') << endl;
}

void Footwear::ChangeField()
{
    cout << "Enter field to change" << endl;
    cout << "1.Name" << endl;
    cout << "2.Value ($)" << endl;
    cout << "3.Size" << endl;
    cout << "4.Material" << endl;
    cout << "5.Type" << endl;
    cout << "6.Color" << endl;
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
        cout << "Enter type: "; type = InputString();
        break;
    case 6:
        cout << "Enter color:"; color = InputString();
        break;
    }
}

string Footwear::GetFileName()
{
    return "Footwears.txt";
}
ifstream& operator>>(ifstream& input, Footwear& obj)
{
    input >> static_cast<Clothing&>(obj);
    if (obj.name == "") return input;
    getline(input, obj.type, '\t');
    getline(input, obj.color, '\n');
    return input;
}

ofstream& operator<<(ofstream& os, const Footwear& obj) {
    os << static_cast<const Clothing&>(obj); 
    os << obj.type << "\t" << obj.color << "\n";
    return os;
}

istream& operator>>(istream& input, Footwear& obj)
{
    system("cls"); 
    cout << "ENTER FOOTWEAR" << endl;
    input >> static_cast<Clothing&>(obj);
    cout << "Enter type: "; obj.type = InputString();
    cout << "Enter color:"; obj.color = InputString();
    system("cls");
    return input;
}
ostream& operator<<(ostream& os, Footwear obj)
{
    os << static_cast<const Clothing&>(obj);
    os << left << setw(17) << obj.type << '|';
    os << left << setw(17) << obj.color << '|' << endl;
    cout << string(98, '-') << endl;
    return os;

}