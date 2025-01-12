#include "Roman.h";
int main()
{
    int** a;  
    int n, m;
    srand(time(NULL));
    printf("vvedite kol-vo ctrochek:");
    n = vvod();
    printf("vvedite kol-vo ctolbcev:");
    m = vvod();
    a = mass(n, m);
    vvod_2matr(a, &n, &m);
    vivod_2matr(a, &n, &m);
    ydalenie_crtochec_c_0(a, &n, &m);
    vivod_2matr(a, &n, &m);
    ochichenie(a, &n, &m);
    return 0;
}