#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <io.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <share.h>
#define ENG 26
char* input_string(char* buffer, int buffer_size) {
    if (fgets(buffer, buffer_size, stdin) != NULL) {
        int length = strlen(buffer);
        if (buffer[length - 1] == '\n') {
            buffer[length - 1] = '\0';
        }
    }
    return buffer;
}
void encrypt(int n, int argc, char** argv[])
{
    FILE* fp1, * fp2;
    fopen_s(&fp1, argv[1], "r");
    fopen_s(&fp2, "output.txt", "w");
    int flag;
    char c;
    c = getc(fp1);
    while (!feof(fp1))
    {
        flag = 0; //обработан ли текущий символ
        if (c >= 'A' && c <= 'Z')
        {
            c = c + (n % ENG);
            if (c > 'Z') c = 'A' + (c - 'Z') - 1;
            fprintf(fp2, "%c", c);
            flag = 1;
        }
        if (c >= 'a' && c <= 'z')
        {
            c = c + (n % ENG);
            if (c > 'z') c = 'a' + (c - 'z') - 1;
            fprintf(fp2, "%c", c);
            flag = 1;
        }
        if (!flag) fprintf(fp2, "%c", c);
        c = getc(fp1);
    }
    fclose(fp1);
    fclose(fp2);
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
int fvivod(FILE* f, int argc, char** argv[])
{
    char c[1000];
    if ((f = fopen("output.txt", "r")) == NULL)
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


