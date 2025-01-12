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
        cout << "|Date: " << setw(10) <<  tax_payments[i].date << ", Amount: " << left << setw(52) << tax_payments[i].amount << '|' << endl;
    }
}
void  Entrepreneur::enterTax_Payments()
{
    int number_tax_payment;
    double amount;
    string data;
    cout << "Enter number of tax payment: " << endl;
    cin >> number_tax_payment;

    for (int i = 0; i < number_tax_payment; i++)
    {
        cout << "Enter data: " << endl;
        cin >> data;
        cout << "Enter amount: " << endl;
        cin >> amount;
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
istream& operator>>(istream& is, Entrepreneur& obj)
{
    is >> static_cast<Person&>(obj);
    cout << "Enter license number: "; is >> obj.license_number;
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