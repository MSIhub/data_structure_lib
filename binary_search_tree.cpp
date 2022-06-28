#include <iostream>


template<class T>
struct binarytree_node
{
    T data;
    binarytree_node * left;
    binarytree_node * right;
}; //struct as all members need to be accessed 

template<class T>
class binarytree
{
    private:
        binarytree_node<T> * root;
    public:
        binarytree():root(nullptr){}
        binarytree(T val_)
        {
            root->data = val_;
            root->left = nullptr;
            root->right = nullptr;
        }

        bool isempty() {return (root==nullptr);}

        bool insertnode(T item);

        void printtree()
        {
            printtree_rec(this->root, 0);
        }

       
};




void printtabs(int numtabs)
{
    for(int i = 0; i < numtabs; i++)
        printf("\t");
}

template<class T> 
void printtree_rec(binarytree_node<T>* tn, int level)
{
    if(tn == nullptr)
    {
        printtabs(level);
        std::cout << "------\n";
        return;
    }
    //PREORDER TRAVERSAL
    printtabs(level);
    printf("value: %d\n", tn->value);
    printtabs(level);
    printf("left\n");

    printtree_rec(tn->m_left, level+1);
    printtabs(level);
    printf("right\n");

    printtree_rec(tn->m_right, level+1);
    printtabs(level);
    printf("done\n");
}




int main()
{
    return 0;
}