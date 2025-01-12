#pragma once
#include "Person.h"

struct TaxPayment
{
    string date;
    double amount{};
};
class Entrepreneur :virtual public Person
{
protected:
    string license_number;
    TaxPayment tax_payments[MAX_SIZE];
    int numPayments;

public:
    Entrepreneur();
    Entrepreneur(string license_number);
    Entrepreneur(string last_name, string first_name, int birth_year, string license_number);
    ~Entrepreneur();
    void initialized_Tax_Paiment();
    void displayTax_Payments();
    void enterTax_Payments();
    string get_license_number() const;
    void set_license_number(string license_number);
    TaxPayment* getPayments();
    int getNumPayments() const;
    void addPayment(string date, double amount);
    void shapka() override;
    void ChangeField() override;
    friend istream& operator>>(istream& is, Entrepreneur& obj);
    friend ostream& operator<<(ostream& os, Entrepreneur obj);
};
