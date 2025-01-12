//Iterator_Stack.h
#pragma once
#include <iostream>
#include <string>
#include <tuple>
using namespace std;
template <typename T1, typename T2, typename T3, typename T4>
struct NodeStack
{
    T1 item1;
    T2 item2;
    T3 item3;
    T4 item4;
    NodeStack<T1, T2, T3, T4>* next;
};

template <typename T1, typename T2, typename T3, typename T4>
class StackListIterator
{
private:
    NodeStack<T1, T2, T3, T4>* pNode;

public:
    StackListIterator();
    StackListIterator(NodeStack<T1, T2, T3, T4>* node);
    StackListIterator& operator++();
    bool operator!=(const StackListIterator& other) const;
    tuple<T1, T2, T3, T4> operator*() const;
};

template <typename T1, typename T2, typename T3, typename T4>
StackListIterator<T1, T2, T3, T4>::StackListIterator() { pNode = nullptr; }

template <typename T1, typename T2, typename T3, typename T4>
StackListIterator<T1, T2, T3, T4>::StackListIterator(NodeStack<T1, T2, T3, T4>* node) : pNode(node) {}

template <typename T1, typename T2, typename T3, typename T4>
StackListIterator<T1, T2, T3, T4>& StackListIterator<T1, T2, T3, T4>::operator++() 
{
    if (pNode)
        pNode = pNode->next;
    return *this;
}

template <typename T1, typename T2, typename T3, typename T4>
bool StackListIterator<T1, T2, T3, T4>::operator!=(const StackListIterator& other) const
{
    return pNode != other.pNode;
}

template <typename T1, typename T2, typename T3, typename T4>
tuple<T1, T2, T3, T4>  StackListIterator<T1, T2, T3, T4>::operator*() const
{
    return make_tuple(pNode->item1, pNode->item2, pNode->item3, pNode->item4);
}