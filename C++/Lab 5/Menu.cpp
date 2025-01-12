#include "Menu.h"

template<typename T>
void Menu<T>::Run() {
    int choice;

    do {
        PrintMenu();
        choice = InputINT(1, 6);

        switch (choice) {
        case 1:
            PushItem();
            break;
        case 2:
            PopItem();
            break;
        case 3:
            PrintStack();
            break;
        case 4:
            ChangeFields();
            break;
        case 5:
            EmptyStack();
            break;
        case 6:
            cout << "Exiting the modul..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 6);
}
template<typename T>
void Menu<T>::PrintMenu() {
    cout << "\n----- Menu -----" << endl;
    cout << "1. Push item"       << endl;
    cout << "2. Pop item"        << endl;
    cout << "3. Print stack"     << endl;
    cout << "4. Change field"    << endl;
    cout << "5. Clear stack"     << endl;
    cout << "6. Exit modul"      << endl;
    cout << "----------------"   << endl;
}

template<typename T>
int Menu<T>::GetUserChoice() {
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

template<typename T>
void Menu<T>::PushItem() {
    T item;
    cout << "Enter the item to push: " << endl;
    cin >> item;
    stack.Push(item);
    cout << "Item pushed successfully." << endl;
}

template<typename T>
void Menu<T>::PopItem() {
    system("cls");
    if (stack.Count() == 0) {
        cout << "Stack is empty. Cannot pop item." << endl;
    }
    else {
        T item = stack.Pop();
        cout << "Popped item:" << endl;
        item.shapka();
        cout << item << endl;
    }
}

template<typename T>
void Menu<T>::PrintStack() {
    system("cls");
    stack.Print();
}

template<typename T>
void Menu<T>::ChangeFields() {
    system("cls");
    if (stack.Count() == 0) {
        cout << "Stack is empty. Cannot change item." << endl;
    }
    else {
        stack.Print();
        T item = stack.Pop();
        item.ChangeField();
        stack.Push(item);
    }
}
template<typename T>
void Menu<T>::EmptyStack()
{
    stack.Empty();
    system("cls");
    cout << "Stack is Empty" << endl;
}
