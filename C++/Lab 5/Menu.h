#pragma once
#include "Stack.cpp"

template<typename T>
class Menu {
private:
    StackList<T> stack;

public:
    void Run();

private:
    void PrintMenu();
    int GetUserChoice();
    void PushItem();
    void PopItem();
    void PrintStack();
    void ChangeFields();
    void EmptyStack();
};