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

template <typename T, typename tree_node_t = default_tree_node_t<T>>
tree_node_t* create_from_pre_order(std::list<T>& values, const T& null) {
    if (values.empty()) {
        TRACE("values is empty.", "");
        return nullptr;
    }
    if (values.front() == null) {
        TRACE("front is null.", "");
        values.pop_front();
        return nullptr;
    }
    auto current_root = new tree_node_t(values.front()); 
#ifdef _DEBUG
    std::stringstream ss;
    ss << values.front();
    TRACE("create root: [%s]", ss.str().c_str());
#endif
    values.pop_front();
    current_root->left = create_from_pre_order<T, tree_node_t>(values, null);
    current_root->right= create_from_pre_order<T, tree_node_t>(values, null);
    return current_root;
}

};
