#include "Roman.h";
int main(int argc, char** argv[])
{
	int n;
    char buffer[1024];
    printf("Enter your string: ");
    input_string(buffer, 1024);
	FILE* f = NULL;
	fvvod(f, buffer, argc, argv);//ввод в файл
	printf("enter how many characters to shift:");
	n = vvod();//кол-во на сколько сдвинетс
	encrypt(n, argc, argv);//сам шифр
	fvivod(f, argc, argv);
	return 0;
}
