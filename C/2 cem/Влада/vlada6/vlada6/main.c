#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct FIFO
{
	char data;
	struct FIFO* next;
	struct FIFO* prev;
};
struct FIFO* create(struct FIFO*, char x);
void print(struct FIFO* head);
int vvod();


int main()
{
	int size, i=0;
	char x, reference_character;
	struct FIFO* head;
	head = NULL;
	struct FIFO* tail;
	tail = NULL;
	printf("Enter size of queue: ");
	size = vvod();
	printf("Enter reference character: "); 
	rewind(stdin); // очищаем буфер ввода
	reference_character = getchar();
	while (i < size)
	{
		rewind(stdin); // очищаем буфер ввода
		x = getchar();
		if (x != reference_character)
		{
			printf("simbol: %c\n", x);
			tail = create(tail, x);
			if (head == NULL)
				head = tail;
			i++;
		}
		else
			i = size;//выход если эталонный символ
	}
	printf("\n");
	print(head);
	free(head);
}

struct FIFO* create(struct FIFO* tail, char x) 
{
	struct FIFO* n;
	n = (struct FIFO*)malloc(sizeof(struct FIFO));
	if (n == NULL)
	{
	printf("error in memory");
	exit(1);
	}
	n->next = NULL;
	n->prev = NULL;
	n->data = x;
	if (tail == NULL)
	{
		tail = n;
	}
	else
	{
		n->prev = tail;
		tail->next = n;

		tail = n;
	}
	return tail;
}
int vvod()
{
	int var;
	while ((scanf_s("%d", &var) == 0) || getchar() != '\n')
	{
		printf("wrong input! try again\n");
		rewind(stdin);
	}
	return var;
}
void print(struct FIFO* head)
{

	while (head != NULL)
	{
		printf("%c  ", head->data);
		head = head->next;
	}
	printf("\n");
}



