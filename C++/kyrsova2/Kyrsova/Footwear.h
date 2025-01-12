//Footwear.h
#pragma once
#include "Clothing.h"
class Footwear : public Clothing {
private:
    string type;
    string color;

public:
    Footwear();
    Footwear(string name, string category, double value, string size, string material, string type, string color);
    string getType();
    string getColor();

    void setType(string type);
    void setColor(string color);

    void Shapka() override;
    void ChangeField() override;
    string GetFileName() override;
    friend ifstream& operator>>(ifstream& input, Footwear& obj);
    friend ofstream& operator<<(ofstream& os, const Footwear& obj);
    friend istream& operator>>(istream& input, Footwear & obj);
    friend ostream& operator<<(ostream& os, Footwear obj);
};
