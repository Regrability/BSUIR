#pragma once
#include <iostream>
#include <cstdlib>
#include <iomanip> 
#include "MyVvod.h"
#include "Stack.h"
using namespace std;
template <typename T>
struct NodeStack
{
    T item;
    NodeStack<T>* next = NULL;
};
template <typename T>
class StackListIterator
{
private:
    NodeStack<T>* current;

public:
    StackListIterator() { current = NULL; }
    StackListIterator(NodeStack<T>* p) : current(p) {}
    T& operator*() { return current->item; }
    StackListIterator& operator++() { current = current->next; return *this; }
    bool operator!=(const StackListIterator& other) const { return current != other.current; }
    StackListIterator<T> at(int index)
    {
        for (int i = 0; i < index; ++i)
        {
            ++(*this);
        }
        return *this;
    }
    void ChangeItem(T buf) { current->item = buf; }
};