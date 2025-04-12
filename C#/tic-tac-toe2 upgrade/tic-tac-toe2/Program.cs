using System;
using System.Linq;

namespace tic_tac_toe2
{
    enum State
    {
        InProgress,
        PlayerOneWin,
        PlayerTwoWin,
        Draw
    }

    enum Player
    {
        One,
        Two
    }

    internal class Program
    {
        private const char SymbolOne = 'x';
        private const char SymbolTwo = '0';
        private const int MatrixSize = 3;
        private const int BannedSize = MatrixSize * MatrixSize;

        static void Main(string[] args)
        {
            char[,] matrix = new char[MatrixSize, MatrixSize];
            byte[] banned = new byte[BannedSize];
            byte bannedIndex = 0;
            State state = State.InProgress;
            
            Initialize(matrix, banned);
            
            while (state == State.InProgress)
            {
                Print(matrix);
                state = Play(matrix, banned, ref bannedIndex, Player.One);

                if (state == State.InProgress)
                {
                    Print(matrix);
                    state = Play(matrix, banned, ref bannedIndex, Player.Two);
                }
            }

            Print(matrix);

            switch (state)
            {
                case State.PlayerOneWin:
                    Console.WriteLine("\n\nPlayer 1 wins");
                    break;

                case State.PlayerTwoWin:
                    Console.WriteLine("\n\nPlayer 2 wins");
                    break;

                case State.Draw:
                    Console.WriteLine("\n\nIt's draw");
                    break;
            }
        }

        private static State Play(char[,] matrix, byte[] banned, ref byte bannedIndex, Player player)
        {
            string name = (player == Player.One) ? "Player 1" : "Player 2";
            char symbol = (player == Player.One) ? SymbolOne : SymbolTwo;
            State stateOnWin = (player == Player.One) ? State.PlayerOneWin : State.PlayerTwoWin;

            Console.WriteLine("\n\nPlayer 1 chooses a position:");
            byte position = NumInputRange(1, 9, banned);
            banned[bannedIndex++] = position;

            SetSymbol(matrix, position, symbol);
            Console.Clear();

            if (CheckWinner(matrix, symbol))
            {
                return stateOnWin;
            }

            if (bannedIndex == BannedSize)
            {
                return State.Draw;
            }

            return State.InProgress;
        }

        static void Initialize(char[,] matrix, byte[] banned)
        {
            // Тут можно упростить инициализацию, но я хз как именно
            for (int row = 0; row < matrix.GetLength(0); row++)
            {
                for (int column = 0; column < matrix.GetLength(1); column++)
                {
                    matrix[row, column] = ' ';
                }
            }

            for (int index = 0; index < banned.Length; index++)
            {
                banned[index] = 0;
            }
        }
        
        static void Print(char[,] matrix)
        {
            // Наверняка тут тоже можно упростить форматирование, но я хз как
            Console.WriteLine("\n\n");
            Console.WriteLine("                 {0} | {1} | {2}                 1 | 2 | 3", matrix[0, 0], matrix[0, 1], matrix[0, 2]);
            Console.WriteLine("                ------------              -----------");
            Console.WriteLine("                 {0} | {1} | {2}                 4 | 5 | 6", matrix[1, 0], matrix[1, 1], matrix[1, 2]);
            Console.WriteLine("                ------------              -----------");
            Console.WriteLine("                 {0} | {1} | {2}                 7 | 8 | 9", matrix[2, 0], matrix[2, 1], matrix[2, 2]);
        }
        
        static void SetSymbol(char[,] matrix, byte index, char symbol)
        {
            var row = (index - 1) / MatrixSize;
            var column = (index - 1) % MatrixSize;

            matrix[row, column] = symbol;
        }
        
        static byte NumInputRange(int min, int max, byte[] banned)
        {
            byte var;
            bool inputIsValid;

            do
            {
                Console.Write("Enter number from {0} to {1}: ", min, max);
                inputIsValid = byte.TryParse(Console.ReadLine(), out var);
                
                if (!inputIsValid || var < min || var > max || banned.Contains(var))
                {
                    Console.WriteLine("Try again");
                }
            } while (!inputIsValid || var < min || var > max || banned.Contains(var));

            return var;
        }

        static bool CheckWinner(char[,] matrix, char symbol)
        {
            for (int index = 0; index < matrix.GetLength(0); index++)
            {
                // Check row
                if (matrix[index, 0] == symbol
                    && matrix[index, 0] == matrix[index, 1]
                    && matrix[index, 0] == matrix[index, 2])
                {
                    return true;
                }

                // Check column
                if (matrix[0, index] == symbol
                    && matrix[0, index] == matrix[1, index]
                    && matrix[0, index] == matrix[2, index])
                {
                    return true;
                }
            }

            // Check diagonals
            bool diagonal = true;
            bool reverseDiagonal = true;
            for (int index = 0; index < matrix.GetLength(0); index++)
            {
                diagonal = diagonal && matrix[index, index] == symbol;
                reverseDiagonal = reverseDiagonal && matrix[index, MatrixSize - 1 - index] == symbol;
            }

            return diagonal || reverseDiagonal;
        }
    }
}
