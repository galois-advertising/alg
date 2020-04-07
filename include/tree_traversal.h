#pragma once
#include <list>
#include <stack>
#include <functional>
#include <queue>
#ifdef _DEBUG
#include <sstream>
#endif
#include "log.h"
#include "default_tree_node.h"
#include "tree_defines.h"

namespace alg::tree {

template<typename T, typename tree_node_t = default_tree_node_t<T>>
void in_order_traversal(tree_node_t* root, visit_t<T> op) {
    if (root != nullptr) {
        in_order_traversal(root->left, op);
        op(root->val);
        in_order_traversal(root->right, op);
    }
}

template<typename T, typename tree_node_t = default_tree_node_t<T>>
void in_order_traversal_iteratively(tree_node_t* root, visit_t<T> op) {
    if (false) {
        // from https://en.wikipedia.org/wiki/Tree_traversal
        std::stack<tree_node_t*> sta;
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
    } else if (false) {
        std::stack<tree_node_t*> sta;
        if (root == nullptr) {
            return;
        }
        sta.push(root);
        while (!sta.empty()) {
            if (sta.top() == nullptr) {
                sta.pop();
                if (!sta.empty()) {
                    op(sta.top()->val);
                    auto top_right = sta.top()->right;
                    sta.pop();
                    sta.push(top_right);
                }
            } else {
                sta.push(sta.top()->left);
            }
        }
    } else {
        std::stack<tree_node_t*> sta;
        auto vtop = root;
        while (vtop != nullptr || !sta.empty()) {
            if (vtop != nullptr) {
                sta.push(vtop);
                vtop = vtop->left;
            } else {
                op(sta.top()->val);
                vtop =  sta.top()->right;
                sta.pop();
            }
        }

    }
}

template<typename T, typename tree_node_t = default_tree_node_t<T>>
void pre_order_traversal(tree_node_t* root, visit_t<T> op) {
    if (root != nullptr) {
        op(root->val);
        pre_order_traversal(root->left, op);
        pre_order_traversal(root->right, op);
    }
}

template <typename T, typename tree_node_t = default_tree_node_t<T>>
void pre_order_traversal_iteratively(tree_node_t* root, visit_t<T> op) {
    if (root == nullptr) {
        return;
    }
    std::stack<tree_node_t*> sta;
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

template<typename T, typename tree_node_t = default_tree_node_t<T>>
void post_order_traversal(tree_node_t* root, visit_t<T> op) {
    if (root != nullptr) {
        post_order_traversal(root->left, op);
        post_order_traversal(root->right, op);
        op(root->val);
    }
}

template<typename T, typename tree_node_t = default_tree_node_t<T>>
void post_order_traversal_iteratively(tree_node_t* root, visit_t<T> op) {
}

template<typename T, typename tree_node_t = default_tree_node_t<T>>
void breadth_first_search_traversal(tree_node_t* root, visit_t<T> op) {
    std::queue<tree_node_t*> que;
    if (root == nullptr) {
        return;
    }
    que.push(root);
    while (!que.empty()) {
        op(que.front()->val);
        if (que.front()->left) {
            que.push(que.front()->left);
        }
        if (que.front()->right) {
            que.push(que.front()->right);
        }
        que.pop();
    }
}

};
