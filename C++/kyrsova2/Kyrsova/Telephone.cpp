//Telephone.cpp
#include "Telephone.h"
Telephone::Telephone() : Electronics() {
    network = "NONE";
    screenSize = 0.0;}
Telephone::Telephone(string name, string category, double value, string brand, string model, string network, double screenSize)
    : Electronics(name, category, value, brand, model), network(network), screenSize(screenSize) {}

string Telephone::getNetwork() { return network; }
double Telephone::getScreenSize() { return screenSize; }

void Telephone::setNetwork(string network) { this->network = network; }
void Telephone::setScreenSize(double screenSize) { this->screenSize = screenSize; }

void Telephone::Shapka()
{
    cout << "Telephone:" << endl;
    cout << string(98, '-') << endl;
    cout << '|' << left << setw(13) << "Name" << '|';
    cout << left << setw(14) << "Value ($)" << '|';
    cout << left << setw(13) << "Brand" << '|';
    cout << left << setw(17) << "Model" << '|';
    cout << left << setw(17) << "Network" << '|';
    cout << left << setw(17) << "Screen Size(inch)" << '|' << endl;
    cout << string(98, '-') << endl;
}

void Telephone::ChangeField()
{
    cout << "Enter field to change" << endl;
    cout << "1.Name" << endl;
    cout << "2.Value ($)" << endl;
    cout << "3.Brand" << endl;
    cout << "4.Model" << endl;
    cout << "5.Network" << endl;
    cout << "6.Screen Size(inch)" << endl;
    int choice = InputINT(1, 6);
    switch (choice) {
    case 1:
        cout << "Enter name: "; name = InputString();
        break;
    case 2:
        cout << "Enter value ($): "; value = InputDouble(0, 10000);
        break;
    case 3:
        cout << "Enter brand: "; brand = InputString();
        break;
    case 4:
        cout << "Enter model: "; model = InputStringwithINT();
        break;
    case 5:
        cout << "Enter Network: "; network = InputStringwithINT();
        break;
    case 6:
        cout << "Enter Screen Size(inch):"; screenSize = InputDouble(1, 20); 
        break;
    }
}

string Telephone::GetFileName()
{
    return "Telephones.txt";
}

ifstream& operator>>(ifstream& input, Telephone& obj)
{
    input >> static_cast<Electronics&>(obj);

    if (obj.name == "") return input;
    string buf;
    double buf1;
    getline(input, obj.network, '\t');


    input >> buf;
    locale::global(std::locale("C"));
    buf1 = stod(buf);
    obj.screenSize = buf1;
    input.ignore();
    return input;
}

ofstream& operator<<(ofstream& os, const Telephone& obj) {
    os << static_cast<const Electronics&>(obj);
    os << obj.network << "\t" << obj.screenSize << "\n";
    return os;
}
istream& operator>>(istream& input, Telephone& obj)
{
    system("cls");
    cout << "Enter TELEPHONE" << endl;
    input >> static_cast<Electronics&>(obj);
    cout << "Enter Network: "; obj.network = InputStringwithINT();
    cout << "Enter Screen Size(inch):"; obj.screenSize = InputDouble(1, 20);
    system("cls");
    return input;
}
ostream& operator<<(ostream& os, Telephone obj)
{
    os << static_cast<const Electronics&>(obj);
    os << left << setw(17) << obj.network << '|';
    os << left << setw(17) << obj.screenSize << '|' << endl;
    cout << string(98, '-') << endl;
    return os;

}