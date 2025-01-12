#include "Menu.cpp"
#include "MyTools.h"
int main()
{
    int choice;
    Menu<int> menu1;
    Menu<char> menu2;
    Menu<float> menu3;
    do {
        system("cls");
        PrintFirstMenu();
        choice = GetFirstUserChoice();
        system("cls");
        switch (choice) {
        case 1:
            menu1.Run();
            break;
        case 2:
            menu2.Run();
            break;
        case 3:
            cout << "Exiting the program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 3);
    return 0;
}