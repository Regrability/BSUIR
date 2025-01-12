#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int proverka()
{
    int R;
    while (scanf_s("%d", &R) == 0 || getchar() != '\n')
    {
        while (getchar() != '\n') // check 
            continue;
        printf("Not correct\n");
        printf("Please, input a corrcet number\n");
    }
    return R;
}
void random(int arr3[], int n3)
{
    srand(time(NULL));
    for (int i = 0; i < n3; i++) {
        arr3[i] = rand() % 200 - 100; // random numbers 0-100
        printf("%d ", arr3[i]);// return
    }
    printf("\n");
}
void byYourSelf(int arr2[], int n2)
{
    for (int i = 0; i < n2; i++) {
        printf("a[%d] = ", i);// input by yourself
        arr2[i] = proverka();
    }
}
void poisk_k_sdvig(int arr1[], int n1)
{
    int i, j, n, k, cnt = 0, fl = 0;
    printf("Input k \n");
    scanf_s("%d", &k);
    for (i = 0; i < n1; i++)
    {
        cnt++;
        if (arr1[i] == 0)
            cnt--;

        if (cnt % k == 0)
        {
            n1++;
            for (j = 1 + i; j > n1; j++)
            {
                arr1[j] = arr1[j + 1];
            }
            arr1[i + 1] = 0;
        }
    }
    for (i = 0; i < n1; i++)
    {
        printf("%d ", arr1[i]);
    }
}

int main()
{
    int n, k, arr[100];
    printf("vvedite kol-vo chlenov v massive(maksi 100)\n");
    scanf_s("%d", &n);
    if ((n > 0) && (n < 101))// anti-crash
    {
        printf("vvedite cami(0) ili random(1)\n");
        scanf_s("%d", &k);// input by random
        if (k == 0)
        {
            byYourSelf(arr, n);
            poisk_k_sdvig(arr, n);
        }
        else if (k == 1)
        {
            random(arr, n);
            poisk_k_sdvig(arr, n);
        }
        else
            printf("nepravilni vvod\n");
    }
    else
        printf("nepravilni vvod");
    return 0;
}