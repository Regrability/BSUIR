#pragma once
#include <fstream>
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
    void read(list<T>& MyList)
    {
        fstream inputFile(FileName);

        try
        {
            if (!inputFile.is_open())
            {
                throw FileError("Error with read File", 13);
            }
            else
            {
                T buf;
                while (!inputFile.eof())
                {
                    while (inputFile >> buf)
                    {
                        MyList.push_back(buf);
                    }
                }
                cout << "Information from file added to the List from file <<" << FileName << ">>" << endl;
            }
            inputFile.close(); // Закрываем файл после чтения
        }
        catch (FileError& e)
        {
            cout << e.WhatFILE();
            cout << "Try again" << endl;
        }
        catch (...) { cout << "Information include succes" << endl; }
    }
    void write(T obj)
    {
        try
        {
            fstream file(FileName, ios::app);
            if (!file.is_open())
            {
                throw FileError("Add in File Error", 12);
            }
            else
            {
                file << obj;
                file.close(); // Закрываем файл после записи
            }
        }
        catch (FileError& e)
        {
            cout << e.WhatFILE();
            cout << "Try again" << endl;
        }
        catch (...) { cout << "Try again" << endl; }
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
