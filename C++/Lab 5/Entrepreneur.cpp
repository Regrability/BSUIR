#include "Entrepreneur.h"
Entrepreneur::Entrepreneur() : Person(), license_number("NONE")
{
    initialized_Tax_Paiment();
}
Entrepreneur::Entrepreneur(string license_number) : Person(), license_number(license_number) 
{
    initialized_Tax_Paiment();
}
Entrepreneur::Entrepreneur(string last_name, string first_name, int birth_year, string license_number)
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
        tax_payments[i] = { "00.00.0000", 0.0 };  // Инициализация amount и date
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
    string data;
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
string Entrepreneur::get_license_number() const { return license_number; }
void Entrepreneur::set_license_number(string license_number) { this->license_number = license_number; }
// Метод получения платежей
TaxPayment* Entrepreneur::getPayments()
{
    return tax_payments;
}
// Метод получения количества платежей
int  Entrepreneur::getNumPayments() const {
    return numPayments;
}
// Метод добавления платежа
void Entrepreneur::addPayment(string date, double amount) {
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
            int choise;
            cout << "1. Change Last Name" << endl;
            cout << "2. Change First Name" << endl;
            cout << "3. Change Birth Year" << endl;
            cout << "4. Change License Number" << endl;
            cout << "5. Change Tax Payments" << endl;
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
istream& operator>>(istream& is, Entrepreneur& obj)
{
    is >> static_cast<Person&>(obj);
    cout << "Enter license number: "; obj.license_number = InputStringwithINT();
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