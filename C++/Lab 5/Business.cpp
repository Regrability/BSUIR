#include "Business.h"
Business::Business(string last_name, string first_name, int birth_year, string number_pasport, string license_number)
    : Person(last_name, first_name, birth_year),
    Tourist(number_pasport),
    Entrepreneur(license_number)
{
    initialized_Adrees_List();
}
Business::Business()
    : Person(),
    Tourist(),
    Entrepreneur()
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

void Business::addAddress(string address)
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
    string address;
    cout << "How many you have purchase: "; num = InputINT(0, MAX_SIZE);
    for (int i = 0; i < num; i++)
    {
        cout << "Enter number of " << i + 1 << " purchase: "; address = InputStringwithINT();
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
string* Business::get_address_list()
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
    int choise;
    cout << "1. Change Last Name" << endl;
    cout << "2. Change First Name" << endl;
    cout << "3. Change Birth Year" << endl;
    cout << "4. Change Pasport Number" << endl;
    cout << "5. Change License Number" << endl;
    cout << "6. Change Border Crossing" << endl;
    cout << "7. Change Tax Payments" << endl;
    cout << "8. Change Adresses of Purchase" << endl;
    choise = InputINT(1, 8);
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
istream& operator>>(istream& is, Business& obj)
{
    is >> static_cast<Person&>(obj);
    cout << "Enter passport number: "; obj.number_pasport = InputStringwithINT();
    cout << "Enter license number: "; obj.license_number = InputStringwithINT();
    obj.enter_Border_Crossing();
    obj.enterTax_Payments();
    obj.enter_ressList();
    system("cls");
    return is;
}
ostream& operator<<(ostream& os, Business obj)
{
    // Вызов оператора << для класса Person
    os << static_cast<const Person&>(obj);
    os << left << setw(17) << obj.number_pasport << '|';
    os << left << setw(17) << obj.license_number << '|' << endl;
    cout << string(80, '-') << endl;
    if (obj.numBorderCrossing > 0)
        obj.display_Border_Crossing();
    else
        cout << left << setw(79) << "|There isn't Border Crossing" << '|' << endl;
    cout << string(80, '-') << endl;
    if (obj.numPayments > 0)
        obj.displayTax_Payments();
    else
        cout << left << setw(79) << "|There isn't Tax Payments" << '|' << endl;
    cout << string(80, '-') << endl;
    if (obj.numAddresses > 0)
        obj.displayAddressList();
    else
        cout << left << setw(79) << "|There isn't Addresses of Purchase" << '|' << endl;
    cout << string(80, '-') << endl;
    cout << string(80, '-') << endl;

    return os;

}