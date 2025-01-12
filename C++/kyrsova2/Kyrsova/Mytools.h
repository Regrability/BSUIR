//Mytools.h
#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip> // Для использования std::setw
#include <thread>
#include <chrono>
using namespace std;


void PrintFirstMenu() {
    cout << "--------- Menu ---------" << endl;
    cout << "1. Work with Computer" << endl;
    cout << "2. Work with Telephone" << endl;
    cout << "3. Work with Footwear" << endl;
    cout << "4. Work with Accessories" << endl;
    cout << "5. Step back" << endl;
    cout << "6. End program" << endl;
    cout << "------------------------" << endl;
}