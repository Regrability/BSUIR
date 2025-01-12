#include "Menu.h"

template<typename T>
void Menu<T>::Run() {
    int choice;

    do {
        PrintMenu();
        choice = InputINT(1, 10);

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
            cout << "Exiting the modul..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 10);
}
template<typename T>
void Menu<T>::PrintMenu() {
    cout << "\n-------- Menu --------" << endl;
    cout << "1. Push item"             << endl;
    cout << "2. Pop item"              << endl;
    cout << "3. Print stack"           << endl;
    cout << "4. Change field"          << endl;
    cout << "5. Clear stack"           << endl;
    cout << "6. Write to text file"    << endl;
    cout << "7. Read from text file"   << endl;
    cout << "8. Write to bin file"     << endl;
    cout << "9. Read from bin file"    << endl;
    cout << "10.Exit modul"            << endl;
    cout << "----------------------"   << endl;
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

template<typename T>
void Menu<T>::WriteToFile()
{
    T buf;
    file.DeleteFale();
    StackList<T> stack_buf;
    int couti = stack.Count();
    for (int i = 0; i < couti; i++) { stack_buf.Push(stack.Pop()); }//чтобы перевернуть стэк
    for (int i = 0; i < couti; i++)
    {
        buf = stack_buf.Pop();
        stack.Push(buf);
        file.write(buf);
    }    
    system("cls");
    cout << "Information write to <<" << buf.GetFileName() << ">> from Stack" << endl;
}

template<typename T>
void Menu<T>::WriteFromFile()
{
    stack.Empty();
    file.read(stack);
}

template<typename T>
void Menu<T>::WriteToFileBin()
{
    T buf;
    filebin.DeleteFale();
    StackList<T> stack_buf;
    int couti = stack.Count();
    for (int i = 0; i < couti; i++) { stack_buf.Push(stack.Pop()); }//чтобы перевернуть стэк
    for (int i = 0; i < couti; i++)
    {
        buf = stack_buf.Pop();
        stack.Push(buf);
        filebin.write(buf);
    }
    system("cls");
    cout << "Information write to <<" << buf.GetFileNameBin() << ">> from Stack" << endl;
}

template<typename T>
void Menu<T>::WriteFromFileBin()
{
    T buf;
    stack.Empty();
    filebin.read(stack);
    system("cls"); 
    cout << "Information from file added to the Stack from file <<" << buf.GetFileNameBin() << ">>" << endl;
}
