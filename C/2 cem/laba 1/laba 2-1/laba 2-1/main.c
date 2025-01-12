#include "Rman.h";
int main(int argc, char** argv[])
{


	FILE* f=NULL;
	int ch;
	fvod(f, argc, argv);
	ch = kraineechislo(f, argc, argv);
	ydalenie(ch, f, argc, argv);
	fvvivid(f, argc, argv);
	return 0;
}