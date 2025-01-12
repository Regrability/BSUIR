#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <io.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <share.h>
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

int fvvod(FILE* f,char* arr, int argc, char** argv[])
{
    if ((f = fopen(argv[1], "w")) == NULL)
    {
        printf("Cannot open file.\n");
        return 0;
    }
    fputs(arr, f);
    fclose(f);


    return 0;
}
int povtorachka(FILE* f, int argc, char** argv[])
{
    int ch = 0;
    char simvol, buf;
 

    if ((f = fopen(argv[1], "r")) == NULL)
    {
        printf("Cannot open file.\n");
        return 0;
    }
    printf("Input simvol:\n");
    scanf_s("%c", &simvol);
    while (!feof(f))
    {
        if ((fscanf(f, "%c", &buf)) > 0)
        {
            if (simvol == buf)
            {
                ch++;
            }
        }

    }
    printf("%d\n", ch);
    fclose(f);
    return 0;
}
int fvivod(FILE* f, int argc, char** argv[])
{
  //  rewind(f);
    char c[1000];
    if ((f = fopen(argv[1], "r")) == NULL)
    {
        printf("Cannot open file.\n");
        return 0;
    }
    while (!feof(f))
    {
        if (fgets(c, 1000, f) != NULL)
            printf("%s", c);
    }
    fclose(f);
    return 0;
}

int perevorot(FILE* f, int argc, char** argv[])
{
    int first, last, raznitca;
    char buf, guf;

    printf("vvedite nachalo clova ");
    first = vvod();
    printf("vvedite konec clova ");
    last = vvod();
    if ((f = fopen(argv[1], "r+")) == NULL)
    {
        printf("Cannot open file.\n");
        return 0;
    }
    int n = (first + last) / 2;
    if (n % 2 != 0)
        n++;
    for (first; first < n; )
    {
        fseek(f, first, SEEK_SET);
        buf = fgetc(f);
        fseek(f, last, SEEK_SET);
        guf = fgetc(f);


        fseek(f, first, SEEK_SET);
        fputc(guf, f);
        fseek(f, last, SEEK_SET);
        fputc(buf, f);
        first++;
        last--;
    }
    fclose(f);

  

    return 0;
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
    arr[g] = '\0';
    return arr;
}
char* memory(char* arr, int* l)
{
    arr = (char*)calloc(1, sizeof(char));
    arr = input(arr, l);
    return arr;
}
