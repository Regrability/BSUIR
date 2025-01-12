#pragma once
#include <iostream>
using namespace std;

void PrintFirstMenu() {
    cout << "--------- Menu ---------" << endl;
    cout << "1. Work with Entrepreneur" << endl;
    cout << "2. Work with Tourist" << endl;
    cout << "3. Work with Business" << endl;
    cout << "4. End program" << endl;
    cout << "------------------------" << endl;
}
int GetFirstUserChoice() {
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}