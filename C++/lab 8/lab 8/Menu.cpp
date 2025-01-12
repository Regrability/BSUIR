#include "Menu.h"

template<typename T>
void Menu<T>::Run() {
    int choice;

    do {
        PrintMenu();
        choice = InputINT(1, 12);

        switch (choice) {
        case 1:
            PushItem();
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
            EmptyLIST();
            break;
        case 6:
            WriteToFile();
            break;
        case 7:
            WriteFromFile();
            break;
        case 8:
            WriteToFileBin();
            break;
        case 9:
            WriteFromFileBin();
            break;
        case 10:
            SearchElement();
            break;
        case 11:
            SortElementByBY();
            break;
        case 12:
            cout << "Exiting the modul..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 12);
}
template<typename T>
void Menu<T>::PrintMenu() {
    cout << "\n-------- Menu --------" << endl;
    cout << "1. Add item" << endl;
    cout << "2. Delete item" << endl;
    cout << "3. Print List" << endl;
    cout << "4. Change field" << endl;
    cout << "5. Clear List" << endl;
    cout << "6. Write to text file" << endl;
    cout << "7. Read from text file" << endl;
    cout << "8. Write to bin file" << endl;
    cout << "9. Read from bin file" << endl;
    cout << "10.Search object by last name" << endl;
    cout << "11.Sort List by birth year" << endl;
    cout << "12.Exit modul" << endl;
    cout << "----------------------" << endl;
}

template<typename T>
void Menu<T>::PushItem() {
    T item;
    cout << "Enter the item to push: " << endl;
    cin >> item;
    Mylist.push_back(item);
    cout << "Item pushed successfully." << endl;
}

template<typename T>
void Menu<T>::DeleteItem() {
    system("cls");
    PrintList();
    if (Mylist.size() > 0)
    {
        cout << "Enter element to delete:";
        int num = InputINT(1, int(Mylist.size())) - 1;
        typename list<T>::iterator it = Mylist.begin();
        advance(it, num);
        Mylist.erase(it);
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
    if (Mylist.size() > 0)
    {
        cout << "Enter element to change:";
        int num = InputINT(1, int(Mylist.size())) - 1;
        typename list<T>::iterator it = Mylist.begin();
        advance(it, num);
        it->ChangeField();
        system("cls");
        cout << "Item is changing" << endl; 
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
    if (Mylist.empty())
    {
        cout << "List is empty" << endl;
    }
    else {
        T buf;
        buf.shapka();
        for (typename list<T>::const_iterator it = Mylist.cbegin(); it != Mylist.cend(); ++it)
        {
            cout << *it;
        }
    }
}

template<typename T>
void Menu<T>::EmptyLIST() {
    Mylist.clear();
    system("cls");
    cout << "List is Empty" << endl;
}

template<typename T>
void Menu<T>::WriteToFile() {
    T buf;
    file.DeleteFale();
    std::list<T> stack_buf(Mylist.rbegin(), Mylist.rend());
    for (typename std::list<T>::iterator it = stack_buf.begin(); it != stack_buf.end(); ++it) {
        buf = *it;
        file.write(buf);
    }
    system("cls");
    cout << "Information write to <<" << buf.GetFileName() << ">> from List" << endl;
}

template<typename T>
void Menu<T>::WriteFromFile() {
    Mylist.clear();
    system("cls");
    file.read(Mylist);
}

template<typename T>
void Menu<T>::WriteToFileBin() {
    T buf;
    filebin.DeleteFale();
    std::list<T> stack_buf(Mylist.rbegin(), Mylist.rend());
    for (typename std::list<T>::iterator it = stack_buf.begin(); it != stack_buf.end(); ++it) {
        buf = *it;
        filebin.write(buf);
    }
    system("cls");
    cout << "Information write to <<" << buf.GetFileNameBin() << ">> from List" << endl;
}

template<typename T>
void Menu<T>::WriteFromFileBin() {
    T buf;
    Mylist.clear();
    filebin.read(Mylist);
    system("cls");
    cout << "Information from file added to the List from file <<" << buf.GetFileNameBin() << ">>" << endl;
}

template<typename T>
void Menu<T>::SearchElement() {
    system("cls");
    algoritm.SearchLastName(Mylist);

}

template<typename T>
void Menu<T>::SortElementByBY() {
    system("cls");
    algoritm.BubbleSort(Mylist);
    cout << "List is sorted by birth year" << endl;
}
