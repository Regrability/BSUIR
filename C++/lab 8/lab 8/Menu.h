#pragma once
#include "TextFile.h"
#include "BinFile.h"
#include "Algoritm.h"
#include "MyVvod.h"
#include <algorithm>
#include <fstream>
#include <list>
template<typename T>
class Menu {
private:
    MyFile<T> file;
    std::list<T> Mylist;
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
    void DeleteItem();
    void PrintList(); 
    void ChangeFields();
    void EmptyLIST();
    void SearchElement();
    void SortElementByBY();
};