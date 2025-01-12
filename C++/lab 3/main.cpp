#include "Business.h"
#include "res.h"
int main()
{
    const int arraySize = 2; // Размер массива
    Business business[arraySize];
    for (int i = 0; i < arraySize; i++)
    {
        cin >> business[i];
    }
    ChangeArray(business, arraySize); 
    business[0].shapka();
    for (int i = 0; i < arraySize; i++)
    {
        cout << business[i];
    }
    return 0;
}