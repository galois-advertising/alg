#pragma once
#include <list>
#include <stack>
#include <functional>
#include <queue>
#include "log.h"
#include "default_tree_node.h"
#include "tree_defines.h"

namespace alg::tree {
template <typename T, typename tree_node_t = default_tree_node_t<T>>
void bst_insert(tree_node_t*&root, const T& val) {
    if (root == nullptr) {
        root = new tree_node_t(val);
    } else if (val == root->val) {
        root->val = val;
    } else if (val < root->val) {
        bst_insert(root->left, val);
    } else {
        bst_insert(root->right, val);
    }
}

template <typename T, typename tree_node_t = default_tree_node_t<T>>
void bst_insert_iteratively(tree_node_t**root, const T& val) {
    while (true) {
        if (*root == nullptr) {
            *root = new tree_node_t(val);
            return;
        } else if (val == (*root)->val) {
            (*root)->val = val;
            return;
        } else if (val < (*root)->val) {
            root = &(*root)->left;
        } else {
            root = &(*root)->right;
        }
    }
}

template <typename K, typename tree_node_t = default_tree_node_t<T>>
tree_node_t* bst_search(tree_node_t*root, const K& key) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->val == key) {
        return root;
    } else {
        if (root->left) {
            return bst_search(root->left, key);
        }
    }
}

}