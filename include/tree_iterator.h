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

class INORDER {};
class PREORDER {};
class POSTORDER {};

template<typename ORDER, typename T, typename tree_node_t = default_tree_node_t<T>> 
class tree_iterator {};

template<typename T, typename tree_node_t> 
class tree_iterator<PREORDER, T, tree_node_t> {
    static T end_t;
    static tree_node_t end_node;
public:
    std::stack<tree_node_t*> sta;
    tree_iterator<PREORDER, T, tree_node_t>() {
        sta.push(&end_node);
    }
    tree_iterator<PREORDER, T, tree_node_t>(tree_node_t* node) {
        sta.push(&end_node);
        if (node != nullptr) {
            sta.push(node);
        }
    }
    tree_node_t& operator*() {
        return *sta.top();
    }
    tree_node_t* operator++(int) {
        auto top(sta.top());
        if (top != &end_node) {
            sta.pop();
            if (top->right) {
                sta.push(top->right);
            }
            if (top->left) {
                sta.push(top->left);
            }
        }
        return sta.top();
    }
    bool operator != (const tree_iterator<PREORDER, T, tree_node_t>& other) {
        return other.sta.top() != sta.top();
    }

};
template<typename T, typename tree_node_t> 
T tree_iterator<PREORDER, T, tree_node_t>::end_t;
template<typename T, typename tree_node_t> 
tree_node_t tree_iterator<PREORDER, T, tree_node_t>::end_node(end_t);

template<typename T, typename tree_node_t> 
class tree_iterator<INORDER, T, tree_node_t> {
    static T end_t;
    static tree_node_t end_node;
    void correct() {
        while (vtop != nullptr) {
            sta.push(vtop);
            vtop = vtop->left;
        }
    }
public:
    std::stack<tree_node_t*> sta;
    tree_node_t* vtop;
    tree_iterator<INORDER, T, tree_node_t>() {
        sta.push(&end_node);
    }
    tree_iterator<INORDER, T, tree_node_t>(tree_node_t* node) {
        sta.push(&end_node);
        vtop = node;
        correct();
    }
    tree_node_t& operator*() {
        return *sta.top();
    }
    tree_node_t* operator++(int) {
        auto top(sta.top());
        if (top != &end_node) {
            if (vtop == nullptr) {
                auto top_right = sta.top()->right;
                sta.pop();
                vtop = top_right;
                correct();
            } else {
                correct();
            }
        }
        return sta.top();
    }
    bool operator != (const tree_iterator<INORDER, T, tree_node_t>& other) {
        return other.sta.top() != sta.top();
    }

};
template<typename T, typename tree_node_t> 
T tree_iterator<INORDER, T, tree_node_t>::end_t;
template<typename T, typename tree_node_t> 
tree_node_t tree_iterator<INORDER, T, tree_node_t>::end_node(end_t);
}