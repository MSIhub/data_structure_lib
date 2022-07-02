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

template <class T>
BST<T> &BST<T>::insert(T item)
{
    if (item == m_value)
    {
        return *this;
    }
    BST<T> *inode = new BST<T>(item);

    if (item < m_value)
    {
        if (m_left == nullptr)
            m_left = inode;
        else
            m_left->insert(item);
    }
    else
    {
        if (m_right == nullptr)
            m_right = inode;
        else
            m_right->insert(item);
    }
    return *this;
}

template <class T>
bool BST<T>::contains(T item)
{
    if (item < m_value)
    {
        if (m_left == nullptr)
            return false;
        else
            m_left->contains(item);
    }
    else if (item > m_value)
    {
        if (m_right == nullptr)
            return false;
        else
            m_right->contains(item);
    }
    else
        return true;
}

void printtabs(int numtabs)
{
    for (int i = 0; i < numtabs; i++)
        printf("\t");
}

template <class T>
void printtree_helper(BST<T> *tn, int level)
{
    if (tn == nullptr)
    {
        printtabs(level);
        std::cout << "------\n";
        return;
    }
    // PREORDER TRAVERSAL
    printtabs(level);
    printf("value: %d\n", tn->m_value);
    printtabs(level);
    printf("left\n");

    printtree_helper(tn->m_left, level + 1);
    printtabs(level);
    printf("right\n");

    printtree_helper(tn->m_right, level + 1);
    printtabs(level);
    printf("done\n");
}

// int main()
// {
//     BST<int>* bst = new BST<int>(19);
//     bst->insert(15);
//     bst->insert(25);
//     bst->insert(19);
//     bst->insert(4);
//     bst->insert(87);
//     bst->print();
//     std::cout << std::boolalpha << bst->contains(23) << std::noboolalpha << std::endl;
//     return 0;
// }