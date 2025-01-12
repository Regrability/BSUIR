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
                a[i][j] = rand() % 199 - 99;
    }for (int i = 0; i < *m; i++)
    {
        a[*n][i] = 0;
    }
}
void vivod_2matr(int** a, int* n, int* m)
{
    int i, j;

    for (i = 0; i < *n; i++)
    {
        for (j = 0; j < *m; j++)
        {
            printf("%5d ", a[i][j]);
        }
        printf("\n");
    }
}
void chetnie(int** a, int n, int m)
{
    int i, j;
    for (j = 0; j < m; j++)
    {
        for (i = 0; i < n; i++)
        {
            if (a[i][j] % 2 == 0)
            {
                a[n][j] = a[n][j] + a[i][j];
            }
        }
    }
    printf("\n");
    return 0;
}

void bubbleSort(int** num, int n, int m)
{
    // Для всех элементов
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = (m - 1); j > i; j--) // для всех элементов после i-ого
        {
            if (num[n][j - 1] > num[n][j]) // если текущий элемент меньше предыдущего
            {
                for (int y = n; y > -1; y--)
                {
                    int temp = num[y][j - 1]; // меняем их местами
                    num[y][j - 1] = num[y][j];
                    num[y][j] = temp;
                }
            }
        }
    }
}
int** mass(int n, int m)
{
    n = n + 1;
    int** a;
    a = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        a[i] = (int*)malloc(m * sizeof(int));
    return a;
}
void ochichenie(int** a, int* n)
{
    n = n + 1;
    for (int i = 0; i < *n; i++)
        free(a[i]);
    free(a);
}