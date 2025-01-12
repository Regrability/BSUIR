#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct FILO
{
	int data;
	struct FILO* next;
};

struct FILO* create(struct FILO*, int x);
void print(struct FILO* head);
int maxi(struct FILO* head);
int vvod();
int main()
{
	int a, size;
	struct FILO* head;
	head = NULL;
	printf("write stack size: ");
	size = vvod();
	for (int i = 0; i < size; i++)
	{
		a = vvod();
		head = create(head, a);
	}
	printf("\n");
	print(head);
	maxi(head);
	free(head);
	return 0;
}

struct FILO* create(struct FILO* head, int x) {
	struct FILO* n;
	n = (struct FILO*)malloc(sizeof(struct FILO));
	if (n == NULL)
	{
		printf("error with allocation of memory");
		exit(1);
	}
	n->next = NULL;
	n->data = x;
	if (head == NULL)
		head = n;
	else
	{
		n->next = head;
		head = n;
	}
	return head;
}


void print(struct FILO* head) {
	struct FILO* p = head;
	while (p != NULL) {
		printf("%2d ---> ", p->data);
		p = p->next;
	}
	printf("NULL\n");
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
int maxi(struct FILO* head)
{
	struct FILO* p = head;
	int s = 0, max, flag = 0;


	while (p != NULL)//поиск максимального чётного элемента
	{
		if (p->data % 2 == 0)
		{
			max = p->data;
			flag = 1;
		}
		p = p->next;
	}
	if (flag == 0)
	{
		printf("no even stack element");
	}
	else
	{
		p = head;
		while (p != NULL)
		{
			if ((p->data > max) && (p->data % 2 == 0))
			{
				max = p->data;
			}
			p = p->next;
		}
		printf("maximum even stack element: %d", max);
	}

	return 0;
}