#include "Entrepreneur.h"

Entrepreneur::Entrepreneur() : Person(), license_number("NONE")
{
    initialized_Tax_Paiment();
}

Entrepreneur::Entrepreneur(String license_number) : Person(), license_number(license_number)
{
    initialized_Tax_Paiment();
}

Entrepreneur::Entrepreneur(String last_name, String first_name, int birth_year, String license_number)
    : Person(last_name, first_name, birth_year), license_number(license_number)
{
    initialized_Tax_Paiment();
}

Entrepreneur::~Entrepreneur() {};

void  Entrepreneur::initialized_Tax_Paiment()
{
    numPayments = 0;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        tax_payments[i].date =  "00.00.0000";  // Initializing amount and date
        tax_payments[i].amount = 0;  // Initializing amount and date
    }
}

void  Entrepreneur::displayTax_Payments()
{
    cout << left << setw(79) << "|Tax Payments:" << '|' << endl;
    for (int i = 0; i < numPayments; i++)
    {
        cout << "|Date: " << setw(10) << tax_payments[i].date << ", Amount: " << left << setw(52) << tax_payments[i].amount << '|' << endl;
    }
}

void  Entrepreneur::enterTax_Payments()
{
    int number_tax_payment;
    double amount;
    String data;
    cout << "Enter number of tax payment: " << endl;
    number_tax_payment = InputINT(0, MAX_SIZE);

    for (int i = 0; i < number_tax_payment; i++)
    {
        cout << "Enter data: " << endl;
        data = InputStringwithINT();
        cout << "Enter amount: " << endl;
        amount = InputDouble(0, 10000);
        addPayment(data, amount);
    }
}

String Entrepreneur::get_license_number() const { return license_number; }

void Entrepreneur::set_license_number(String license_number) { this->license_number = license_number; }

// Get payments method
TaxPayment* Entrepreneur::getPayments() 
{
    return this->tax_payments;
}

// Get number of payments method
int  Entrepreneur::getNumPayments() const {
    return numPayments;
}

// Add payment method
void Entrepreneur::addPayment(String date, double amount) {
    if (this->numPayments < MAX_SIZE) {
        this->tax_payments[this->numPayments] = { date, amount };
        (this->numPayments)++;
    }
    else {
        cout << "The maximum size of the payment array has been reached." << endl;
    }
}

void Entrepreneur::shapka()
{
    cout << string(80, '-') << endl;
    cout << "|  Last Name  |  First Name  | Birth Year  | License Number " << string(19, ' ') << '|' << endl;
    cout << string(80, '-') << endl;
}

void Entrepreneur::ChangeField()
{
    int choice;
    cout << "1. Change Last Name" << endl;
    cout << "2. Change First Name" << endl;
    cout << "3. Change Birth Year" << endl;
    cout << "4. Change License Number" << endl;
    cout << "5. Change Tax Payments" << endl;
    choice = InputINT(1, 5);
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
        cout << "Enter License Number:" << endl;
        license_number = InputStringwithINT();
        break;
    case 5:
        numPayments = 0;
        enterTax_Payments();
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
        break;
    }
}

string Entrepreneur::GetFileName() 
{
    return "Entrepreneur's.txt";
}

string Entrepreneur::GetFileNameBin()
{
    return "Entrepreneur's.bin";
}

istream& operator>>(istream& is, Entrepreneur& obj)
{
    is >> static_cast<Person&>(obj);
    cout << "Enter license number: ";
    obj.license_number = InputStringwithINT();
    obj.enterTax_Payments();
    system("cls");
    return is;
}

ostream& operator<<(ostream& os, Entrepreneur obj)
{
    os << static_cast<Person&>(obj);
    os << left << setw(35) << obj.license_number << '|' << endl;
    cout << string(80, '-') << endl;
    if (obj.numPayments > 0)
        obj.displayTax_Payments();
    else
        cout << left << setw(79) << "|There isn't Tax Payments" << '|' << endl;
    cout << string(80, '-') << endl;
    cout << string(80, '-') << endl;

    return os;
}

ifstream& operator>>(ifstream& is, Entrepreneur& obj)
{
    is >> static_cast<Person&>(obj);
    string buf;
    char c;
    obj.license_number = "";
    is.get(c);//чтобы убрать \t
    while (is.get(c) && c != '\n') {
        obj.license_number += c;
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
    return is;
}

ofstream& operator<<(ofstream& os, const Entrepreneur& obj) {
    os << static_cast<const Person&>(obj);
    os << obj.license_number() << "\n";
    os << obj.numPayments << "\n";
    for (int i = 0; i < obj.numPayments; i++)
    {
        os << obj.tax_payments[i].date() << "\t";
        os << obj.tax_payments[i].amount << "\n";
    }

    return os;
}

fstream& operator>>(fstream& is, Entrepreneur& obj)
{
    is >> static_cast<Person&>(obj);
    char* buf = new char[20];
    is.read(buf, 20);
    obj.license_number = buf;
    is.read(reinterpret_cast<char*>(&obj.numPayments), sizeof(obj.numPayments));
    for (int i = 0; i < obj.numPayments; i++)
    {
        is.read(buf, 20);
        obj.tax_payments[i].date = buf;
        is.read(reinterpret_cast<char*>(&obj.tax_payments[i].amount), sizeof(obj.tax_payments[i].amount));
    }
    delete[] buf;
    return is;
}
fstream& operator<<(fstream& os, const Entrepreneur& obj)
{
    os << static_cast<const Person&>(obj);
    char* buf = new char[20];
    buf = obj.license_number.convert20();
    os.write(buf, 20);
    os.write((char*)&obj.numPayments, sizeof(obj.numPayments));
    for (int i = 0; i < obj.numPayments; i++)
    {
        buf = obj.tax_payments[i].date.convert20();
        os.write(buf, 20); 
        os.write((char*)&obj.tax_payments[i].amount, sizeof(obj.tax_payments[i].amount));
    }
    delete[] buf;

    return os;
}