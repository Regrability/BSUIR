#include "Roman.h";
int main()
{
    srand(time(NULL));
    int** a;
    int n;
    int * m;
    printf("Vvedite ko-vo strok: ");
    n = vvod();
    a = mass2(n);
    m = mass1(n);
    vvod_2matr_canystolbcami(a, n, m);
    vivod_2matr_canystolbcami(a, n, m);
    ydalenie_maxelementov_v_strokax(a, n, m);
    vivod_2matr_canystolbcami(a, n, m);
    ochichenie(a, n, m);
    return 0;
}