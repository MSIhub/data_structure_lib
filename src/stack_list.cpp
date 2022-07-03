#include "../include/stack_list.h"

template <class T>
void stack_list<T>::push(T ele)
{
    Node<T> *t = new Node<T>();
    if (t == nullptr)
    {
        std::cout << "Stack is full\n";
        return;
    }
    t->m_data = ele;
    t->m_next = top;
    top = t;
    m_size++;
}

template <class T>
T stack_list<T>::pop()
{
    if (top == nullptr)
    {
        std::cout << "Stack underflow\n";
        return -1;
    }
    T ret_val = top->m_data;
    Node<T> *p = top;
    top = top->m_next;
    delete p;
    m_size--;
    return ret_val;
}

template <class T>
T stack_list<T>::peek(int index)
{
    if (top == nullptr)
        return -1;
    Node<T> *p = top;
    int i = 0;
    while (p != nullptr && i < index)
    {
        p = p->m_next;
        i++;
    }
    return p->m_data;
}

template <class T>
T stack_list<T>::stack_top()
{
    if (top == nullptr)
        return -1;
    return top->m_data;
}

template <class T>
std::ostream &operator<<(std::ostream &os, const stack_list<T> &st)
{
    Node<T> *p = st.top;
    while (p != nullptr)
    {
        std::cout << p->m_data << ", ";
        p = p->m_next;
    }
    std::cout << "\b\b \n";
    return os;
}
bool stack_list_test()
{
    stack_list<double> st;
    st.push(10.8);
    st.push(20.8);
    st.push(30.8);
    st.push(40.8);
    st.push(50.8);
    std::cout << st;
    st.pop();
    st.pop();
    std::cout << st;
    std::cout << st.peek(0) << std::endl;
    std::cout << st.peek(1) << std::endl;
    std::cout << st.peek(2) << std::endl;
    std::cout << st.stack_top() << std::endl;
    return true;
}