#pragma once
#include "Entrepreneur.h"
#include "Tourist.h"
class Business : public Tourist, public Entrepreneur
{
private:
    string address_list[MAX_SIZE];
    int numAddresses;
    int size_of_mass_object;

public:
    Business(string last_name, string first_name, int birth_year, string number_pasport, string license_number);
    Business();
    ~Business();
    void initialized_Adrees_List();
    void addAddress(string address);
    void displayAddressList();
    void enter_ressList();
    string* get_address_list();
    int get_numAddresses();
    void shapka();
    friend istream& operator>>(istream& input, Business& obj);
    friend ostream& operator<<(ostream& os, Business obj);
};

