#include <stdio.h>
#define SIZE_MAS 100
#define SIZE_MIN 0
#define VIBOR_MIN 1
#define VIBOR_MAX 2
int numinputrange(int min, int max);
void matcica(int n1, int m1, int  arr[SIZE_MAS][SIZE_MAS]);
void poradok(int n, int m, int  a[SIZE_MAS][SIZE_MAS]);
int vvod();
int main() {//всё как в аервой проге
    int b[SIZE_MAS][SIZE_MAS];
    int n, m, k;
    printf("write kol-vo ctolbcev\n");
    m = numinputrange(SIZE_MIN, SIZE_MAS);
    printf("write kol-vo ctrochek\n");
    n = numinputrange(SIZE_MIN, SIZE_MAS);
    printf("vvedite 2 chiclo(cami-1; random-2)\n");
    k = numinputrange(VIBOR_MIN, VIBOR_MAX);//тут выбор сам или нет
    if (k == 1) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                printf("\nb[%d][%d]=", i + 1, j + 1);
                b[i][j] = vvod(); } }
    if (k == 2){
        srand(time(NULL));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                b[i][j] = rand() % 199 - 99; }
    matcica(n, m, b);
    poradok(n, m, b);
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
void matcica(int n1, int m1, int  arr[SIZE_MAS][SIZE_MAS]) {
    printf("matric\n");
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m1; j++)
            printf("%3d   ", arr[i][j]);
        printf("\n");
    }
}
void poradok(int n, int m, int  a[SIZE_MAS][SIZE_MAS])
{
    int ch = 0, bloc = 0, poiman;
    for (int i = 0; i < n; i++)//поиск первой строки в которой эл-ты по убыванию
    {
        for (int j = 0; j < m - 1; j++)
            if (a[i][j] > a[i][j + 1])
            {
                ch = ch + 1;
            }
        if ((m - 1 == ch) && (bloc == 0))
        {
            poiman = i;
            bloc = 1;
            printf("strochka nomer %d\n", poiman+1);
        }
        ch = 0;
    }
    if (bloc == 1)
    {
        for (int i = 0; i < m - 1; i++)//перестановка пузырьком(максимальный в конец)
        {
            for (int j = 0; j < m - i - 1; j++) {
                if (a[poiman][j] > a[poiman][j + 1])
                {
                    int tmp = a[poiman][j];
                    a[poiman][j] = a[poiman][j + 1];
                    a[poiman][j + 1] = tmp;
                }
            }
        }
    }
    printf("matric 2\n");//вывод матрицы
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%3d   ", a[i][j]);
        printf("\n");
    }
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


