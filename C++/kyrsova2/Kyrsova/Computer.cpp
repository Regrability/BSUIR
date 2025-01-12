//Computer.cpp
#include "Computer.h"
Computer::Computer() : Electronics() {
    operatingSystem = "NONE";
    memory = 0;
}
Computer::Computer(string name, string category, double value, string brand, string model, string operatingSystem, int memory)
    : Electronics(name, category, value, brand, model), operatingSystem(operatingSystem), memory(memory) {}

string Computer::getOperatingSystem() { return operatingSystem; }
int Computer::getMemory() { return memory; }

void Computer::setOperatingSystem(string operatingSystem) { this->operatingSystem = operatingSystem; }
void Computer::setMemory(int memory) { this->memory = memory; }

void Computer::Shapka() 
{
    cout << "Computers:" << endl;
    cout << string(98, '-') << endl;
    cout << '|' << left << setw(13) << "Name" << '|';
    cout << left << setw(14) << "Value ($)" << '|';
    cout << left << setw(13) << "Brand" << '|';
    cout << left << setw(17) << "Model" << '|';
    cout << left << setw(17) << "Operating System" << '|';
    cout << left << setw(17) << "Memory(GB)" << '|' << endl;
    cout << string(98, '-') << endl;
}

void Computer::ChangeField()
{
    cout << "Enter field to change" << endl;
    cout << "1.Name" << endl;
    cout << "2.Value ($)" << endl;
    cout << "3.Brand" << endl;
    cout << "4.Model" << endl;
    cout << "5.Operating System" << endl; 
    cout << "6.Memory(GB)" << endl;
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
        cout << "Enter Operating System: "; operatingSystem = InputStringwithINT();
        break;
    case 6:
        cout << "Enter memory(GB): "; memory = InputINT(100, 5000);
        break;
    }
}

string Computer::GetFileName()
{
    return "Computer's.txt";
}

ifstream& operator>>(ifstream& input, Computer& obj)
{
    input >> static_cast<Electronics&>(obj);
    if (obj.name == "") return input;
    string buf;
    int buf1;
    getline(input, obj.operatingSystem, '\t');


    input >> buf;
    buf1 = stoi(buf);
    obj.memory = buf1;
    input.ignore();
    return input;
}

ofstream& operator<<(ofstream& os, const Computer& obj) {
    os << static_cast<const Electronics&>(obj);
    os << obj.operatingSystem << "\t" << obj.memory << "\n";
    return os;
}
istream& operator>>(istream& input, Computer& obj)
{
    system("cls"); 
    cout << "Enter COMPUTER" << endl;
    input >> static_cast<Electronics&>(obj);
    cout << "Enter Operating System: "; obj.operatingSystem = InputStringwithINT();
    cout << "Enter memory(GB): "; obj.memory = InputINT(100, 5000);
    system("cls");
    return input;
}
ostream& operator<<(ostream& os, Computer obj)
{
    os << static_cast<const Electronics&>(obj);
    os << left << setw(17) << obj.operatingSystem << '|';
    os << left << setw(17) << obj.memory << '|' << endl;
    cout << string(98, '-') << endl;
    return os;

}