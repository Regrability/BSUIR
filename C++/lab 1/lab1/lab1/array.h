#include <iostream>
using namespace std;

class Array
{
 private:
    int n;
    int* array;

 public:
    Array();
    Array(int size);
   /* Array(const Array& other);*/
    ~Array();

    void Enter_Array();
    void Print_Array();
    Array Intersection_Arrays(const Array& clas2);
    Array operator+(const Array& clas2);
};

