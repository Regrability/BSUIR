#include "Roman.h";
int main(int argc, char** argv[])
{
	int n;
    char buffer[1024];
    printf("Enter your string: ");
    input_string(buffer, 1024);
	FILE* f = NULL;
	fvvod(f, buffer, argc, argv);//���� � ����
	printf("enter how many characters to shift:");
	n = vvod();//���-�� �� ������� ��������
	encrypt(n, argc, argv);//��� ����
	fvivod(f, argc, argv);
	return 0;
}
