#include <iostream>
#include "../include/matrix.h"
#include "../include/binary_search_tree.h"
#include "../include/binary_tree.h"

int main(int argc, char **argv)
{
    std::cout << "In main";
    matrix_test();
    bst_test();
    binary_tree_test();
    graph_test();
    stack_array_test();

    return 0;
}