#include <stdio.h>
#include <math.h>
int main() {
	int R, KV;
	printf("vvedita rabiys kryga i ctorony kvadrata\n");
	scanf_s("%d%d", &R, &KV);//ввод радиуса и стороны квадрата
	//Тут вводится сначало радиус круга, а потом сторона квадрата;
	if ((sqrt(2)) * KV <= 2 * R)
		//сторона квадрата умноженое на корень из 2 меньше, чем 2 радиуса круга;
		printf("True");
	else 
		printf("False");
	return 0;
}
