#include <stdio.h>
int main() {
	char a,b,c, d;
	scanf_s("%c", &a);
	scanf_s("%c", &b);
	scanf_s("%c", &c);
	scanf_s("%c", &d);
	if ((a == 74) && (b == 117) && (c == 110) && (d == 117))
		printf("31");
	else if ((a == 70))
		printf("28/29");
	else if ((a == 77) && (b == 97) && (c == 114))
		printf("31");
	else if ((a == 65) && (b == 112))
		printf("30");
	else if ((a == 77) && (b == 97) && (c == 121))
		printf("31");
	else if ((a == 74) && (b == 117) && (c == 110))
		printf("30");
	else if ((a == 74) && (b == 117) && (c == 108))
		printf("31");
	else if ((a == 65) && (b == 117))
		printf("31");
	else if ((a == 83))
		printf("30");
	else if ((a == 79))
		printf("31");
	else if ((a == 78))
		printf("30");
	else if ((a ==68 ))
		printf("31");
	else
		printf("Nepravilni vvod");
	return 0;
}