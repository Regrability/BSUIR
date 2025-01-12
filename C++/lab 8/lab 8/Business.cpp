#include "Business.h"

Business::Business(String last_name, String first_name, int birth_year, String number_pasport, String license_number)
    : Person(last_name, first_name, birth_year),
    Tourist(number_pasport),
    Entrepreneur(license_number)
{
    initialized_Adrees_List();
}

Business::Business() : Person(), Tourist(), Entrepreneur()
{
    initialized_Adrees_List();
}

Business::~Business() {}

void Business::initialized_Adrees_List()
{
    numAddresses = 0;
    for (int i = 0; i < MAX_SIZE; i++)
        address_list[i] = "NONE";
}

void Business::addAddress(String address)
{
    if (numAddresses < MAX_SIZE)
    {
        address_list[numAddresses] = address;
        numAddresses++;
    }
    else
    {
        cout << "The maximum number of addresses has been reached." << endl;
    }
}

void Business::enter_ressList()
{
    int num;
    String address;
    cout << "How many purchases have you made? ";
    num = InputINT(0, MAX_SIZE);
    for (int i = 0; i < num; i++)
    {
        cout << "Enter address of purchase " << i + 1 << ": ";
        address = InputStringwithINT();
        addAddress(address);
    }
}

void Business::displayAddressList()
{
    cout << left << setw(79) << "|Address List:" << '|' << endl;
    for (int i = 0; i < numAddresses; i++)
    {
        cout << '|' << left << setw(78) << address_list[i] << '|' << endl;
    }
}

String* Business::get_address_list()
{
    return this->address_list;
}

int Business::get_numAddresses()
{
    return numAddresses;
}

void Business::shapka()
{
    cout << string(80, '-') << endl;
    cout << "|  Last Name  |  First Name  | Birth Year  | Passport Number | License Number  | " << endl;
    cout << string(80, '-') << endl;
}

void Business::ChangeField()
{
    int choice;
    cout << "1. Change Last Name" << endl;
    cout << "2. Change First Name" << endl;
    cout << "3. Change Birth Year" << endl;
    cout << "4. Change Passport Number" << endl;
    cout << "5. Change License Number" << endl;
    cout << "6. Change Border Crossing" << endl;
    cout << "7. Change Tax Payments" << endl;
    cout << "8. Change Addresses of Purchase" << endl;
    choice = InputINT(1, 8);
    switch (choice)
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
        cout << "Enter Passport Number:" << endl;
        number_pasport = InputStringwithINT();
        break;
    case 5:
        cout << "Enter License Number:" << endl;
        license_number = InputStringwithINT();
        break;
    case 6:
        numBorderCrossing = 0;
        enter_Border_Crossing();
        break;
    case 7:
        numPayments = 0;
        enterTax_Payments();
        break;
    case 8:
        numAddresses = 0;
        enter_ressList();
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
        break;
    }
}

string Business::GetFileName()
{
    return "Business's.txt";
}

string Business::GetFileNameBin()
{
    return "Business's.bin";
}

istream& operator>>(istream& is, Business& obj)
{
    is >> static_cast<Person&>(obj);
    cout << "Enter passport number: ";
    obj.number_pasport = InputStringwithINT();
    cout << "Enter license number: ";
    obj.license_number = InputStringwithINT();
    obj.enter_Border_Crossing();
    obj.enterTax_Payments();
    obj.enter_ressList();
    system("cls");
    return is;
}

ostream& operator<<(ostream& os, Business obj)
{
    os << static_cast<const Person&>(obj);
    os << left << setw(17) << obj.number_pasport << '|';
    os << left << setw(17) << obj.license_number << '|' << endl;
    cout << string(80, '-') << endl;
    if (obj.numBorderCrossing > 0)
        obj.display_Border_Crossing();
    else
        cout << left << setw(79) << "|There areno Border Crossings" << '|' << endl;
    cout << string(80, '-') << endl;
    if (obj.numPayments > 0)
        obj.displayTax_Payments();
    else
        cout << left << setw(79) << "|There are no Tax Payments" << '|' << endl;
    cout << string(80, '-') << endl;
    if (obj.numAddresses > 0)
        obj.displayAddressList();
    else
        cout << left << setw(79) << "|There are no Addresses of Purchase" << '|' << endl;
    cout << string(80, '-') << endl;
    cout << string(80, '-') << endl;

    return os;
}

ifstream& operator>>(ifstream& is, Business& obj)
{
    is >> static_cast<Person&>(obj);
    char c;
    string buf;
    obj.number_pasport = "";
    is.get(c);//чтобы убрать \t
    while (is.get(c) && c != '\t') {
        obj.number_pasport += c;
    }
    obj.license_number = "";
    while (is.get(c) && c != '\n') {
        obj.license_number += c;
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
    is >> buf;
    obj.numPayments = stoi(buf);
    is.get(c);//чтобы убрать \n
    if (obj.numPayments > 0)
    {
        for (int i = 0; i < obj.numPayments; i++)
        {
            obj.tax_payments[i].date = "";
            while (is.get(c) && c != '\t') {
                obj.tax_payments[i].date += c;
            }
            is >> buf;
            locale::global(locale("C"));
            obj.tax_payments[i].amount = stod(buf);
            is.get(c);//чтобы убрать \n
        }
    }
    is >> buf;
    obj.numAddresses = stoi(buf);
    is.get(c);//чтобы убрать \n
    for (int i = 0; i < obj.numAddresses; i++)
    {
        obj.address_list[i] = "";
        while (is.get(c) && c != '\n') {
            obj.address_list[i] += c;
        }
    }
    return is;
}

ofstream& operator<<(ofstream& os, const Business& obj) {
    os << static_cast<const Person&>(obj);
    os << obj.number_pasport() << "\t";
    os << obj.license_number() << "\n";
    os << obj.numBorderCrossing << "\n";
    for (int i = 0; i < obj.numBorderCrossing; i++)
    {
        os << obj.border_crossing[i].date() << "\t";
        os << obj.border_crossing[i].country() << "\n";
    }
    os << obj.numPayments << "\n";
    for (int i = 0; i < obj.numPayments; i++)
    {
        os << obj.tax_payments[i].date() << "\t";
        os << obj.tax_payments[i].amount << "\n";
    }
    os << obj.numAddresses << "\n";
    for (int i = 0; i < obj.numAddresses; i++)
    {
        os << obj.address_list[i]() << "\n";
    }

    return os;
}

fstream& operator>>(fstream& is, Business& obj)
{
    is >> static_cast<Entrepreneur&>(obj);
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
    is.read(reinterpret_cast<char*>(&obj.numAddresses), sizeof(obj.numAddresses));
    for (int i = 0; i < obj.numAddresses; i++)
    {
        is.read(buf, 20);
        obj.address_list[i] = buf;
    }
    delete[] buf;
    return is;
}
fstream& operator<<(fstream& os, const Business& obj)
{
    os << static_cast<const Entrepreneur&>(obj);
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
    os.write((char*)&obj.numAddresses, sizeof(obj.numAddresses));
    for (int i = 0; i < obj.numAddresses; i++)
    {
        buf = obj.address_list[i].convert20();
        os.write(buf, 20);
    }
    delete[] buf;
    return os;
}