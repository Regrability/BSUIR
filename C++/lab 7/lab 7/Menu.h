#pragma once
#include "Stack.cpp"
#include "TextFile.h"
#include "BinFile.h"
#include "Algoritm.h"
template<typename T>
class Menu {
private:
    StackList<T> stack;
    MyFile<T> file;
    MyFileBin<T> filebin;
    Algorithms<T> algoritm;

public:
    void Run();

private:
    void WriteFromFile();
    void WriteToFile();
    void WriteFromFileBin();
    void WriteToFileBin();
    void PrintMenu();
    void PushItem();
    void PopItem();
    void PrintStack();
    void ChangeFields();
    void EmptyStack();
    void SearchElement();
    void SortElementByBY();
    void SortElementByLN();
};