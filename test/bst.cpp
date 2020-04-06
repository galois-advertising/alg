
#include <list>
#include <iostream>
#include "tree.h"

int main() {
    std::list<int> input = {5,4,6,3,7,2,8};
    alg::tree::default_tree_node_t<int>* root = nullptr;
    for (auto& i : input) {
        alg::tree::bst_insert_iteratively(&root, i);
    }
    alg::tree::print<int>(root);
    return 0;
}