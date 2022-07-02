#ifndef __STACK_LIST_H__
#define __STACK_LIST_H__
#include <iostream>

template <class T>
class Node
{
public:
    T data;
    Node *next;
};
bool stack_list_test();
#endif