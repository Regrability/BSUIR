//MyAlgoritms.cpp
#include "MyAlgoritms.h"
template <typename T>
void BubbleSort(list<T>& MyList)
{
    system("cls");
    if (MyList.empty())
    {
        cout << "List is empty" << endl;
    }
    else
    {
        bool swapped = true; // ����, ����������� ������� �������
        while (swapped)
        {
            swapped = false; // ���������� ���� ����� ������ ���������

            // �������� �� ��������� ������
            typename list<T>::iterator it = MyList.begin();
            typename list<T>::iterator nextIt = next(it);

            while (nextIt != MyList.end())
            {
                // ���� ������� ������� ������ ���������� ��������
                if (it->getValue() > nextIt->getValue())
                {
                    // ������ ������� ��������
                    iter_swap(it, nextIt);
                    swapped = true; // ������������� ���� ������
                }

                // ��������� � ��������� ���������
                ++it;
                ++nextIt;
            }
        }
    }
}
template<typename T>
void SearchValue(list<T>& MyList)
{
    system("cls");
    if (MyList.empty())
    {
        cout << "List is empty" << endl;
    }
    else
    {
        cout << "Enter min value: ";
        double min_value = InputDouble(0, 10001);
        bool flag = true;
        for (typename list<T>::iterator it = MyList.begin(); it != MyList.end(); ++it)
        {
            if (it->getValue() >= min_value)
            {
                if (flag) { MyList.front().Shapka(); flag = false; }
                cout << *it;
            }
        }
        if (flag) cout << "There are no elements" << endl;
    }
}

template<typename T>
void SearchName(list<T>& MyList)
{
    system("cls");
    if (MyList.empty())
    {
        cout << "List is empty" << endl;
    }
    else
    {
        cout << "Enter name: ";
        string name = InputString();
        bool flag = true;
        for (typename list<T>::iterator it = MyList.begin(); it != MyList.end(); ++it)
        {
            if (it->getName() == name)
            {
                if (flag) { MyList.front().Shapka(); flag = false; }
                cout << *it;
            }
        }
        if (flag) cout << "There are no elements" << endl;
    }
}