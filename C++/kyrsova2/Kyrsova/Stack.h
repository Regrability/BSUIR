//Stack.h
#pragma once
#include "Iterator_Stack.h"
template <typename T1, typename T2, typename T3, typename T4>
class StackList
{
private:
    NodeStack<T1, T2, T3, T4>* pTop;

public:
    StackList();
    StackList(const StackList& SL);
    ~StackList();
    StackList<T1, T2, T3, T4>& operator=(const StackList<T1, T2, T3, T4>& LS);
    void Empty();
    int Cout();
    StackListIterator<T1, T2, T3, T4> begin() const;
    StackListIterator<T1, T2, T3, T4> end() const;
    void Push(T1 item1, T2 item2, T3 item3, T4 item4);
    tuple<T1, T2, T3, T4> Pop();
};