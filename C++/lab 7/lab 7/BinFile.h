#pragma once
#include <fstream>
#include "Stack.h"
#include "MyException.h"
using namespace std;
template <class T>
class MyFileBin {
private:
    string FileName;
public:
    MyFileBin()
    {
        T buf;
        FileName = buf.GetFileNameBin();
    }
    void write(T obj)
    {
        fstream file(FileName, ios::out | ios::app);
        try
        {
            if (!file.is_open())
            {
                throw FileError("Add in File Error", 12);
            }
            else
            {
                file << obj;
                file.close();
            }
        }
        catch (FileError& e)
        {
            cout << e.WhatFILE();
            cout << "Try again" << endl;
        }
        catch (...) { cout << "Try again" << endl; }
    }

    void read(StackList<T>& Mystack)
    {
        fstream inputFile(FileName, ios::in);

        try
        {
            if (!inputFile.is_open())
            {
                throw FileError("Error with read File", 13);
            }
            else
            {
                T buf;
                while (inputFile >> buf) {
                    Mystack.Push(buf);
                }
            }
        }
        catch (FileError& e)
        {
            cout << e.WhatFILE();
            cout << "Try again" << endl;
        }
        catch (...) { system("cls"); cout << "Information from file added to the Stack from file <<" << FileName << ">>" << endl; }
    }
    void DeleteFale() {
        try {
            fstream file(FileName, ios::out | ios::trunc);
            if (!file.is_open()) {
                throw FileError("Error with rewrite File", 14);
            }
            file.close();
        }
        catch (FileError& e)
        {
            cout << e.WhatFILE();
            cout << "Try again" << endl;
        }
        catch (...) { cout << "Try again" << endl; }
    }
};
