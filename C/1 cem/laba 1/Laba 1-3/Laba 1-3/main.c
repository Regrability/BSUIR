#include <stdio.h>;
#include <math.h>;
int main() {
	float a, b, c, a1, b1, c1;//3 числа для ввода, 3 для округ
	int ch;//это мой счётчик
	printf("vvedite 3 chicla\n");
	scanf_s("%f%f%f", &a, &b, &c);
	ch = 0;
	a1 = trunc(a);//отбрасываю дроб часть
	b1 = trunc(b);
	c1 = trunc(c);
	if (a - a1 == 0)//от числа отнимаю без дроби
		ch = ch + 1;
	if (b - b1 ==0)
		ch = ch + 1;
	if (c - c1 == 0)
		ch = ch + 1;


	printf("%d", ch);


	return 0;
}
