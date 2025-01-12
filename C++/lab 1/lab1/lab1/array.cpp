#include "array.h"
Array::Array()
{
    n = 0;
    array = nullptr;
}
Array::Array(int size)
{
    n = size;
    array = new int[n];
}
//Array::Array(const Array& other)
//{
//    n = other.n;
//    array = new int[n];
//    for (int i = 0; i < n; i++) {
//        array[i] = other.array[i];
//    }
//}
Array::~Array()
{
    //cout << "Memory is clear:" << endl;
    delete[] array;
}
void Array::Enter_Array()
{
    for (int i = 0; i < n; i++) 
        cin >> array[i];

}
void Array::Print_Array()
{
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

Array Array::Intersection_Arrays(const Array& clas2)
    {
        int maxLength = (this->n > clas2.n) ? this->n : clas2.n;
        Array clas3{maxLength};

        for (int i = 0; i < maxLength; ++i) {
            int sum = 0;

            if (i < this->n) {
                sum += this->array[i];
            }

            if (i < clas2.n) {
                sum += clas2.array[i];
            }

            clas3.array[i] = sum;
        }


        return clas3;
    }


Array Array::operator+(const Array& clas2)
{
    int i, j;
    int ch = 0;
    int n3 = (this->n > clas2.n) ? clas2.n : this->n;
    Array clas3( n3 );


    for (i = 0; i < this->n; i++)
    {
        for (j = 0; j < clas2.n; j++)
        {
            if (this->array[i] == clas2.array[j])
            {
                clas3.array[ch] = this->array[i];
                ch++;
            }

        }

    }
    clas3.n = ch;
    return clas3;
}