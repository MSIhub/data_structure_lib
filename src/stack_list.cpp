#include <iostream>

template <class T>
class Node
{
public:
    T data;
    Node *next;
};

template <class T>
class stack_list
{
private:
    Node<T> *top;

public:
    stack_list() : top(nullptr) {}

    void push(T ele);
    T pop();

    ~stack_list()
    {
        if (top)
            delete top;
    }
};
