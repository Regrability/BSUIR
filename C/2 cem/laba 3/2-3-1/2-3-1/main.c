#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <io.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <share.h>
int main()
{
    int num = 5; 

    if (num & (1 << (sizeof(int) * 8 - 1)))
    {
        printf("otricatelnoe\n");
    }
    else {
        printf("polojitelnoe\n");
    }
    return 0;
}