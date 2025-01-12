#pragma once
#include "Person.h"

struct BorderCrossing
{
    string date;
    string country;
};

class Tourist : virtual public Person
{
protected:
    string number_pasport;
    BorderCrossing border_crossing[MAX_SIZE];
    int numBorderCrossing;

public:
    Tourist();
    Tourist(string number_pasport);
    Tourist(string last_name, string first_name, int birth_year, string number_pasport);
    ~Tourist();
    void initialized_Border_Crossing();
    void display_Border_Crossing();
    void enter_Border_Crossing();
    string get_pasport_number() const;
    void set_pasport_number(string number_pasport);
    BorderCrossing* getBorderCrossing();
    int get_numBorderCrossing() const;
    void addBorderCrossing(string data, string country);
    void shapka();
    friend istream& operator>>(istream& is, Tourist& obj);
    friend ostream& operator<<(ostream& os, Tourist obj);
};