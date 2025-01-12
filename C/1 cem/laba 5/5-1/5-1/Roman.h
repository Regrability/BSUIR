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
int* mass(int n1)
{
    int* mass;
    int i, k;
    mass = (int*)malloc(n1 * sizeof(int));
    printf("cam(1) random(2)\n");
    k = numinputrange(VIBOR_MIN, VIBOR_MAX);
    if (k == 1)
    {
        for (i = 0; i < n1; i++)
        {
            printf("a[%d] = ", i+1);
            mass[i] = vvod();
        }
    }
    if (k == 2)
    {
        for (int i = 0; i < n1; i++)
        {
            mass[i] = rand() % 200 - 100; // диапазон случайных чисед от 0 до 100
            printf("%d ", mass[i]);
        }
        printf("\n ");

    }

    return mass;
}
void ydalenie(int* a, int* n)
{
    int razmer = *n;
    for (razmer; razmer > -1; razmer--)
    {
        if ((a[razmer] % 11 == 0) && (a[razmer] != 0))
        {
            for (int i = razmer; i < *n; i++)
            {
                a[i] = a[i + 1];
            }
            (*n)--;
        }

    }

}
void vvivod(int* a, int* n)
{
    printf("\n");
    for (int i = 0; i < *n; i++)
        printf("%d ", a[i]);
    free(a);
}