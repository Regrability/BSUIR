#include <stdio.h>
#include <math.h>
int main() {
	int R, KV;
	printf("vvedita rabiys kryga i ctorony kvadrata\n");
	scanf_s("%d%d", &R, &KV);//���� ������� � ������� ��������
	//��� �������� ������� ������ �����, � ����� ������� ��������;
	if ((sqrt(2)) * KV <= 2 * R)
		//������� �������� ��������� �� ������ �� 2 ������, ��� 2 ������� �����;
		printf("True");
	else 
		printf("False");
	return 0;
}
