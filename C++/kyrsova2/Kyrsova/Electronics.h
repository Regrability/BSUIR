//Electronics.h
#pragma once
#include "Item.h"
class Electronics : public Item {
protected:
    string brand;
    string model;

public:
    Electronics();
    Electronics(string name, string category, double value, string brand, string model);
    string getBrand();
    string getModel();
    void setBrand(string brand);
    void setModel(string model);
    friend istream& operator>>(istream& input, Electronics& obj);
    friend ostream& operator<<(ostream& os, Electronics obj);
    friend ofstream& operator<<(ofstream& os, const Electronics& obj);
    friend ifstream& operator>>(ifstream& input, Electronics& obj);
};
