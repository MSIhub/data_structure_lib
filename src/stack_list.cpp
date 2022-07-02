#include "../include/stack_list.h"

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

bool stack_list_test()
{
    return true;
}