#include <iostream>

//#region
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

//#endregion

// int main()
// {
//     stack_array<double> st(5);
//     st.push(10.8);
//     st.push(20.8);
//     st.push(30.8);
//     st.push(40.8);
//     st.push(50.8);
//     std::cout << st;
//     st.pop();
//     st.pop();
//     std::cout << st;
//     std::cout << st.peek(0) << std::endl;
//     std::cout << st.peek(1) << std::endl;
//     std::cout << st.peek(2) << std::endl;
//     std::cout << st.stack_top() << std::endl;

//     return 0;
// }