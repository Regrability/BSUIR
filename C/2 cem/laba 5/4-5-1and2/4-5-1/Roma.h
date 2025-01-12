#include <stdio.h>
#include <stdlib.h>
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
struct Stack
{
    int* data;
    int top;
};
void push(struct Stack* s, int value, int SIZE)
{
    if (s->top == SIZE - 1) { // проверка на переполнение
        printf("Error in add: steck is full\n");
        exit(1);
    }
    s->top++;
    s->data[s->top] = value;
}
int pop(struct Stack* s)
{
    if (s->top == -1) { // проверка на пустоту
        printf("Error in delete: steck is empty\n");
        exit(1);
    }
    int value = s->data[s->top];
    s->top--;
    return value;
}
int vvod_stack(struct Stack* s)
{
    int maxSize;
    printf("Enter the maximum stack size: ");
    maxSize = vvod();
    s->data = (int*)calloc(maxSize, sizeof(int));
    s->top = -1; // инициализаци€ стека
    // заполнение стека
    for (int i = 0; i < maxSize; i++) {
        int value;
        printf("Enter elemnt #%d: ", i + 1);
        value = vvod();
        push(s, value, maxSize);
    }
    return maxSize;
}
void sumStack_aftermax(struct Stack* s)
{
    int sumAfterMax = 0;
    // поиск максимального элемента
    int max = s->data[s->top];
    int maxPos = s->top;
    for (int i = s->top - 1; i >= 0; i--) {
        if (s->data[i] > max) {
            max = s->data[i];
            maxPos = i;
        }
    }
    // суммирование элементов после максимального
    for (int i = maxPos + 1; i <= s->top; i++)
    {
        sumAfterMax += s->data[i];
    }
    printf("Sum of elements after maximum: %d\n", sumAfterMax);
}
void printStack(struct Stack* s)
 {
    printf("stack:\n");
    for (int i = 0; i < s->top + 1; i++)
        printf("%d\n", s->data[i]);
}
void sort(struct Stack* s1, struct Stack* s2, struct Stack* s3, int size1, int size2)
{
    int MAX_SIZE, i;
    int* buf = NULL;
    buf = (int*)calloc(size2, sizeof(int));
    if (buf == NULL)
    {
        printf("Error");
        exit(1);
    }
    for (i = size2 - 1; i > -1; i--)
    {
        buf[i] = pop(s2);
    }
    MAX_SIZE = size1 + size2;
    s3->data = (int*)calloc(MAX_SIZE, sizeof(int));
    s3->top = -1;
    i = 0;
    while (s1->top != -1 && i < size2)
    { // ѕока оба стека не пусты
        if (s1->data[s1->top] > buf[i]) // ≈сли верхний элемент первого стека больше нижнего элемента второго стека
            push(s3, pop(s1), MAX_SIZE); // ƒобавл€ем верхний элемент первого стека в новый стек
        else
        {
            push(s3, buf[i], MAX_SIZE); // »наче добавл€ем верхний элемент второго стека в новый стек
            i++;
        }
    }
    while (s1->top != -1) // ≈сли первый стек еще не пустой, добавл€ем его оставшиес€ элементы в новый стек
        push(s3, pop(s1), MAX_SIZE);
    while (i < size2) // ≈сли второй стек еще не пустой, добавл€ем его оставшиес€ элементы в новый стек
    {
        push(s3, buf[i], MAX_SIZE);
        i++;
    }
    free(buf);
}