#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__
#include <iostream>

template <class T>
class BST
{
public:
    T m_value;
    BST *m_left;
    BST *m_right;

    BST(T val_) : m_value(val_), m_left(nullptr), m_right(nullptr) {}

    BST &insert(T item);
    bool contains(T item);
    void print() { printtree_helper(this, 0); }
};

bool bst_test();

#endif