#include <stdio.h>
#define SIZE_MAS 100
int numinputrange(int min, int max)
{
	int var;
	while ((scanf_s("%d", &var) == 0) || (var < min) || (var>max) || getchar() != '\n')
	{
		printf("wrong input! try again\n");
		rewind(stdin);
	}
	return var;
}
void proizvedenie(int arr2[], int n2)
{
	int ch = 0, p=1, ch1=0, a=0;

	for (int i = 0; i < n2; i++)
	{
		if ((arr2[i] == 0)&&(a==0))//посик первого 0
		{
			ch1 = i;
			a = 1;
		}
	}
	if (arr2[ch1] == arr2[ch1 + 1]) {
		printf("dva pervix 0 radom");
	}
	else {
		for (int i = ch1; i < n2; i++)
		{
			if (arr2[i] == 0)//флажок +1 если нашёл 0
				ch = ch + 1;
			if (ch == 1)//само произведение
				p = p * arr2[i];
			if (p == 0)//чтобы 1 ноль ничего не заруинил
				p = 1;
		}
		if (ch == 1)//защита от одного нуля
			printf("ect 1 0-oi element");
		else if (ch == 0)
			printf("nety 0-ix elementov\n");
		else
			printf("proizvedenie mejdy 0-imi elementami: %d\n", p);

	}
		return 0;
}
void maks(int arr1[], int n1)
{
	int max=arr1[0];
	for (int i = 0; i < n1; i++)
	{//всё сравнивает с 1
		if (arr1[i] > max)
			max = arr1[i];
	}
	for (int i = 0; i < n1; i++)
	{//всё сравнивает с максимальным
		if (arr1[i] == max)
			printf("maksimalni element pod nomerom: %d\n", i+1);
	}
	return 0;
}
int main() 
{
	int n, k;
	int arr[SIZE_MAS];
	    printf("vvedino kolvo chlenov v massive(maksi 100)\n");
		n = numinputrange(1, SIZE_MAS);
		printf("vvedite cami(1) ili random(2)\n");//тут выбор сам или нет
		k = numinputrange(1, 2);
		if (k == 1){
			for (int i = 0; i < n; i++){
				printf("a[%d] = ", i);//вручную
				arr[i] = numinputrange(-100000000, 100000000);}
			maks(arr, n);
			proizvedenie(arr, n);}
		else if (k == 2){
			srand(time(NULL));
			for (int i = 0; i < n; i++){
				arr[i] = rand() % 200 - 100; // диапазон случайных чисед от 0 до 100
				printf("%d ", arr[i]);}//случайно
			printf("\n");
			maks(arr, n);
			proizvedenie(arr, n);}
	return 0;}