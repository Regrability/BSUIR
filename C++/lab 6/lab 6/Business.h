#pragma once

#include "Entrepreneur.h"
#include "Tourist.h"

class Business : public Tourist, public Entrepreneur
{
private:
    String address_list[MAX_SIZE];
    int numAddresses;

public:
    Business(String last_name, String first_name, int birth_year, String number_pasport, String license_number);
    Business();
    ~Business();
    void initialized_Adrees_List();
    void addAddress(String address);
    void displayAddressList();
    void enter_ressList();
    String* get_address_list();
    int get_numAddresses();
    void shapka() override;
    void ChangeField() override;
    string GetFileName() override;
    string GetFileNameBin() override; 
    friend istream& operator>>(istream& input, Business& obj);
    friend ostream& operator<<(ostream& os, Business obj);
    friend ifstream& operator>>(ifstream& is, Business& obj);
    friend ofstream& operator<<(ofstream& os, const Business& obj);
    friend fstream& operator>>(fstream& is, Business& obj);
    friend fstream& operator<<(fstream& os, const Business& obj);
};