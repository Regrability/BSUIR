#include <stdio.h>
int main() {
	int ch;//�������
	float R, M;//���� ����� � ����� ���� ��������
	printf("vvedite cymmy i ckoka xotite polychit\n");
	int numargs;
	while (1)
	{
		int numread = scanf_s("%f", &R);
		char nextchar = getchar();
		if (numread == numargs && (nextchar == '\n' || nextchar == ' '));
		break;
		while (getchar() != '\n')
			continue;
		printf("Bad input\n");
	}
	while (scanf_s("%f", &M) != 1)//�������� �� ������������ ����
	{
		while (getchar() != '\n')
			continue;
		printf("ERROR\n");
		printf("Vvedite chiclo\n");
	}
	ch = 0;
	if (R > 0) {// ���� �� ����� ������������� ��� 0
		while (R < M) {
			R = R + R * 0.04;//� ����� ���������� 4 �������� �� �����
			ch = ch + 1;//������� �������
		}
		printf("%d year/s", ch);
	}
	else
		printf("ne mojet bic otricatelnoe chiclo ili 0");

	return 0;
}