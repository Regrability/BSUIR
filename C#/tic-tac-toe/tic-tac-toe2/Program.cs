using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace tic_tac_toe2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            char[,] mas = new char[3, 3];
            byte win = 0, pos, i=0;
            byte[] ban = new byte[9];
            inicializ_mas(mas, ban);
            while (win == 0)
            {
                print(mas);
                Console.WriteLine("\n\nPlayer 1 chooses a position:");
                pos = NumInputRange(1, 9, ban);
                ban[i] = pos; i++;
                vvod_x(mas, pos);
                Console.Clear();
                win = winer_1(mas, win);
                if ((i == 9) && (win==0))
                    win = 3;
                if ((win != 1) && (i != 9))
                {
                    print(mas);
                    Console.WriteLine("\n\nPlayer 2 chooses a position:");
                    pos = NumInputRange(1, 9, ban);
                    ban[i] = pos; i++;
                    vvod_0(mas, pos);
                    Console.Clear();
                    win = winer_2(mas, win);
                }
            }
            print(mas);
            if (win == 1)
            {
                Console.WriteLine("\n\nPlayer 1 win's");
            }
            if (win == 2)
            {
                Console.WriteLine("\n\nPlayer 2 win's");
            }
            if (win == 3)
            {
                Console.WriteLine("\n\nIt's draw");
            }
        }
        static void inicializ_mas(char[,] arr, byte[] ban)
        {
            int n;
            for (n = 0; n < 3; n++)
            {
                for (int m = 0; m < 3; m++)
                {
                    arr[n, m] = ' ';

                }
            }
            for (n = 0; n < ban.Length; n++)
            {
                ban[n] = 0;
            }
        }
        static void print(char[,] mas)
        {
            Console.WriteLine("\n\n\n                 {0} | {1} | {2}                 1 | 2 | 3", mas[0, 0], mas[0, 1], mas[0, 2]);
            Console.WriteLine("                ------------              -----------");
            Console.WriteLine("                 {0} | {1} | {2}                 4 | 5 | 6", mas[1, 0], mas[1, 1], mas[1, 2]);
            Console.WriteLine("                ------------              -----------");
            Console.WriteLine("                 {0} | {1} | {2}                 7 | 8 | 9", mas[2, 0], mas[2, 1], mas[2, 2]);
        }
        static void vvod_x(char[,] arr, byte p)
        {
            switch (p)
            {
                case 1:
                    arr[0, 0] = 'x';
                    break;
                case 2:
                    arr[0, 1] = 'x';
                    break;
                case 3:
                    arr[0, 2] = 'x';
                    break;
                case 4:
                    arr[1, 0] = 'x';
                    break;
                case 5:
                    arr[1, 1] = 'x';
                    break;
                case 6:
                    arr[1, 2] = 'x';
                    break;
                case 7:
                    arr[2, 0] = 'x';
                    break;
                case 8:
                    arr[2, 1] = 'x';
                    break;
                case 9:
                    arr[2, 2] = 'x';
                    break;
            }


        }
        static void vvod_0(char[,] arr, byte p)
        {
            switch (p)
            {
                case 1:
                    arr[0, 0] = '0';
                    break;
                case 2:
                    arr[0, 1] = '0';
                    break;
                case 3:
                    arr[0, 2] = '0';
                    break;
                case 4:
                    arr[1, 0] = '0';
                    break;
                case 5:
                    arr[1, 1] = '0';
                    break;
                case 6:
                    arr[1, 2] = '0';
                    break;
                case 7:
                    arr[2, 0] = '0';
                    break;
                case 8:
                    arr[2, 1] = '0';
                    break;
                case 9:
                    arr[2, 2] = '0';
                    break;
            }

        }
        static byte NumInputRange(int min, int max, byte[] ban)
        {
            byte var;
            bool inputIsValid;

            do
            {
                Console.Write("Enter number from {0} to {1}: ", min, max);
                inputIsValid = byte.TryParse(Console.ReadLine(), out var);
                if (!inputIsValid || var < min || var > max || var == ban[0] || var == ban[1] || var == ban[2] || var == ban[3] || var == ban[4] || var == ban[5] || var == ban[6] || var == ban[7] || var == ban[8])
                {
                    Console.WriteLine("Try again");
                }
            } while (!inputIsValid || var < min || var > max || var == ban[0] || var == ban[1] || var == ban[2] || var == ban[3] || var == ban[4] || var == ban[5] || var == ban[6] || var == ban[7] || var == ban[8]);

            return var;
        }
        static byte winer_1(char[,] mas, byte win) 
        {
            if ((mas[0,0] == mas[0,1]) && (mas[0, 0] == mas[0, 2]) && (mas[0,0] == 'x'))
            { return 1;}
            if ((mas[1, 0] == mas[1, 1]) && (mas[1, 0] == mas[1, 2]) && (mas[1, 0] == 'x'))
            { return 1; }
            if ((mas[2, 0] == mas[2, 1]) && (mas[2, 0] == mas[2, 2]) && (mas[2, 0] == 'x'))
            { return 1; }
            if ((mas[0, 0] == mas[1, 0]) && (mas[0, 0] == mas[2, 0]) && (mas[0, 0] == 'x'))
            { return 1; }
            if ((mas[0, 1] == mas[1, 1]) && (mas[0, 1] == mas[2, 1]) && (mas[0, 1] == 'x'))
            { return 1; }
            if ((mas[0, 2] == mas[1, 2]) && (mas[0, 2] == mas[2, 2]) && (mas[0, 2] == 'x'))
            { return 1; }
            if ((mas[0, 0] == mas[1, 1]) && (mas[0, 0] == mas[2, 2]) && (mas[0, 0] == 'x'))
            { return 1; }
            if ((mas[0, 2] == mas[1, 1]) && (mas[0, 2] == mas[2, 0]) && (mas[0, 2] == 'x'))
            { return 1; }
            return 0;
        }
        static byte winer_2(char[,] mas, byte win)
        {
            if ((mas[0, 0] == mas[0, 1]) && (mas[0, 0] == mas[0, 2]) && (mas[0, 0] == '0'))
            { return 2; }
            if ((mas[1, 0] == mas[1, 1]) && (mas[1, 0] == mas[1, 2]) && (mas[1, 0] == '0'))
            { return 2; }
            if ((mas[2, 0] == mas[2, 1]) && (mas[2, 0] == mas[2, 2]) && (mas[2, 0] == '0'))
            { return 2; }
            if ((mas[0, 0] == mas[1, 0]) && (mas[0, 0] == mas[2, 0]) && (mas[0, 0] == '0'))
            { return 2; }
            if ((mas[0, 1] == mas[1, 1]) && (mas[0, 1] == mas[2, 1]) && (mas[0, 1] == '0'))
            { return 2; }
            if ((mas[0, 2] == mas[1, 2]) && (mas[0, 2] == mas[2, 2]) && (mas[0, 2] == '0'))
            { return 2; }
            if ((mas[0, 0] == mas[1, 1]) && (mas[0, 0] == mas[2, 2]) && (mas[0, 0] == '0'))
            { return 2; }
            if ((mas[0, 2] == mas[1, 1]) && (mas[0, 2] == mas[2, 0]) && (mas[0, 2] == '0'))
            { return 2; }
            return 0;
        }
    }
}
