#include "Tourist.h"
Tourist::Tourist() : Person(), number_pasport("")
{
    initialized_Border_Crossing();
}

Tourist::Tourist(String number_pasport) : Person(), number_pasport(number_pasport)
{
    initialized_Border_Crossing();
}

Tourist::Tourist(String last_name, String first_name, int birth_year, String number_pasport)
    : Person(last_name, first_name, birth_year), number_pasport(number_pasport)
{
    initialized_Border_Crossing();
}

Tourist::~Tourist() {}

void Tourist::initialized_Border_Crossing()
{
    numBorderCrossing = 0;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        border_crossing[i].country = "NONE" ;  // Initializing
        border_crossing[i].date = "00.00.0000";  // Initializing
    }
}

void Tourist::display_Border_Crossing()
{
    cout << left << setw(79) << "|Border Crossings:" << '|' << endl;
    for (int i = 0; i < numBorderCrossing; i++)
    {
        cout << "|Date: " << setw(10) << border_crossing[i].date << ", Country: " << left << setw(51) << border_crossing[i].country << '|' << endl;
    }
}

void Tourist::enter_Border_Crossing()
{
    String country, data;
    cout << "Enter number of border crossing: " << endl;
    int num_border_crossing = InputINT(0, MAX_SIZE);

    for (int i = 0; i < num_border_crossing; i++)
    {
        cout << "Enter country: " << endl;
        country = InputString();
        cout << "Enter data: " << endl;
        data = InputStringwithINT();
        addBorderCrossing(data, country);
    }
}

String Tourist::get_pasport_number() const { return number_pasport; }

void Tourist::set_pasport_number(String number_pasport) { this->number_pasport = number_pasport; }

BorderCrossing* Tourist::getBorderCrossing()
{
    return border_crossing;
}

int Tourist::get_numBorderCrossing() const
{
    return numBorderCrossing;
}

void Tourist::addBorderCrossing(String data, String country)
{
    if (this->numBorderCrossing < MAX_SIZE) {
        this->border_crossing[this->numBorderCrossing] = { data, country };
        (this->numBorderCrossing)++;
    }
    else {
        cout << "The maximum size of the border crossing array has been reached." << endl;
    }
}

void Tourist::shapka()
{
    cout << string(80, '-') << endl;
    cout << "|  Last Name  |  First Name  | Birth Year  | Passport Number " << string(18, ' ') << '|' << endl;
    cout << string(80, '-') << endl;
}

void Tourist::ChangeField()
{
    int choise;
    String buf;
    cout << "1. Change Last Name" << endl;
    cout << "2. Change First Name" << endl;
    cout << "3. Change Birth Year" << endl;
    cout << "4. Change Pasport Number" << endl;
    cout << "5. Change Border Crossing" << endl;
    choise = InputINT(1, 5);
    switch (choise)
    {
    case 1:
        cout << "Enter Last Name:" << endl;
        last_name = InputString();
        break;
    case 2:
        cout << "Enter First Name:" << endl;
        first_name = InputString();
        break;
    case 3:
        cout << "Enter Birth Year:" << endl;
        birth_year = InputINT(1900, 2023);
        break;
    case 4:
        cout << "Enter Pasport Number:" << endl;
        number_pasport = InputStringwithINT();
        break;
    case 5:
        numBorderCrossing = 0;
        enter_Border_Crossing();
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
        break;
    }
}

string Tourist::GetFileName()
{
    return "Tourist's.txt";
}

string Tourist::GetFileNameBin()
{
    return "Tourist's.bin";
}

istream& operator>>(istream& is, Tourist& obj)
{
    is >> static_cast<Person&>(obj);
    cout << "Enter passport number: ";
    obj.number_pasport = InputStringwithINT();
    obj.enter_Border_Crossing();
    system("cls");
    return is;
}
ostream& operator<<(ostream& os, Tourist obj)
{
    os << static_cast<Person&>(obj);
    os << left << setw(35) << obj.number_pasport << '|' << endl;
    cout << string(80, '-') << endl;
    if (obj.numBorderCrossing > 0)
        obj.display_Border_Crossing();
    else
        cout << left << setw(79) << "|There isn't Border Crossing" << '|' << endl;
    cout << string(80, '-') << endl;
    cout << string(80, '-') << endl;

    return os;

}

ifstream& operator>>(ifstream& is, Tourist& obj)
{
    is >> static_cast<Person&>(obj);
    char c;
    string buf;
    obj.number_pasport = "";
    is.get(c);//чтобы убрать \t
    while (is.get(c) && c != '\n') {
        obj.number_pasport += c;
    }
    is >> buf;
    obj.numBorderCrossing = stoi(buf);
    is.get(c);//чтобы убрать \n
    if (obj.numBorderCrossing > 0)
    {
        for (int i = 0; i < obj.numBorderCrossing; i++)
        {
            obj.border_crossing[i].date = "";
            obj.border_crossing[i].country = "";
            while (is.get(c) && c != '\t') {
                obj.border_crossing[i].date += c;
            }
            while (is.get(c) && c != '\n') {
                obj.border_crossing[i].country += c;
            }

        }
    }
    return is;
}

ofstream& operator<<(ofstream& os, const Tourist& obj) {
    os << static_cast<const Person&>(obj);
    os << obj.number_pasport() << "\n";
    os << obj.numBorderCrossing << "\n";
    for (int i = 0; i < obj.numBorderCrossing; i++)
    {
        os << obj.border_crossing[i].date() << "\t";
        os << obj.border_crossing[i].country() << "\n";
    }

    return os;
}

fstream& operator>>(fstream& is, Tourist& obj)
{
    is >> static_cast<Person&>(obj);
    char* buf = new char[20];
    is.read(buf, 20);
    obj.number_pasport = buf;
    is.read(reinterpret_cast<char*>(&obj.numBorderCrossing), sizeof(obj.numBorderCrossing));
    for (int i = 0; i < obj.numBorderCrossing; i++)
    {
        is.read(buf, 20);
        obj.border_crossing[i].date = buf;
        is.read(buf, 20);
        obj.border_crossing[i].country = buf;
    }
    delete[] buf;
    return is;
}
fstream& operator<<(fstream& os, const Tourist& obj)
{
    os << static_cast<const Person&>(obj);
    char* buf = new char[20];
    buf = obj.number_pasport.convert20();
    os.write(buf, 20);
    os.write((char*)&obj.numBorderCrossing, sizeof(obj.numBorderCrossing));
    for (int i = 0; i < obj.numBorderCrossing; i++)
    {
        buf = obj.border_crossing[i].date.convert20();
        os.write(buf, 20);
        buf = obj.border_crossing[i].country.convert20();
        os.write(buf, 20);
    }
    delete[] buf;
    return os;
}
