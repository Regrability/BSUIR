#include "Business.h"
#include "Menu.cpp"
#include "Mytools.h"
int main() { 
    Menu<Entrepreneur> entrepreneur;
    Menu<Tourist> tourist;
    Menu<Business> business;
    int choice;
    do {
        system("cls");
        PrintFirstMenu();
        choice = InputINT(1, 4);
        system("cls");
        switch (choice) {
        case 1:
            entrepreneur.Run();
            break;
        case 2:
            tourist.Run();
            break;
        case 3:
            business.Run();
            break;
        case 4:
            cout << "Exiting the program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 4);
    return 0;
}