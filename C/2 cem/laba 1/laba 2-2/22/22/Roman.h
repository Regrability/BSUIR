#include <stdlib.h>
#include <io.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <share.h>
#define _CRT_SECURE_NO_WARNINGS
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