#include <stdio.h>
int main() {
    int chacnoe;//��� �������
    float N, K;//��� ����� � �� ��� �������
    chacnoe = 0;
    printf("vvedite chislo i delitel\n");
         while (scanf_s("%f%f", &N, &K) != 2)//�������� �� ������������ ����
    {
    while (getchar() != '\n')
    continue;
    printf("ERROR\n");
    printf("Vvedite chiclo\n");
    }
  

    if ((N >= 0) && (N - (int)N == 0) && (K >= 0) && (K - (int)K == 0))//�������� �� ������ ��� ������� ����� ��
    {
        while (N - K >= 0) {
            N = N - K;//�������� � ������ �������� ���������
            chacnoe = chacnoe + 1;
        }
        printf("chacnoe ot delenia - %d, octatok - %.0f", chacnoe, N);
    }
    else{
        printf("vvedino otricatelnoe chiclo ili ne celoe");
        }
	return 0;
}