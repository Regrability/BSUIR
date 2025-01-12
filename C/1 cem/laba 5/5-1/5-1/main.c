#include "Roman.h"
int main()
{
    srand(time(NULL));
    int* a;  
    int i, n;
    printf("vvedite ko-vo elementov\n");
    n= vvod();
    a = mass(n);
    ydalenie(a, &n);
    vvivod(a, &n);
    return 0;
}
