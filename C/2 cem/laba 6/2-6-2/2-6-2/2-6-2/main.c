#include <stdio.h>
#include <stdlib.h>
// ���������� ��������� ��� �������� �������
struct QueueNode
{
    int value;
    struct QueueNode* prev;
    struct QueueNode* next;
};
// ���������� ��������� ��� ��������������� ������� 
struct Deque
{
    struct QueueNode* head; // ��������� �� ������ �������
    struct QueueNode* tail; // ��������� �� ����� �������
};

void enqueue_front(struct Deque* deque, int value);
void enqueue_back(struct Deque* deque, int value);
void dequeue_front(struct Deque* deque);
void dequeue_back(struct Deque* deque);
void print_queue(struct Deque* deque);
void romka(struct Deque* deque);
int vvod();

int main() {
    struct Deque deque;
    deque.head = NULL;
    deque.tail = NULL;
    int buf;
    for (int i = 0; i < 3; i++)
    {
        printf("Enter elemens on right: \n");
        buf = vvod();
        enqueue_back(&deque, buf);
    }
    for (int i = 0; i < 3; i++)
    {
        printf("Enter elemens on left: \n");
        buf = vvod();
        enqueue_front(&deque, buf);
    }

    romka(&deque);
    return 0;
}
void enqueue_front(struct Deque* deque, int value)
{
    struct QueueNode* node = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    node->value = value;

    if (deque->head == NULL)
    {
        deque->head = node;
        deque->tail = node;
        node->prev = NULL;
        node->next = NULL;
    }
    else
    {
        node->next = deque->head;
        node->prev = NULL;
        deque->head->prev = node;
        deque->head = node;
    }
}
// ������� ��� ���������� �������� � ����� �������
void enqueue_back(struct Deque* deque, int value) {
    struct QueueNode* node = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    node->value = value;

    if (deque->tail == NULL) {
        deque->head = node;
        deque->tail = node;
        node->prev = NULL;
        node->next = NULL;
    }
    else {
        node->prev = deque->tail;
        node->next = NULL;
        deque->tail->next = node;
        deque->tail = node;
    }
}
// ������� ��� �������� �������� � ������ �������
void dequeue_front(struct Deque* deque) {
    if (deque->head == deque->tail) {
        free(deque->head);
        deque->head = NULL;
        deque->tail = NULL;
    }
    else {
        struct QueueNode* temp = deque->head;
        deque->head = deque->head->next;
        deque->head->prev = NULL;
        free(temp);
    }
}
// ������� ��� �������� �������� � ����� �������
void dequeue_back(struct Deque* deque) {
    if (deque->head == deque->tail) {
        free(deque->tail);
        deque->head = NULL;
        deque->tail = NULL;
    }
    else {
        struct QueueNode* temp = deque->tail;
        deque->tail = deque->tail->prev;
        deque->tail->next = NULL;
        free(temp);
    }
}
// ������� ��� ������ �� ����� ���� ��������� �������
void print_queue(struct Deque* deque) {
    struct QueueNode* current = deque->head;
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

void romka(struct Deque* deque) {
    struct QueueNode* current = deque->tail;
    int block = 0, ch = 6;
    while (current != NULL && block == 0)
    {
        if (current->value < 0)
        {
            block = 1;
        }
        ch--;
        printf("%d ", current->value);
        current = current->prev;
    }

    printf("\nnumber of elements left in deck: %d\n", ch);

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