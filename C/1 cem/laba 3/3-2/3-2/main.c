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
void ydalenie(int arr1[], int n1)//основная движуха
{
	int j, y = n1;
	for (int i = 1; i < n1; i++)
	{
		if (((arr1[i] % 2 == 1) && (arr1[i]!=0)) || ((arr1[i] % 2 == -1) && (arr1[i] != 0)))//это нечетность
		{
			j = i;
			for (j; j < n1; j++)//это оно перезаписывает когда нашла нечётный начиная с этого элемента
			{
			arr1[j - 1] = arr1[j];
			}
			y = y - 1;//это мы убрали общее кол-во с перезаписанными для вывода
			--n1;//мы перезаписали поэтому поселдние тоже сдвинулось
		}
	 if ((((arr1[i - 1] % 2 == 1) && (arr1[i - 1] != 0)) || ((arr1[i - 1] % 2 == -1) && (arr1[i - 1] != 0))) && (((arr1[i] % 2 == 1) && (arr1[i]!=0)) || ((arr1[i] % 2 == -1) && (arr1[i] != 0))) )
			--i;//это если удут подряд нечётные чтобы не пропустило
	}
	printf("\n\n");
	for (int i = 0; i < y; i++)//это вывод
	{
	printf("%d ", arr1[i]);

	}
	return 0;
}
int main()
{	int n, k, arr[100];
	printf("vvedino kolvo chlenov v massive(maksi 100)\n");
	n = numinputrange(1, 100);
	printf("vvedite cami(1) ili random(2)\n");//тут выбор сам или нет
	k = numinputrange(1, 2);
	if (k == 1) {
		for (int i = 0; i < n; i++) {
			printf("a[%d] = ", i);//вручную
			arr[i] = numinputrange(-100000000, 100000000);}
		ydalenie(arr, n);}
	else if (k == 2) {
		srand(time(NULL));
		for (int i = 0; i < n; i++) {
			arr[i] = rand() % 200 - 100; // диапазон случайных чисед от 0 до 100
			printf("%d ", arr[i]);}//случайно
		printf("\n");
		ydalenie(arr, n);}
	return 0;
}