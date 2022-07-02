#include "../include/stack_array.h"

template <class T>
void stack_array<T>::push(T ele)
{
    if (isfull())
    {
        std::cout << "Stack Overflow\n";
        return;
    }
    m_element[++m_top] = ele;
}

template <class T>
T stack_array<T>::pop()
{
    if (isempty())
    {
        std::cout << "Stack Underflow\n";
        return -1;
    }
    return m_element[m_top--];
}

template <class T>
T stack_array<T>::peek(int index)
{
    int offset = m_top - index;
    if (offset < 0)
    {
        std::cout << "Invalid index\n";
        return -1;
    }
    return m_element[offset];
}

template <class T>
T stack_array<T>::stack_top()
{
    if (isempty())
        return -1;
    return m_element[m_top];
}

template <class T>
std::ostream &operator<<(std::ostream &os, const stack_array<T> &st)
{
    for (int i = st.m_top; i >= 0; i--)
        os << st.m_element[i] << ", ";
    os << "\b\b \n";
    return os;
}

bool stack_array_test()
{
    stack_array<double> st(5);
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