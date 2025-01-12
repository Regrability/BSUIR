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
        bool swapped = true; // Флаг, указывающий наличие обменов
        while (swapped)
        {
            swapped = false; // Сбрасываем флаг перед каждой итерацией

            // Проходим по элементам списка
            typename list<T>::iterator it = MyList.begin();
            typename list<T>::iterator nextIt = next(it);

            while (nextIt != MyList.end())
            {
                // Если текущий элемент больше следующего элемента
                if (it->getValue() > nextIt->getValue())
                {
                    // Меняем местами элементы
                    iter_swap(it, nextIt);
                    swapped = true; // Устанавливаем флаг обмена
                }

                // Переходим к следующим элементам
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