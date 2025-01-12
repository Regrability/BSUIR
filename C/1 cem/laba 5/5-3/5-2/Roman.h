#include <stdio.h>
#include <malloc.h>
#include<stdlib.h>
#include<time.h>
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
void vvod_2matr(int** a, int* n, int* m)
{
    int i, j, k;
    printf("vvedite 2 chiclo(cami-1; random-2)\n");
    k = numinputrange(VIBOR_MIN, VIBOR_MAX);//тут выбор сам или нет
    if (k == 1)
    {
        for (int i = 0; i < *n; i++)
            for (int j = 0; j < *m; j++) 
            {
                printf("\nb[%d][%d]=", i + 1, j + 1);
                a[i][j] = vvod();
            }
    }
    if (k == 2)
    {
        for (int i = 0; i < *n; i++)
            for (int j = 0; j < *m; j++)
                a[i][j] = rand() % 20 - 10;
    }
}
void vivod_2matr(int** a, int* n, int* m)
{
    int i, j;

    for (i = 0; i < *n; i++)
    {
        for (j = 0; j < *m; j++)
        {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }
}
void ydalenie_crtochec_c_0(int** a, int* n, int* m)
{
    int popalsa=0;
    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < (*m)-2; j++)//поиск 0 0 0 
        {
            if ((a[i][j]==0) && (a[i][j + 1]==0) && (a[i][j + 2]==0))
            {
                popalsa = 1;
            }
        }
        if (popalsa == 1)//перестановка
        {

            for (int w = i; w < (*n) - 1; w++)
            {
                for (int j = 0; j < *m; j++)
                {
                    a[w][j] = a[w + 1][j];
                }
            }
            --(*n);
        }
        popalsa = 0;

        for (int j = 0; j < (*m) - 2; j++)//поиск 0 0 0 для перескока
        {
            if ((a[i][j] == 0) && (a[i][j + 1] == 0) && (a[i][j + 2] == 0))
            {
                popalsa = 1;
            }
        }
        if (popalsa == 1)
        {
            --i;
            popalsa = 0;
        }
    }
    printf("\n");
}
int** mass(int n, int m)
{
    int** a;
    a = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        a[i] = (int*)malloc(m * sizeof(int));
    return a;
}
void ochichenie(int** a, int* n, int* m)
{
    for (int i = 0; i < *n; i++)
        free(a[i]);
    free(a);
}