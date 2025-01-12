#include "Roma.h"
int main()
{
    srand(time(NULL));
    int* a;
    int* nechet;
    int i, n, stop=0, razmer_nechet=0;
    printf("vvedite ko-vo elementov\n");
    n = vvod();
    a = mass(n);
    nechet = (int*)malloc(n * sizeof(int));
    sortirovka(a, nechet, n, &stop, &razmer_nechet);
    vvivod(a, &n);
    printf("\n kol-vo nechetnix - %d", razmer_nechet);
    printf("\n stop - %d", stop+1);
    return 0;
}
