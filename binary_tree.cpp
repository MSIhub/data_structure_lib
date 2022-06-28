#include <iostream>

template<class T>
class treenode
{
    private:
        T m_value;
    public:
        treenode *m_right;
        treenode *m_left;

        treenode():m_value(0), m_left(nullptr), m_right(nullptr) {}
        
        treenode(int val_):m_value(val_), m_left(nullptr), m_right(nullptr) {}

        //reference-getter method
        T& value() {return  m_value;}

        
};

void printtabs(int numtabs)
{
    for(int i = 0; i < numtabs; i++)
        printf("\t");
}

template<class T> 
void printtree_rec(treenode<T>* tn, int level)
{
    if(tn == nullptr)
    {
        printtabs(level);
        std::cout << "------\n";
        return;
    }
    //PREORDER TRAVERSAL
    printtabs(level);
    printf("value: %d\n", tn->value());
    printtabs(level);
    printf("left\n");

    printtree_rec(tn->m_left, level+1);
    printtabs(level);
    printf("right\n");

    printtree_rec(tn->m_right, level+1);
    printtabs(level);
    printf("done\n");
}

template<class T> 
void printtree(treenode<T>* root)
{
    printtree_rec(root, 0);
}

int main()
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

    return 0;
}