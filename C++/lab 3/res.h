#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip> // Для использования std::setw
using namespace std;

void MenuBusiness(){
    system("cls");
    cout << "1. Change Last Name" << endl;
    cout << "2. Change First Name" << endl; 
    cout << "3. Change Birth Year" << endl; 
    cout << "4. Change Pasport Number" << endl;
    cout << "5. Change License Number" << endl; 
    cout << "6. Change Border Crossing" << endl;
    cout << "7. Change Tax Payments" << endl;
    cout << "8. Change Adresses of Purchase" << endl;
}
void ChangeArray(Business* arr, int size) {
    int choise, num;
    bool flag;
    string buf;
    int buf_int;
    do {
        system("cls");
        arr[0].shapka();
        for (int i = 0; i < size; i++)
        {
            cout << arr[i];
        }
        cout << "Do you want to change something?" << endl;
        cout << "1.Yes" << endl;
        cout << "2.No" << endl;
        cin >> choise;
        flag = (choise == 1) ? true : false;
        system("cls");
        if (flag)
        {
        cout << "Enter number of element, that you want to channge" << endl;
        cin >> num;
        num--;
        MenuBusiness();
        cin >> choise;
        system("cls");
        switch (choise)
        {
        case 1:
            cout << "Enter Last Name:" << endl;
            cin.ignore(); // Добавлено для очистки символа новой строки из буфера ввода
            getline(cin, buf);
            arr[num].set_last_name(buf);
            system("cls");
            break;
        case 2:
            cout << "Enter First Name:" << endl;
            cin.ignore(); // Добавлено для очистки символа новой строки из буфера ввода
            getline(cin, buf);
            arr[num].set_first_name(buf);
            system("cls");
            break;
        case 3:
            cout << "Enter Birth Year:" << endl;
            cin >> buf_int;
            arr[num].set_birth_year(buf_int);
            system("cls");
            break;
        case 4:
            cout << "Enter Pasport Number:" << endl;
            cin.ignore(); // Добавлено для очистки символа новой строки из буфера ввода
            getline(cin, buf);
            arr[num].set_pasport_number(buf);
            system("cls");
            break;
        case 5:
            cout << "Enter License Number:" << endl;
            cin.ignore(); // Добавлено для очистки символа новой строки из буфера ввода
            getline(cin, buf);
            arr[num].set_license_number(buf);
            system("cls");
            break;
        case 6:
            arr[num].enter_Border_Crossing();
            break;
        case 7:
            arr[num].enterTax_Payments();
            break;
        case 8:
            arr[num].enter_ressList();
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;

        }
        }
    } while (flag);
}