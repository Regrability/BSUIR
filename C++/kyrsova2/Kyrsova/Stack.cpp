//Stack.cpp
#include "Stack.h"

template <typename T1, typename T2, typename T3, typename T4>
StackList<T1, T2, T3, T4>::StackList()
{
    pTop = nullptr;
}

template <typename T1, typename T2, typename T3, typename T4>
StackList<T1, T2, T3, T4>::StackList(const StackList& SL)
{
    NodeStack<T1, T2, T3, T4>* p;
    NodeStack<T1, T2, T3, T4>* p2;
    NodeStack<T1, T2, T3, T4>* p3;
    pTop = nullptr;
    p3 = nullptr;

    p = SL.pTop;
    while (p != nullptr)
    {
        p2 = new NodeStack<T1, T2, T3, T4>;
        p2->item1 = p->item1;
        p2->item2 = p->item2;
        p2->item3 = p->item3;
        p2->item4 = p->item4;
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

template <typename T1, typename T2, typename T3, typename T4>
StackList<T1, T2, T3, T4>::~StackList()
{
    Empty();
}

template <typename T1, typename T2, typename T3, typename T4>
void StackList<T1, T2, T3, T4>::Push(T1 item1, T2 item2, T3 item3, T4 item4)
{
    NodeStack<T1, T2, T3, T4>* p;
    p = new NodeStack<T1, T2, T3, T4>;
    p->item1 = item1;
    p->item2 = item2;
    p->item3 = item3;
    p->item4 = item4;
    p->next = pTop;
    pTop = p;
}

template <typename T1, typename T2, typename T3, typename T4>
void StackList<T1, T2, T3, T4>::Empty()
{
    NodeStack<T1, T2, T3, T4>* p;
    NodeStack<T1, T2, T3, T4>* p2;
    p = pTop;
    while (p != nullptr)
    {
        p2 = p;
        p = p->next;
        delete p2;
    }
    pTop = nullptr;
}

template <typename T1, typename T2, typename T3, typename T4>
int StackList<T1, T2, T3, T4>::Cout()
{
    int cout = 0;
    NodeStack<T1, T2, T3, T4>* p;
    p = pTop;
    while (p != nullptr)
    {
        p = p->next;
        cout++;
    }
    return cout;
}


template <typename T1, typename T2, typename T3, typename T4>
StackListIterator<T1, T2, T3, T4> StackList<T1, T2, T3, T4>::begin() const
{
    return StackListIterator<T1, T2, T3, T4>(pTop);
}

template <typename T1, typename T2, typename T3, typename T4>
StackListIterator<T1, T2, T3, T4> StackList<T1, T2, T3, T4>::end() const
{
    return StackListIterator<T1, T2, T3, T4>(nullptr);
}

template <typename T1, typename T2, typename T3, typename T4>
StackList<T1, T2, T3, T4>& StackList<T1, T2, T3, T4>::operator=(const StackList<T1, T2, T3, T4>& LS)
{
    if (pTop != nullptr) Empty();
    NodeStack<T1, T2, T3, T4>* p;
    NodeStack<T1, T2, T3, T4>* p2;
    NodeStack<T1, T2, T3, T4>* p3;
    pTop = nullptr;
    p3 = nullptr;

    p = LS.pTop;
    while (p != nullptr)
    {
        p2 = new NodeStack<T1, T2, T3, T4>;
        p2->item1 = p->item1;
        p2->item2 = p->item2;
        p2->item3 = p->item3;
        p2->item4 = p->item4;
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
template <typename T1, typename T2, typename T3, typename T4>
tuple<T1, T2, T3, T4> StackList<T1, T2, T3, T4>::Pop()
{
    if (pTop == nullptr)
    {
        cout << "You can't step back" << endl;
        return make_tuple(T1(), T2(), T3(), T4());
    }

    tuple<T1, T2, T3, T4> items(pTop->item1, pTop->item2, pTop->item3, pTop->item4);
    NodeStack<T1, T2, T3, T4>* p = pTop;
    pTop = pTop->next;
    delete p;
    return items;
}