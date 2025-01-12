//Clothing.h
#pragma once
#include "Item.h"
class Clothing : public Item {
protected:
    string size;
    string material;

public:
    Clothing();
    Clothing(string name, string category, double value, string size, string material);
    string getSize();
    string getMaterial();
    void setSize(string size);
    void setMaterial(string material);
    friend ifstream& operator>>(ifstream& input, Clothing& obj);
    friend ofstream& operator<<(ofstream& os, const Clothing& obj);
    friend istream& operator>>(istream& input, Clothing& obj);
    friend ostream& operator<<(ostream& os, Clothing obj);
};
