#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct FIFO 
{
	int data;
	struct FIFO* next;
	struct FIFO* prev;
};
struct FIFO* create(struct FIFO*, int); 
void print(struct FIFO*); 
struct FIFO* pop(struct FIFO* head);
int vvod();


int main()
{
	int i, x;
	struct FIFO* head;   
	head = NULL;
	struct FIFO* tail;    
	tail = NULL;
	printf("Enter 6 elements:\n");
	for (i = 0; i < 6; i++) 
	{
		x = vvod();
		tail = create(tail, x);
		if (head == NULL)
			head = tail;

	}
	printf("\n");
	print(head);
	free(head);
}

struct FIFO* create(struct FIFO* tail, int x) {
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
	int flag = 0, ch = 0;
	while ((head != NULL) && (flag == 0))
	{     
		printf("%d  ", head->data);
		if (head->data < 0)
		{
			flag = 1;
		}
		ch++;
		head = head->next;       
	}
	printf("\nnumber of element's, that left in the queue: %d", 6 - ch);
	printf("\n");
}
struct FIFO* pop(struct FIFO* head)
{
	if (head != NULL)
	{
		head = head->next;
		return head;
	}
	else return NULL;

}

