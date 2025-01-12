#include "array.h"
int main()
{
    int size1, size2, size3;

    cout << "Enter size of first array: ";
    cin >> size1;
    Array m1{size1};
    cout << "Enter first array: " << endl;
    m1.Enter_Array();

    cout << "Enter size of second array: ";
    cin >> size2;
    Array m2{size2};
    cout << "Enter second array: " << endl;
    m2.Enter_Array();
    

 /*   cout << "Enter size of thed array: ";
    cin >> size3;
    Array m4{ size3 };
    cout << "Enter second array: " << endl;
    m4.Enter_Array();*/


    m1.Print_Array();
    m2.Print_Array();
   /* m4.Print_Array();*/

    cout << "Intersection of Arrays:";
    Array m3 = m1.Intersection_Arrays(m2);
    m3.Print_Array();
    return 0;
}