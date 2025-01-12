#include "Tourist.h"
Tourist::Tourist() : Person(), number_pasport("")
{
    initialized_Border_Crossing();
}

Tourist::Tourist(string number_pasport) : Person(), number_pasport(number_pasport)
{
    initialized_Border_Crossing();
}

Tourist::Tourist(string last_name, string first_name, int birth_year, string number_pasport)
    : Person(last_name, first_name, birth_year), number_pasport(number_pasport)
{
    initialized_Border_Crossing();
}
Tourist::~Tourist() {};

void Tourist::initialized_Border_Crossing()
{
    numBorderCrossing = 0;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        border_crossing[i] = { "00.00.0000", "NONE" };  // Инициализация 
    }
}

void Tourist::display_Border_Crossing()
{
    cout << left << setw(79) << "|Border Crossings:" << '|' << endl;
    for (int i = 0; i < numBorderCrossing; i++)
    {
        cout << "|Date: " << setw(10) << border_crossing[i].date << ", Country: " << left << setw(51) << border_crossing[i].country <<  '|' << endl;
    }

}

void Tourist::enter_Border_Crossing()
{
    int number_border_crossing;
    string country, data;
    cout << "Enter number of border crossing: " << endl;
    cin >> number_border_crossing;

    for (int i = 0; i < number_border_crossing; i++)
    {
        cout << "Enter country: " << endl;
        cin >> country;
        cout << "Enter data: " << endl;
        cin >> data;
        addBorderCrossing(data, country);
    }
}


string Tourist::get_pasport_number() const { return number_pasport; }

void Tourist::set_pasport_number(string number_pasport) { this->number_pasport = number_pasport; }

BorderCrossing* Tourist::getBorderCrossing()
{
    return border_crossing;
}


int Tourist::get_numBorderCrossing() const
{
    return numBorderCrossing;
}

void Tourist::addBorderCrossing(string data, string country)
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
    cout << "|  Last Name  |  First Name  | Birth Year  | Passport Number "<< string(18, ' ') << '|' << endl;
    cout << string(80, '-') << endl;
}
istream& operator>>(istream& is, Tourist& obj)
{
    is >> static_cast<Person&>(obj);
    cout << "Enter passport number: "; is >> obj.number_pasport;
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

