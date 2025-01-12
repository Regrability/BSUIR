//Telephone.h
#pragma once
#include "Electronics.h"
class Telephone : public Electronics {
private:
    string network;
    double screenSize;

public:
    Telephone();
    Telephone(string name, string category, double value, string brand, string model, string network, double screenSize);
    string getNetwork();
    double getScreenSize();
    void setNetwork(string network);
    void setScreenSize(double screenSize);
    void Shapka()  override;
    void ChangeField() override;
    string GetFileName() override;
    friend ifstream& operator>>(ifstream& input, Telephone& obj);
    friend ofstream& operator<<(ofstream& os, const Telephone& obj);
    friend istream& operator>>(istream& input, Telephone& obj);
    friend ostream& operator<<(ostream& os, Telephone obj);
};