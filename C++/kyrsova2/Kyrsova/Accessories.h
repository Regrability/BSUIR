//Accessories.h
#pragma once
#include "Clothing.h"
class Accessories : public Clothing {
private:
    string style;
    string brand;

public:
    Accessories();
    Accessories(string name, string category, double value, string size, string material, string style, string brand);
    string getStyle();
    string getBrand();

    void setStyle(string style);
    void setBrand(string brand);
    void Shapka()  override;
    void ChangeField() override;
    string GetFileName() override;
    friend ifstream& operator>>(ifstream& input, Accessories& obj);
    friend ofstream& operator<<(ofstream& os, const Accessories& obj);
    friend istream& operator>>(istream& input, Accessories& obj);
    friend ostream& operator<<(ostream& os, Accessories obj);
};