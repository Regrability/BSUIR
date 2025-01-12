//Menu.cpp
#include "Menu.h"
template<typename T>
void Menu<T>::Run(bool& write_to_stack) {
    int choice;
    PrintMenu();
    choice = InputINT(1, 9);
    switch (choice)
    {
    case 1:
        AddItem();
        break;
    case 2:
        DeleteItem();
        break;
    case 3:
        PrintList();
        break;
    case 4:
        ChangeFields();
        break;
    case 5:
        SearchValue(MyList);
        break;
    case 6:
        SearchName(MyList);
        break;
    case 7:
        BubbleSort(MyList);
        RewriteFile(); 
        break;
    case 8:
        ClearList();
        break;
    case 9:
        cout << "Exiting the modul..." << endl;
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
        break;
    }
    if (choice == 1 || choice == 2 || choice == 4 || choice == 7 || choice == 8) write_to_stack = true;
    else write_to_stack = false;
}

template<typename T>
void Menu<T>::PrintMenu() {
    cout << "\n----- Menu -----" << endl;
    cout << "1. Add item" << endl;
    cout << "2. Delete item" << endl;
    cout << "3. Print List" << endl;
    cout << "4. Change item" << endl;
    cout << "5. Search by value" << endl;
    cout << "6. Search by name" << endl;
    cout << "7. Sort by value" << endl;
    cout << "8. Clear list" << endl;
    cout << "9. Exit modul" << endl;
    cout << "----------------" << endl;
}

template<typename T>
void Menu<T>::AddItem() {
    T item;
    cin >> item;
    MyList.push_back(item);
    file.write(item);
    cout << "Item pushed successfully." << endl;
}

template<typename T>
void Menu<T>::DeleteItem() {
    system("cls");
    PrintList();
    if (MyList.size() > 0)
    {
        cout << "Enter element to delete:";
        int num = InputINT(1, int(MyList.size())) - 1;
        typename list<T>::iterator it = MyList.begin();
        advance(it, num);
        MyList.erase(it);
        RewriteFile();
    }
    else
    {
        cout << "There aren't elements to delete" << endl;
    }
}

template<typename T>
void Menu<T>::ChangeFields() {
    system("cls");
    PrintList();
    if (MyList.size() > 0)
    {
        cout << "Enter element to change:";
        int num = InputINT(1, int(MyList.size())) - 1;
        typename list<T>::iterator it = MyList.begin();
        advance(it, num);
        it->ChangeField();
        RewriteFile();
    }
    else
    {
        cout << "There aren't elements to change" << endl;
    }
}

template<typename T>
void Menu<T>::PrintList()
{
    system("cls");
    if (MyList.empty())
    {
        cout << "List is empty" << endl;
    }
    else {
        T buf;
        buf.Shapka();
        for (typename list<T>::const_iterator it = MyList.cbegin(); it != MyList.cend(); ++it)
        {
            cout << *it;
        }
    }
}

template<typename T>
void Menu<T>::WriteFromFile()
{
    file.read(MyList);
}

template<typename T>
void Menu<T>::RewriteFile()
{
    file.DeleteFale();
    for (typename list<T>::iterator it = MyList.begin(); it != MyList.end(); ++it)
        file.write(*it);
}

template<typename T>
void Menu<T>::ClearList()
{
    system("cls");
    if (MyList.empty())
    {
        cout << "List is empty" << endl;
    }
    else {
        MyList.clear();
        file.DeleteFale();
        cout << "List is empty" << endl;
    }
}