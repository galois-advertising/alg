#pragma once
#include <list>
#ifdef _DEBUG
#include <sstream>
#endif
#include "log.h"

template <typename T>
struct TreeNode final {
    T val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(const T& x) : val(x), left(nullptr), right(nullptr) {}
};

template<typename T>
void in_order_traversal(TreeNode<T>* root, typename std::add_pointer<void(const T&)>::type op) {
    if (root != nullptr) {
        op(root->val);
        in_order_traversal(root->left, op);
        in_order_traversal(root->right, op);
    }
}

template <typename T>
TreeNode<T>* create_from_in_order(std::list<T>& values, const T& null) {
    if (values.empty()) {
        TRACE("values is empty.", "");
        return nullptr;
    }
    if (values.front() == null) {
        TRACE("front is null.", "");
        values.pop_front();
        return nullptr;
    }
    auto current_root = new TreeNode<T>(values.front()); 
#ifdef _DEBUG
    std::stringstream ss;
    ss << values.front();
    TRACE("create root: [%s]", ss.str().c_str());
#endif
    values.pop_front();
    current_root->left = create_from_in_order<T>(values, null);
    current_root->right= create_from_in_order<T>(values, null);
    return current_root;
}
