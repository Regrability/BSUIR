#pragma once
#include <iostream>
#include <cstdlib>
#include <iomanip> // Для использования std::setw
#include "MyVvod.h"
using namespace std;
template <typename T>
struct NodeStack
{
    T item;
    NodeStack<T>* next = NULL;
};

template <typename T>
class StackList
{
private:
    NodeStack<T>* pTop;

public:
    StackList();
    StackList(const StackList& SL);
    ~StackList();
    void Push(T item);
    int Count();
    void Empty();
    StackList<T>& operator=(const StackList<T>& LS);
    void Print();
    T Pop();
};