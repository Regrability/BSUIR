#pragma once
#include "Stack.h"
template <typename T>
class Algorithms
{
public:
    StackList<T> search(StackList<T>& stack)
    {
        StackList<T> stack_buf;
        cout << "If you input 'n' - that paramentrs is not search" << endl;
        cout << "Enter last name: ";
        String last_name = InputString();
        cout << "Enter first name: ";
        String first_name = InputString();
        for (StackListIterator<T> it = stack.begin(); it != stack.end(); ++it)
        {
            if (((*it).get_last_name() == last_name || (last_name == "n")) && ((*it).get_first_name() == first_name || (first_name == "n")))
            {
                stack_buf.Push(*it); 
            }
        }
        return stack_buf;
    }
    void buble_sort(StackList<T>& stack)
    {
        int i = 0;
        int n = stack.Count();
        T* arr = new T[n];
        for (StackListIterator<T> it = stack.begin(); it != stack.end(); ++it)
        {
            if (i < n) arr[i] = (*it);
            i++;
        }
        // Bubble sort
        for (i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j].get_birth_year() < arr[j + 1].get_birth_year()) {
                    T temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        stack.Empty();
        for (i = 0; i < n; i++) { stack.Push(arr[i]); }
        delete[] arr;
    }
    void insertion_sort(StackList<T>& stack)
    {
        int i = 0;
        int n = stack.Count();
        T* arr = new T[n];
        for (StackListIterator<T> it = stack.begin(); it != stack.end(); ++it)
        {
            if (i < n) arr[i] = (*it);
            i++;
        }
        // Insertion sort
        for (int i = 1; i < n; i++) {
            String key = arr[i].get_last_name();
            T key_buf = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j].get_last_name() < key){
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key_buf;
        }
        stack.Empty();
        for (i = 0; i < n; i++) { stack.Push(arr[i]); }
        delete[] arr;
    }
};