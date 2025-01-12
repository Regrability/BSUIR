#include <stdio.h>
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
void kracivivivod(int chiclo1[], int chiclo2[]) {
	printf("\n\n ");
	for (int i = 0; i < 20; i++)
	{
		printf("%d ", chiclo1[i]);
	}
	printf("\n+\n ");
	for (int i = 0; i < 20; i++)
	{
		printf("%d ", chiclo2[i]);
	}
	printf("\n-----------------------------------------\n");
	return 0;
}
void cymma(int chiclo1[], int chiclo2[]) {
	int a[100];
	int razrad = 0;
	for (int i = 19; i > 0; i--)
	{
		a[i] = ((chiclo1[i] + chiclo2[i] + razrad) % 10);
		razrad = (int)((chiclo1[i] + chiclo2[i]) / 10);
	}
	a[0]=razrad + chiclo1[0] + chiclo2[0];

	for (int i = 0; i < 20; i++)
	{
		printf("%d ", a[i]);
	}

	return 0;
}
int main()
{
	int k, chiclo1[100], chiclo2[100];
	printf("vvedite 1 chiclo(cami-1; random-2)\n");
	k = numinputrange(1, 2);//тут выбор сам или нет
	if (k == 1)
	{
		for (int i = 0; i < 20; i++)
			chiclo1[i] = numinputrange(-32000, 1000000);
	}
	else if (k == 2)
	{
		srand(time(NULL));
		for (int i = 0; i < 20; i++)
		{
			chiclo1[i] = rand() % 10;
			printf("%d ", chiclo1[i]);//случайно
		}
		printf("\n");
	}
	printf("vvedite 2 chiclo(cami-1; random-2)\n");
	k = numinputrange(1, 2);//тут выбор сам или нет
	if (k == 1)
	{
		for (int i = 0; i < 20; i++)
			chiclo2[i] = numinputrange(-1000000, 1000000);
	}
	else if (k == 2)
	{
		srand(time(NULL));
		for (int i = 0; i < 20; i++)
		{
			chiclo2[i] = rand() % 10;
			printf("%d ", chiclo2[i]);//случайно
		}
		printf("\n");
	}
	kracivivivod(chiclo1, chiclo2);
	cymma(chiclo1, chiclo2);
	return 0;
}