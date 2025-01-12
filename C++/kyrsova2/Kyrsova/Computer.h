//Computer.h
#pragma once
#include "Electronics.h"
class Computer : public Electronics {
private:
    string operatingSystem;
    int memory;

public:
    Computer();
    Computer(string name, string category, double value, string brand, string model, string operatingSystem, int memory);
    string getOperatingSystem();
    int getMemory();
    void setOperatingSystem(string operatingSystem);
    void setMemory(int memory);
    void Shapka() override;
    void ChangeField() override;
    string GetFileName() override;
    friend ifstream& operator>>(ifstream& input, Computer& obj);
    friend ofstream& operator<<(ofstream& os, const Computer& obj);
    friend istream& operator>>(istream& input, Computer& obj);
    friend ostream& operator<<(ostream& os, Computer obj);
};
