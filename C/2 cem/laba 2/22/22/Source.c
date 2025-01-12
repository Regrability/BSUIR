#include "Roman.h";


int main(int argc, char** argv[])
{
	char* arr = NULL;
	int l = 0;
	printf("Input string:\n");
	arr = memory(arr, &l);
	FILE* f = NULL;
	fvvod(f, arr, argc, argv);
	povtorachka(f, argc, argv);
	perevorot(f, argc, argv);
	fvivod(f, argc, argv);
	return 0;
}
