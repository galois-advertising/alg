
#pragma once
namespace alg::list {

template <typename T>
struct default_list_node_t final {
    T val;
    default_list_node_t* next;
    default_list_node_t(const T& x) : val(x), next(nullptr) {}
};

}