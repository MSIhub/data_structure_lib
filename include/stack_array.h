#ifndef __STACK_ARRAY_H__
#define __STACK_ARRAY_H__
#include <iostream>

template <class T>
class stack_array
{
private:
    int m_size;
    int m_top;
    T *m_element;

public:
    stack_array() : m_size(0), m_top(-1), m_element(nullptr) {}
    stack_array(int n_) : m_size(n_), m_top(-1) { m_element = new T[m_size]; }

    void push(T ele);
    T pop();

    int size() { return m_size; }
    bool isfull() { return (m_top == (m_size - 1)); }
    bool isempty() { return (m_top == -1); }
    T peek(int index);
    T stack_top();
    friend std::ostream &operator<< <>(std::ostream &os, const stack_array &st);
    ~stack_array()
    {
        if (m_element != nullptr)
            delete[] m_element;
    }
};

bool stack_array_test();

#endif