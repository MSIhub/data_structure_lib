#include "../include/binary_tree.h"

void print_tabs(int numtabs)
{
    for (int i = 0; i < numtabs; i++)
        printf("\t");
}

template <class T>
void printtree_rec(treenode<T> *tn, int level)
{
    if (tn == nullptr)
    {
        print_tabs(level);
        std::cout << "------\n";
        return;
    }
    // PREORDER TRAVERSAL
    print_tabs(level);
    printf("value: %d\n", tn->value());
    print_tabs(level);
    printf("left\n");

    printtree_rec(tn->m_left, level + 1);
    print_tabs(level);
    printf("right\n");

    printtree_rec(tn->m_right, level + 1);
    print_tabs(level);
    printf("done\n");
}

template <class T>
void printtree(treenode<T> *root)
{
    printtree_rec(root, 0);
}

bool binary_tree_test()
{
    auto bt1 = new treenode<int>(15);
    auto bt2 = new treenode<int>(20);
    auto bt3 = new treenode<int>(25);
    auto bt4 = new treenode<int>(30);
    auto bt5 = new treenode<int>(35);

    bt1->m_left = bt2;
    bt1->m_right = bt3;
    bt3->m_left = bt4;
    bt3->m_right = bt5;

    printtree(bt1);

    delete bt1;
    delete bt2;
    delete bt3;
    delete bt4;
    delete bt5;

    return true;
}