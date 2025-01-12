#include <stdio.h>
#define SIZE_MAS 100
#define SIZE_MIN 0
#define VIBOR_MIN 1
#define VIBOR_MAX 2
int vvod();
int numinputrange(int min, int max);
void matcica(int n1, int  arr[SIZE_MAS][SIZE_MAS]);
void cymma(int n1, int  arr[SIZE_MAS][SIZE_MAS]);
int main() {//всё как во 2 задаче но теперь тока n
    int b[SIZE_MAS][SIZE_MAS];
    int n, k;
    printf("write kol-vo ctrochek i ctolbcev\n");
    n = numinputrange(SIZE_MIN, SIZE_MAS);
    printf("vvedite 2 chiclo(cami-1; random-2)\n");
    k = numinputrange(VIBOR_MIN, VIBOR_MAX);//тут выбор сам или нет
    if (k == 1){
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {  printf("\nb[%d][%d]=", i + 1, j + 1);
                b[i][j] = vvod();} }
    if (k == 2){    srand(time(NULL));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                b[i][j] = rand() % 199 - 99;}
    matcica(n, b);
    cymma(n, b);
    return 0;}
int numinputrange(int min, int max)
{
    int var;
    while ((scanf_s("%d", &var) == 0) || (var < min) || (var > max) || getchar() != '\n')
    {
        printf("wrong input! try again\n");
        rewind(stdin);
    }
    return var;
}
void matcica(int n1, int  arr[SIZE_MAS][SIZE_MAS]) {
    printf("matric\n");
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n1; j++)
            printf("%3d   ", arr[i][j]);
        printf("\n");
    }
}
void cymma(int n1, int  arr[SIZE_MAS][SIZE_MAS])
{
    int cum = 0;
    for (int j = 0; j < n1; j++)
    {
        for (int i = 0 + j; i < n1 - j; i++)//откидываем столбы сверху и снизу на j, на середине i станет слишком большим и не будет запускать
        {
            cum = cum + arr[i][j];
            printf("cymmiryetca element [%d][%d]=%d \n", i+1, j+1, arr[i][j]);
        }

    }
    printf("cymma 4 chetverti %d \n", cum);
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


