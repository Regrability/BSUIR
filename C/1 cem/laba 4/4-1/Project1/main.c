#include <stdio.h>
#define SIZE_MAS 100
#define SIZE_MIN 1
#define VIBOR_MIN 1
#define VIBOR_MAX 2
int numinputrange(int min, int max);
void nyli(int arr[SIZE_MAS][SIZE_MAS], int n1, int  m1);
void maks(int arr[SIZE_MAS][SIZE_MAS], int n2, int  m2);
int vvod();
int main() {
    int b[SIZE_MAS][SIZE_MAS];
    int n, m, k;
    printf("write kol-vo ctolbcev\n");
    m = numinputrange(SIZE_MIN, SIZE_MAS);
    printf("write kol-vo ctrochek\n");
    n = numinputrange(VIBOR_MIN, SIZE_MAS);
    printf("vvedite 2 chiclo(cami-1; random-2)\n");
    k = numinputrange(VIBOR_MIN, VIBOR_MAX);//тут выбор сам или нет
    if (k == 1){
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++){
                printf("\nb[%d][%d]=", i + 1, j + 1);//+1 чтобы нормально выводилось
                b[i][j] = vvod();} }
    if (k == 2){
        srand(time(NULL));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                b[i][j] = rand() % 199 - 99;}
    nyli(b,n,m);
    maks(b,n,m);
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
void nyli(int arr[][SIZE_MAS], int n1, int  m1)
{
    printf("matric\n");//просто вывод матрицы
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m1; j++)
            printf("%3d   ", arr[i][j]);
        printf("\n");
    }
    int ch = 0, a = 0;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m1; j++)
        {
            if (arr[i][j] == 0)//прокручивает строку, если нашЄл 0 то мен€ет счЄтчик
                ch = 1;
        }
        if (ch == 0)//если не нашЄл ноли то счЄтскик = 0
            a = a + 1;//кол-во строк без нолей
        ch = 0;
    }
    printf("kol-vo ctrok bez 0 elementa: %d\n", a);
    return 0;
}
void maks(int arr[][SIZE_MAS], int n2, int  m2)
{
    int maksi = -1000, ch = 0, bloc = 0;
    for (int i = 0; i < n2; i++)//прокручивает массив
    {
        for (int j = 0; j < m2; j++)
        {
            if (arr[i][j] > maksi)
            {
                for (int p = 0; p < n2; p++)//ещЄ один массив дл€ повтор€щек
                {
                    for (int o = 0; o < m2; o++)
                    {
                        if (arr[i][j] == arr[p][o])
                        {
                            ch = ch + 1;
                        }

                    }
                }
                if (ch > 1)
                {
                    maksi = arr[i][j];//если нашЄл повтор€шку, то перезапишет

                }
                ch = 0;
            }

        }

    }
    if (maksi != -1000)//такое макси если не нашЄл повтор€шек
        printf("maksimalni element: %d", maksi);
    else
        printf("nety elementa kotorii vstr 2 raza");
    return 0;
}
int vvod()
{
    int var;
    while ((scanf_s("%d", &var) == 0) ||  getchar() != '\n')
    {
        printf("wrong input! try again\n");
        rewind(stdin);
    }
    return var;
}