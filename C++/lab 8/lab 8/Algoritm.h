#pragma once
#include <algorithm>
#include "MyVvod.h"
#include "Menu.h"
template <typename T>
class Algorithms
{
public:
    //StackList<T> search(StackList<T>& stack)
    //{
    //    StackList<T> stack_buf;
    //    cout << "If you input 'n' - that paramentrs is not search" << endl;
    //    cout << "Enter last name: ";
    //    String last_name = InputString();
    //    cout << "Enter first name: ";
    //    String first_name = InputString();
    //    for (StackListIterator<T> it = stack.begin(); it != stack.end(); ++it)
    //    {
    //        if (((*it).get_last_name() == last_name || (last_name == "n")) && ((*it).get_first_name() == first_name || (first_name == "n")))
    //        {
    //            stack_buf.Push(*it); 
    //        }
    //    }
    //    return stack_buf;
    //}

    template<typename T>
    void SearchLastName(list<T>& MyList)
    {
        system("cls");
        if (MyList.empty())
        {
            cout << "List is empty" << endl;
        }
        else
        {
            cout << "Enter last name: ";
            String name = InputString();
            bool flag = true;
            for (typename list<T>::iterator it = MyList.begin(); it != MyList.end(); ++it)
            {
                if (it->get_last_name() == name)
                {
                    if (flag) { MyList.front().shapka(); flag = false; }
                    cout << *it;
                }
            }
            if (flag) cout << "There are no elements" << endl;
        }
    }


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
                    if (it->get_birth_year() > nextIt->get_birth_year())
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








    //void insertion_sort(StackList<T>& stack)
    //{
    //    int i = 0;
    //    int n = stack.Count();
    //    T* arr = new T[n];
    //    for (StackListIterator<T> it = stack.begin(); it != stack.end(); ++it)
    //    {
    //        if (i < n) arr[i] = (*it);
    //        i++;
    //    }
    //    // Insertion sort
    //    for (int i = 1; i < n; i++) {
    //        String key = arr[i].get_last_name();
    //        T key_buf = arr[i];
    //        int j = i - 1;
    //        while (j >= 0 && arr[j].get_last_name() < key){
    //            arr[j + 1] = arr[j];
    //            j--;
    //        }
    //        arr[j + 1] = key_buf;
    //    }
    //    stack.Empty();
    //    for (i = 0; i < n; i++) { stack.Push(arr[i]); }
    //    delete[] arr;
    //}
};