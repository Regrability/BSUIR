#include <stdio.h>
int main() {
	float C1, C2;//���� � ������ � ������ ������
	printf("vvedite litri v cocydax\n");
	while (scanf_s("%f", &C1) != 1)//�������� �� ������������ ����
	{
		while (getchar() != '\n')
			continue;
		printf("ERROR\n");
		printf("Vvedite chiclo\n");
	}
	while (scanf_s("%f", &C2) != 1)//�������� �� ������������ ����
	{
		while (getchar() != '\n')
			continue;
		printf("ERROR\n");
		printf("Vvedite chiclo\n");
	}
	if ((C1 >= 0) && (C2 >= 0))//���� ��� �� �������������
	{
		for (int i = 0; i < 12; i++) {//��� ���� �������� 12 ���
			C1 = C1 * 0.5;
			C2 = C2 + C1;
			C2 = C2 * 0.5;
			C1 = C1 + C2;
		}
		printf("%.3f and %.3f", C1, C2);
	}
	else//���� ��� �������������
		printf("ne mojet bic otricatelnim");
	return 0;
}
