#ifndef __STACK_LIST_H__
#define __STACK_LIST_H__
#include <iostream>

template <class T>
class Node
{
public:
    T m_data;
    Node *m_next;
};

template <class T>
class stack_list
{
private:
    Node<T> *top;
    int m_size;

public:
    stack_list() : top(nullptr) {}

    void push(T ele);
    T pop();
    int size() { return m_size; }
    bool isempty() { return (top == nullptr); }

    T peek(int index);
    T stack_top();

    friend std::ostream &operator<< <>(std::ostream &os, const stack_list &st);

    ~stack_list()
    {
        Node<T> *temp = top;

        while (top != nullptr)
        {
            top = top->m_next;
            delete temp;
            temp = top;
        }
    }
};

bool stack_list_test();
#endif