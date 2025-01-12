#include "Roman.h";
char* memory(char* arr, int* l)
{
    arr = (char*)calloc(256, sizeof(char));
    arr = input(arr, l);
    return arr;
}
int main()
{
    char* arr = NULL;
    int op, k, l = 0;
    printf("Input string:\n");
    arr = memory(arr, &l);
    fspace(arr, &l);
    op = kolvo_slov(arr, l);
    printf("Input number word for mix:\n");
    k = check(op);
    perevorot(arr, l, k);
    print(arr, l);
    free(arr);
    return 0;
}