#pragma once
#include <list>
#include <stack>
#ifdef _DEBUG
#include <sstream>
#endif
#include "log.h"

namespace alg {

template <typename T>
struct tree_node_t final {
    T val;
    tree_node_t* left;
    tree_node_t* right;
    tree_node_t(const T& x) : val(x), left(nullptr), right(nullptr) {}
};
template <typename T>
using visit_t = typename std::add_pointer<void(T&)>::type;

template<typename T>
void in_order_traversal(tree_node_t<T>* root, visit_t<T> op) {
    if (root != nullptr) {
        in_order_traversal(root->left, op);
        op(root->val);
        in_order_traversal(root->right, op);
    }
}

template<typename T>
void in_order_traversal_iteratively(tree_node_t<T>* root, visit_t<T> op) {
    std::stack<tree_node_t<T>*> sta;
    while (!sta.empty() || root != nullptr) {
        if (root != nullptr) {
            sta.push(root);
            root = root->left;
        } else {
            op(sta.top()->val);
            root = sta.top()->right;
            sta.pop();
        }
    }
}

template<typename T>
void pre_order_traversal(tree_node_t<T>* root, visit_t<T> op) {
    if (root != nullptr) {
        op(root->val);
        pre_order_traversal(root->left, op);
        pre_order_traversal(root->right, op);
    }
}

template <typename T>
void pre_order_traversal_iteratively(tree_node_t<T>* root, visit_t<T> op) {
    if (root == nullptr) {
        return;
    }
    std::stack<tree_node_t<T>*> sta;
    sta.push(root);
    while (!sta.empty()) {
        auto top = sta.top();
        sta.pop();
        // push right first
        if (top->right) {
            sta.push(top->right);
        }
        if (top->left) {
            sta.push(top->left);
        }
        op(top->val);
    }

}

template<typename T>
void post_order_traversal(tree_node_t<T>* root, visit_t<T> op) {
    if (root != nullptr) {
        post_order_traversal(root->left, op);
        post_order_traversal(root->right, op);
        op(root->val);
    }
}

template<typename T>
void post_order_traversal_iteratively(tree_node_t<T>* root, visit_t<T> op) {
}

template <typename T>
tree_node_t<T>* create_from_pre_order(std::list<T>& values, const T& null) {
    if (values.empty()) {
        TRACE("values is empty.", "");
        return nullptr;
    }
    if (values.front() == null) {
        TRACE("front is null.", "");
        values.pop_front();
        return nullptr;
    }
    auto current_root = new tree_node_t<T>(values.front()); 
#ifdef _DEBUG
    std::stringstream ss;
    ss << values.front();
    TRACE("create root: [%s]", ss.str().c_str());
#endif
    values.pop_front();
    current_root->left = create_from_pre_order<T>(values, null);
    current_root->right= create_from_pre_order<T>(values, null);
    return current_root;
}


}
