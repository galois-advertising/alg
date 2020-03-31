
#pragma once
#include <list>
#include <stack>
#include <functional>
#include <queue>
#include <sstream>
#include "log.h"
#include "default_tree_node.h"
#include "tree_defines.h"

namespace alg::tree {

template<typename T, typename tree_node_t>
int getTreeHeight(tree_node_t* root){
    if (!root)
        return 0;
    return std::max(getTreeHeight<T, tree_node_t>(root->left), getTreeHeight<T, tree_node_t>(root->right)) + 1;
}


template<typename T, typename tree_node_t>
void printTree_helper(std::vector<std::vector<std::string>>& res, 
    tree_node_t* root, int offset, int w, int depth){
    if (!root)
        return;
    int center = offset + w / 2 + 1;
    std::stringstream ss;
    ss << root->val;
    res[depth][center] = ss.str();
    printTree_helper<T, tree_node_t>(res, root->left, offset, w / 2, depth + 1);
    printTree_helper<T, tree_node_t>(res, root->right, center, w / 2, depth + 1);
}

template<typename T, typename tree_node_t>
std::vector<std::vector<std::string>> printTree(tree_node_t* root) {
    int h = getTreeHeight<T, tree_node_t>(root);
    int w = 0;
    for (int i = 0;i < h;i++) w = w * 2 + 1;
    std::vector<std::vector<std::string>> res(h, std::vector<std::string>(w, "\t"));
    printTree_helper<T, tree_node_t>(res, root, -1, w, 0);
    return res;
}
template<typename T, typename tree_node_t = default_tree_node_t<T>>
void print(tree_node_t* root) {
    if (root != nullptr) {
        for (auto & v : printTree<T, tree_node_t>(root)) {
            for (auto& i : v) {
                std::cout<<i;
            }
            std::cout<<std::endl;
        }
    }

}
}