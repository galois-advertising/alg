#pragma once
namespace alg::tree {

template <typename T>
struct default_tree_node_t final {
    T val;
    default_tree_node_t* left;
    default_tree_node_t* right;
    default_tree_node_t(const T& x) : val(x), left(nullptr), right(nullptr) {}
};

}