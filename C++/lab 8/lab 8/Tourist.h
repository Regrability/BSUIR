#pragma once

#include "Person.h"

struct BorderCrossing
{
    String date;
    String country;
};

class Tourist : virtual public Person
{
protected:
    String number_pasport;
    BorderCrossing border_crossing[MAX_SIZE];
    int numBorderCrossing;

public:
    Tourist();
    Tourist(String number_pasport);
    Tourist(String last_name, String first_name, int birth_year, String number_pasport);
    ~Tourist();
    void initialized_Border_Crossing();
    void display_Border_Crossing();
    void enter_Border_Crossing();
    String get_pasport_number() const;
    void set_pasport_number(String number_pasport);
    BorderCrossing* getBorderCrossing();
    int get_numBorderCrossing() const;
    void addBorderCrossing(String data, String country);
    void shapka() override;
    void ChangeField() override;
    string GetFileName() override;
    string GetFileNameBin() override; 
    friend istream& operator>>(istream& is, Tourist& obj);
    friend ostream& operator<<(ostream& os, Tourist obj);
    friend ifstream& operator>>(ifstream& is, Tourist& obj);
    friend ofstream& operator<<(ofstream& os, const Tourist& obj);
    friend fstream& operator>>(fstream& is, Tourist& obj);
    friend fstream& operator<<(fstream& os, const Tourist& obj);
};