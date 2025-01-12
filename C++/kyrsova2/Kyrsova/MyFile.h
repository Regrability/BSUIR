//MyFile.h
#pragma once
#include <fstream>
#include <list>
#include "MyException.h"
using namespace std;
template <class T>
class MyFile {
private:
    string FileName;
public:
    MyFile()
    {
        T buf;
        FileName = buf.GetFileName();
    }
    void write(T obj)
    {
        ofstream file(FileName, ios::app);
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

    void read(list<T>& MyList)
    {
        ifstream inputFile(FileName);

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
                inputFile >> buf;
                if (buf.getName() != "")
                {
                    MyList.push_back(buf);
                }
            }
            cout << "Information from file added to the List from file <<" << FileName << ">>" << endl;
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
        ofstream file(FileName, ios::trunc);
        if (!file.is_open()) {
            throw FileError("Error with rewrite File", 14);
        }
        file.close();
    }
};
