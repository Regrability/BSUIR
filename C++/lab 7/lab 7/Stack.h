#pragma once
#include "IteratorStack.h"

template <typename T>
class StackList
{
protected:
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
    StackListIterator<T> begin();
    StackListIterator<T> end();
};

