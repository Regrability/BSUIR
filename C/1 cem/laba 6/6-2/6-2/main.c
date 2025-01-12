#include "Roma.h";
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
        chetnie(a, n, m);
        bubbleSort(a, n, m);
        n = n + 1;
        vivod_2matr(a, &n, &m);
        ochichenie(a, &n);
        return 0;
    }
