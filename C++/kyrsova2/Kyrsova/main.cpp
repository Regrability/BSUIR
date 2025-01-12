//main.cpp
#include "Computer.h"
#include "Telephone.h"
#include "Footwear.h"
#include "Accessories.h"
#include "Mytools.h"

#include "Menu.cpp"
#include "Stack.cpp"

    int main() 
    {
        setlocale(LC_ALL, "RUS");
        Menu<Computer> computer; computer.WriteFromFile();//загрузка из файла
        Menu<Telephone> telephone; telephone.WriteFromFile();
        Menu<Footwear> footwear; footwear.WriteFromFile();
        Menu<Accessories> accessories; accessories.WriteFromFile();
        StackList<Menu<Computer>, Menu<Telephone>, Menu<Footwear>, Menu<Accessories>> stack;
        stack.Push(computer, telephone, footwear, accessories);//загрузить в стек изначальное состояние
        cout << "STACK is dowland" << endl;
        tuple <Menu<Computer>, Menu<Telephone>, Menu<Footwear>, Menu<Accessories>> poppedItems{};//для извлечения из стека
        StackListIterator< Menu<Computer>, Menu<Telephone>, Menu<Footwear>, Menu<Accessories> > it;
        int choice;
        bool write_to_stack;//пользовать может просто просмотреть и это не надо записывать в стек
        do
        {
            PrintFirstMenu();
            choice = InputINT(1, 6);
            system("cls");
            switch (choice) {
            case 1:
                computer.Run(write_to_stack);
                if (write_to_stack) stack.Push(computer, telephone, footwear, accessories);
                break;
            case 2:
                telephone.Run(write_to_stack);
                if (write_to_stack) stack.Push(computer, telephone, footwear, accessories);
                break;
            case 3:
                footwear.Run(write_to_stack);
                if (write_to_stack) stack.Push(computer, telephone, footwear, accessories);
                break;
            case 4:
                accessories.Run(write_to_stack);
                if (write_to_stack) stack.Push(computer, telephone, footwear, accessories);
                break;
            case 5:
                if (stack.Cout() >= 2)//чтобы не стереть первые данные
                {
                    it = stack.begin();
                    ++it;
                    poppedItems = *it;
                    computer = get<0>(poppedItems); 
                    telephone = get<1>(poppedItems); 
                    footwear = get<2>(poppedItems); 
                    accessories = get<3>(poppedItems);
                    stack.Pop();
                    computer.RewriteFile();
                    telephone.RewriteFile();
                    footwear.RewriteFile();
                    accessories.RewriteFile();
                }
                else cout << "You can't step back" << endl;
                break;
            case 6:
                cout << "Exiting the program..." << endl;
                break;
            }
        } while (choice != 6);
        return 0;
    }