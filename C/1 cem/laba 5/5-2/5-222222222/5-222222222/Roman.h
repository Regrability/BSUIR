#include <stdio.h>
#include <malloc.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#define VIBOR_MIN 1
#define VIBOR_MAX 2
int numinputrange(int min, int max)
{
    int var;
    while ((scanf_s("%d", &var) == 0) || (var < min) || (var > max) || getchar() != '\n')
    {
        printf("wrong input! try again\n");
        rewind(stdin);
    }
    return var;
}
int vvod()
{
    int var;
    while ((scanf_s("%d", &var) == 0) || getchar() != '\n')
    {
        printf("wrong input! try again\n");
        rewind(stdin);
    }
    return var;
}


void ydalenie_maxelementov_v_strokax(int** a, int n, int* m)
{
    int i, j, max;
    printf("\n");
    for (i = n-1; i > -1; i--)
    {
        max = a[i][0];
        for (j = 0; j < m[i]; j++)//поиск максимального
        {
            if (a[i][j] > max)
            {
                max = a[i][j];
            }
        }
        printf("max v stroke %d = %d\n", i + 1, max);

        for (j = m[i]-1; j > -1; j--)//удаление
        {

            if (a[i][j]==max)
            {
                for (int w = j; w < m[i]; w++)
                {
                    a[i][w] = a[i][w + 1];
                }
                --m[i];
            }

        }
    }
    printf("\n");
}
void vvod_2matr_canystolbcami(int** a, int n, int* m)
{
    int i, j, k;
    for (i = 0; i < n; i++)//ввод
    {
        printf("Vvedite kol-vo stolcev v stroke  %d: ", i + 1);
        m[i] = vvod();
        a[i] = (int*)malloc(m[i] * sizeof(int));
        printf("cam(1) random(2)\n");
        k = numinputrange(VIBOR_MIN, VIBOR_MAX);
        if (k == 1)
        {
            for (j = 0; j < m[i] - 1; j++)
            {
                printf("a[%d][%d]= ", i + 1, j + 1);
                a[i][j] = vvod();
            }
            a[i][m[i] - 1] = 0;
        }
        if (k == 2)
        {
            for (j = 0; j < m[i] - 1; j++)
            {
                a[i][j] = rand() % 200 - 100; // диапазон случайных чисед от 0 до 100
            }
            a[i][m[i] - 1] = 0;
        }
    }
}
void vivod_2matr_canystolbcami(int** a, int n, int* m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m[i]; j++)
        {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }

}
int** mass2(int n)
{
    int** a;
    a = (int**)malloc(n * sizeof(int*));
    return a;
}
int* mass1(int n)
{
    int* a;
    a = (int*) сalloc(n, sizeof(int));
    return a;
    
}
void ochichenie(int** a, int n, int* m)
{
    for (int i = 0; i < n; i++)
    {
        free(a[i]);
    }
    free(a);
    free(m);
}