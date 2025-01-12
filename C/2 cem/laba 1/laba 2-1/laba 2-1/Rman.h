#include <io.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <share.h>
#include <stdlib.h>
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

int vvod2()
{
	int var;
	while ((scanf_s("%d", &var) == 0) || (getchar() != '\n') || (var < 0))
	{
		printf("wrong input! try again\n");
		rewind(stdin);
	}
	return var;
}
int kraineechislo(FILE* f, int argc, char** argv[])
{
	int buf, guf, ch = 1, bloc = 0;

	fopen_s(&f, argv[1], "rb");//крайнее число
	if (f == NULL)
	{
		printf("Cannot open file.\n");
		return 0;
	}
	fread(&guf, 1, sizeof(guf), f);
	while (!feof(f))
	{
		fread(&buf, 1, sizeof(buf), f);

		if ((buf > guf) && (bloc == 0))
		{
			ch++;
			guf = buf;
		}
		else bloc = 1;
	}
	printf("krainee chislo - %d\n", ch);
	fclose(f);
	return ch;
}
int ydalenie(int ch, FILE* f, int argc, char** argv[])
{
	int guf, n;
	fopen_s(&f, argv[1], "rb");//крайнее число
	if (f == NULL)
	{
		printf("Cannot open file.\n");
		return 0;
	}
	int* mas;
	mas = (int*)calloc(ch, sizeof(int));
	if (mas == NULL)
	{
		return 0;
	}
	for (int i = 0; i < ch; i++)
	{
		fread(&guf, 1, sizeof(guf), f);
		mas[i] = guf;
	}
	printf("\n\n");
	fclose(f);



	fopen_s(&f, argv[1], "wb");//перезаписывание
	if (f == NULL)
	{
		printf("Cannot open file.\n");
		return 0;
	}
	for (int i = 0; i < ch; i++)
	{
		n = mas[i];
		fwrite(&n, 1, sizeof(n), f);
	}
	fclose(f);
	return 0;
}

int fvod(FILE* f, int argc, char** argv[])
{

	int a, n;
	fopen_s(&f, argv[1], "wb");//ввод
	if (f == NULL)
	{
		printf("Cannot open file.\n");
		return 0;
	}
	printf("vvedite kolichectvo chicel\n");
		a = vvod2();
		printf("\n\n");
		for (int i = 0; i < a; i++)
		{
			n = vvod();
			fwrite(&n, 1, sizeof(n), f);
		}
	fclose(f);
	printf("\n\n");
	return 0;
}
int fvvivid(FILE* f, int argc, char** argv[])
{
	int buf;
	fopen_s(&f, argv[1], "r");//вывод
	if (f == NULL)
	{
		printf("Cannot open file.\n");
		return 0;
	}
	while (!feof(f))
	{
		if ((fread(&buf, 1, sizeof(buf), f)) > 0)
			printf("%d\n", buf);
	}
	fclose(f);


	return 0;

}