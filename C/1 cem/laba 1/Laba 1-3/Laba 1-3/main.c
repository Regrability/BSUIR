#include <stdio.h>;
#include <math.h>;
int main() {
	float a, b, c, a1, b1, c1;//3 ����� ��� �����, 3 ��� �����
	int ch;//��� ��� �������
	printf("vvedite 3 chicla\n");
	scanf_s("%f%f%f", &a, &b, &c);
	ch = 0;
	a1 = trunc(a);//���������� ���� �����
	b1 = trunc(b);
	c1 = trunc(c);
	if (a - a1 == 0)//�� ����� ������� ��� �����
		ch = ch + 1;
	if (b - b1 ==0)
		ch = ch + 1;
	if (c - c1 == 0)
		ch = ch + 1;


	printf("%d", ch);


	return 0;
}
