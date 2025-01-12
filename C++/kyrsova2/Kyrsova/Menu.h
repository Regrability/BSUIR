//Menu.h
#pragma once
#include "MyAlgoritms.cpp"
template<typename T>
class Menu {
private:
    MyFile<T> file;
    list<T> MyList;

public:
    void Run(bool& write_to_stack);
    void WriteFromFile();
    void RewriteFile();

private:
    void PrintMenu();
    void AddItem();
    void DeleteItem();
    void PrintList();
    void ChangeFields();
    void ClearList();
};