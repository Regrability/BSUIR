//Item.h
#pragma once
#include "MyVvod.h"
using namespace std;
class Item {
protected:
    string name;
    string category;
    double value;

public:
    Item();
    Item(string name, string category, double value);
    string getName();
    string getCategory();
    double getValue();
    void setName(string name);
    void setCategory(string category);
    void setValue(double value);
    void virtual Shapka(){};
    void virtual ChangeField(){};
    string virtual GetFileName();
    friend istream& operator>>(istream& input, Item& obj);
    friend ostream& operator<<(ostream& os, Item obj);
    friend ofstream& operator<<(ofstream& os, const Item& obj);
    friend ifstream& operator>>(ifstream& input, Item& obj);
};
