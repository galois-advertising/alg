#pragma once
#include <list>
#include <stack>
#include <functional>
#include <queue>
#include "log.h"
#include "default_tree_node.h"
#include "tree_defines.h"

namespace alg::tree {
template<typename T, typename tree_node_t = default_tree_node_t<T>>
tree_node_t* find_if(tree_node_t* root, std::function<bool(const tree_node_t&)> cond) {
    tree_node_t* result = nullptr;
    if (root == nullptr) {
        result = nullptr;
    } else {
        if (result == nullptr && cond(*root)) {
            result = root;
        } else {
            if (result == nullptr && root->left) {
                result = find_if<T, tree_node_t>(root->left, cond);
            }
            if (result == nullptr && root->right) {
                result = find_if<T, tree_node_t>(root->right, cond);
            }
        }
    }
    return result;
}

}