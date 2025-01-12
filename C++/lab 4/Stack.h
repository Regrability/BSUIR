#pragma once
#include <iostream>
#include <string>
using namespace std;
template <typename T>
struct NodeStack
{
    T item;
    NodeStack<T>* next;
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
    void Less_elements(T n);
    void Large_elements(T n);
    void Summa();
    T Pop();
};
