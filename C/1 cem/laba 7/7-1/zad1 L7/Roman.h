#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int check(int op)
{
    int in;
    while ((scanf_s("%d", &in) == 0) || (in < 1) || (in > op) || getchar() != '\n')
    {
        printf("Wrong! Try again\n");
        rewind(stdin);
    }
    return in;
}
void print(char* arr, int l)
{
    for (int i = 0; i < l; i++)
        printf("%c", arr[i]);
}
char* real(char* arr, int l)
{
    arr = (char*)realloc(arr, l);
    return arr;
}
char* input(char* arr, int* l)
{
    int g = *l, i = 0, c;
    while ((c = getchar()) != '\n')
    {
        if (isalpha(c) == 0)
        {
            if (c != ' ')
            {
                printf("Wrong! Try again\n");
                i = 0;
                g = 0;
                rewind(stdin);
            }
            else
                if ((i + 1) >= g)
                {
                    g++;
                    arr = real(arr, g);
                    arr[i] = c;
                    i++;
                }
        }
        else
            if ((i + 1) >= g)
            {
                g++;
                arr = real(arr, g);
                arr[i] = c;
                i++;
            }
    }
    *l = g;
    return arr;
}

void dspace(char* arr, int* l, int f)
{
    int s = *l;
    for (int j = f; j < (s - 1); j++)
        arr[j] = arr[j + 1];
    s--;
    f--;
    arr = real(arr, s);
    *l = s;
}
void fspace(char* arr, int* l)
{
    int g = *l, u = 0;
    for (int i = 0; i < g; i++)
    {
        if ((arr[i] == ' ') && (arr[i + 1] == ' '))
        {
            dspace(arr, l, i);
            i--;
        }
    }
    if (arr[u] == ' ')
        dspace(arr, l, u);
}
int kolvo_slov(char* arr, int  l)
{
    int ch = 1;
    for (int i = 0; i < l; i++)
    {
        if (arr[i] == ' ')
            ch++;
    }
    return ch;
}
void mix(char* arr, int l)
{
    int g = l - 1;
    char temp;
    for (int i = 0; i < l / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[g];
        arr[g] = temp;
        g--;
    }

}
void perevorot(char* arr, int l, int k)
{
    char* clovo = NULL;
    int ch = 1, g = 0;
    clovo = (char*)calloc(l, sizeof(char));
    for (int i = 0; i < l; i++)
    {
        if (arr[i] == ' ')
            ch++;
        if ((ch == k) && (arr[i] != ' '))
        {
            clovo[g] = arr[i];
            g++;
        }
    }
    mix(clovo, g);
    ch = 1;
    g = 0;
    for (int i = 0; i < l; i++)
    {
        if (arr[i] == ' ')
            ch++;
        if ((ch == k) && (arr[i] != ' '))
        {
            arr[i] = clovo[g];
            g++;
        }
    }
}