#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__
#include <iostream>

template <class T>
class treenode
{
private:
    T m_value;

public:
    treenode *m_right;
    treenode *m_left;

    treenode() : m_value(0), m_left(nullptr), m_right(nullptr) {}

    treenode(int val_) : m_value(val_), m_left(nullptr), m_right(nullptr) {}

    // reference-getter method
    T &value() { return m_value; }
};

void print_tabs(int numtabs);
template <class T>
void printtree(treenode<T> *root);
bool binary_tree_test();

#endif