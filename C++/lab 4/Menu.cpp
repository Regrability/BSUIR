#include "Menu.h"

template<typename T>
void Menu<T>::Run() {
    int choice;

    do {
        PrintMenu();
        choice = GetUserChoice();

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
            LessElement();
            break;
        case 5:
            LargeElement();
            break;
        case 6:
            Sum();
            break;
        case 7:
            DeleteAll();
            break;
        case 8:
            cout << "Exiting the work witch modul..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 8);
}





template<typename T>
void Menu<T>::PrintMenu() {
    cout << "\n----- Menu -----" << endl;
    cout << "1. Push item" << endl;
    cout << "2. Pop item" << endl;
    cout << "3. Print stack" << endl;
    cout << "4. Less elements" << endl;
    cout << "5. Large elemets" << endl;
    cout << "6. Sum of elements" << endl;
    cout << "7. Delete Stack" << endl;
    cout << "8. Exit modul" << endl;
    cout << "----------------" << endl;
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
    cout << "Enter the item to push: ";
    cin >> item;
    stack.Push(item);
    cout << "Item pushed successfully." << endl;
}

template<typename T>
void Menu<T>::PopItem() {
    if (stack.Count() == 0) {
        cout << "Stack is empty. Cannot pop item." << endl;
    }
    else {
        T item = stack.Pop();
        cout << "Popped item: " << item << endl;
    }
}

template<typename T>
void Menu<T>::PrintStack() {
    stack.Print();
}

template<typename T>
void Menu<T>::LessElement() {
    T n;
    cout << "Enter elements: ";
    cin >> n;
    stack.Less_elements(n);
}

template<typename T>
void Menu<T>::LargeElement() {
    T n;
    cout << "Enter elements: ";
    cin >> n;
    stack.Large_elements(n);
}

template<typename T>
void Menu<T>::Sum() {
    stack.Summa();
}

template<typename T>
void Menu<T>::DeleteAll() {
    stack.Empty();
    cout << "Stack is Empty" << endl;
}