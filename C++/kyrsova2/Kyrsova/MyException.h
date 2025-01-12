//MyException.h
#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip> // Для использования std::setw
#include <fstream>
using namespace std;

class MyException
{
private:
    int codeError;
    string messenge;

public:
    MyException(string messenge, int codeError) : messenge(messenge), codeError(codeError){}
    int GetCodeerror() { return this->codeError; }
    virtual string What()
    {
        string Messenge = messenge + ", Number of error:" + to_string(codeError) + '\n';
        return Messenge;
    }
};

class IntException : public MyException
{
public:
    IntException(string messenge, int codeError) : MyException(messenge, codeError){}
    virtual string WhatINT()
    {
        string Messenge = "Error with input int\n" + What();
        return Messenge;
    }
};

class StringException : public MyException
{
public:
    StringException(string messenge, int codeError) : MyException(messenge, codeError) {}
    virtual string WhatSTRING() 
    {
        string Messenge = "Error with input string\n" + What();
        return Messenge;
    }
};

class DoubleException : public MyException
{
public:
    DoubleException(string messenge, int codeError) : MyException(messenge, codeError) {}
    virtual string WhatDOUBLE()
    {
        string Messenge = "Error with input double\n" + What();
        return Messenge;
    }
};

class FileError : public MyException
{
public:
    FileError(string messenge, int codeError) : MyException(messenge, codeError) {}
    virtual string WhatFILE()
    {
        string Messenge = "Error with file\n" + What();
        return Messenge;
    }
};