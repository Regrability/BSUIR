#pragma once
#include "Person.h"

struct TaxPayment
{
    String date;
    double amount{};
};

class Entrepreneur : virtual public Person
{
protected:
    String license_number;
    TaxPayment tax_payments[MAX_SIZE];
    int numPayments;

public:
    Entrepreneur();
    Entrepreneur(String license_number);
    Entrepreneur(String last_name, String first_name, int birth_year, String license_number);
    ~Entrepreneur();
    void initialized_Tax_Paiment();
    void displayTax_Payments();
    void enterTax_Payments();
    String get_license_number() const;
    void set_license_number(String license_number);
    TaxPayment* getPayments();
    int getNumPayments() const;
    void addPayment(String date, double amount);
    void shapka() override;
    void ChangeField() override;
    string GetFileName() override;
    string GetFileNameBin() override;
    friend istream& operator>>(istream& is, Entrepreneur& obj);
    friend ostream& operator<<(ostream& os, Entrepreneur obj);
    friend ifstream& operator>>(ifstream& is, Entrepreneur& obj);
    friend ofstream& operator<<(ofstream& os, const Entrepreneur& obj);
    friend fstream& operator>>(fstream& is, Entrepreneur& obj);
    friend fstream& operator<<(fstream& os, const Entrepreneur& obj);
};