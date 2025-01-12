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
            printf("a[%d] = ", i + 1);
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
void sortirovka(int* a, int* nechet, int n, int *stop, int* razmer_nechet)
{
    int j = 0, tmp, step, i;
    for (int i = 0; i < n; i++)//находим стоп
    {
        if (a[i] > 0)
        {
            *stop = i;
        }
    }
    for (int i = 0; i < *stop; i++)//заполняем массив
    {
        if (a[i] % 2 != 0)
        {
            nechet[j] = a[i];
            j++;
            (*razmer_nechet)++;
        }
    }
     for (step = (*razmer_nechet) / 2; step > 0; step /= 2) // Перечисление элементов, которые сортируются на определенном шаге 
    {
        for (i = step; i < (*razmer_nechet); i++)
        {   // Перестановка элементов внутри подсписка, пока i-тый не будет отсортирован
            for (j = i - step; (j >= 0) && (nechet[j] > nechet[j + step]); j -= step)
            {
                tmp = nechet[j];
                nechet[j] = nechet[j + step];
                nechet[j + step] = tmp;
            }
        }
    }
    j = 0;
    for (int i = 0; i < *stop; i++)//вставка
    {
        if (a[i] % 2 != 0)
        {
            a[i]= nechet[j];
            j++;
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