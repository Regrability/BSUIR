#include "Stack.h"

template <typename T>
StackList<T>::StackList()
{
    pTop = nullptr;
}

template <typename T>
StackList<T>::StackList(const StackList& SL)
{
    NodeStack<T>* p;
    NodeStack<T>* p2;
    NodeStack<T>* p3;
    pTop = nullptr;
    p3 = nullptr;

    p = SL.pTop;
    while (p != nullptr)
    {
        p2 = new NodeStack<T>;
        p2->item = p->item;
        p2->next = nullptr;

        if (pTop == nullptr)
        {
            pTop = p2;
            p3 = p2;
        }
        else
        {
            p3->next = p2;
            p3 = p3->next;
        }
        p = p->next;
    }
}

template <typename T>
StackList<T>::~StackList()
{
    Empty();
}
template <typename T>
void StackList<T>::Push(T item)
{
    NodeStack<T>* p;
    p = new NodeStack<T>;
    p->item = item;
    p->next = pTop;
    pTop = p;
}

template <typename T>
int StackList<T>::Count()
{
    if (pTop == nullptr)
        return 0;
    else
    {
        NodeStack<T>* p = pTop;
        int count = 0;
        while (p != nullptr)
        {
            count++;
            p = p->next;
        }
        return count;
    }
}
template <typename T>
void StackList<T>::Empty()
{
    NodeStack<T>* p;
    NodeStack<T>* p2;
    p = pTop;
    while (p != nullptr)
    {
        p2 = p;
        p = p->next;
        delete p2;
    }
    pTop = nullptr;
}
template <typename T>
StackList<T>& StackList<T>::operator=(const StackList<T>& LS)
{
    if (pTop != nullptr) Empty();
    NodeStack<T>* p;
    NodeStack<T>* p2;
    NodeStack<T>* p3;
    pTop = nullptr;
    p3 = nullptr;

    p = LS.pTop;
    while (p != nullptr)
    {
        p2 = new NodeStack<T>;
        p2->item = p->item;
        p2->next = nullptr;

        if (pTop == nullptr)
        {
            pTop = p2;
            p3 = p2;
        }
        else
        {
            p3->next = p2;
            p3 = p3->next;
        }
        p = p->next;
    }
    return *this;
}

template <typename T>
void StackList<T>::Print()
{
    if (pTop == nullptr)
        cout << "stack is empty." << endl;
    else
    {
        NodeStack<T>* p;
        p = pTop;
        T buf;
        buf.shapka();
        while (p != nullptr)
        {
            cout << p->item;
            p = p->next;
        }
        cout << endl;
    }
}
template <typename T>
T StackList<T>::Pop()
{
    if (pTop == nullptr)
        return T(); // ���������� �������� �� ���������, ���� ���� ����

    T item = pTop->item;
    NodeStack<T>* p = pTop;
    pTop = pTop->next;
    delete p; // ������� ���� �� ������
    return item;
}

template <typename T>
StackListIterator<T> StackList<T>::begin() { return StackListIterator<T>(pTop); }
template <typename T>
StackListIterator<T> StackList<T>::end() { return StackListIterator<T>(nullptr); }
