#include "Roma.h";
int main()
{
    struct Stack s;
    struct Stack s1;
    struct Stack s2;
    struct Stack s3;
    int size1, size2;
    printf("Task #1\n---------------------------------\n");
    vvod_stack(&s);
    sumStack_aftermax(&s);
    printStack(&s); // Выводим элементы нового стека на экран
    printf("\n---------------------------------\n");

    printf("Task #2\n---------------------------------\n");
    printf("Enter elements on ascending\n");
    size1 = vvod_stack(&s1);
    printf("Enter elements on descending\n");
    size2 = vvod_stack(&s2);
    sort(&s1, &s2, &s3, size1, size2);
    printf("Sort elements on descending\n");
    printStack(&s3);
    printf("\n---------------------------------\n");
    return 0;
}