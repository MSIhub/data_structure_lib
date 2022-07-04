#include <iostream>
#include "gtest/gtest.h"
#include "../include/matrix.h"
#include "../include/binary_search_tree.h"
#include "../include/binary_tree.h"
#include "../include/stack_array.h"
#include "../include/stack_list.h"
#include "../include/graph.h"

TEST(matrix_test, base_test)
{
    EXPECT_EQ(matrix_test(), true);
}

TEST(stack_list_test, base_test)
{
    EXPECT_EQ(stack_list_test(), true);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
// int main(int argc, char **argv)
// {
//     // matrix_test();
//     // bst_test();
//     // binary_tree_test();
//     // graph_test();
//     // stack_array_test();
//     // stack_list_test();
//     return 0;
// }