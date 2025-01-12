#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip> // Для использования std::setw
using namespace std;


void PrintFirstMenu() {
    cout << "--------- Menu ---------" << endl;
    cout << "1. Work with INT Stack" << endl;
    cout << "2. Work with CHAR Stack" << endl;
    cout << "3. End program" << endl;
    cout << "------------------------" << endl;
}
int GetFirstUserChoice() {
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}
