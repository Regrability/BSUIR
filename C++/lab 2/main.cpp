#include "MyString.h"
int main()
{
    String s1, s2, s4;
    int first, second;
    cout << "Enter first string: ";
    s1.vvod_str();
    cout << "Enter second string: ";
    s2.vvod_str();
    cout << "Enter thed string: ";
    s4.vvod_str();
    String s3 = "VF " + s2 + s4 + "230501";
    cout << s3() << endl;  

    s3 += s4;
    cout << s3() << endl; 

    bool greater = s1 > s2;
    cout << boolalpha << greater << endl;  

    char ch = s1[0];
    cout << ch << endl;  // Выводит первую букву

    cout << "Enter first symbol: ";
    cin >> first;
    cout << "Enter second symbol: ";
    cin >> second;
    String sub = s3(first, second);
    cout << sub() << endl;  

    return 0;
}