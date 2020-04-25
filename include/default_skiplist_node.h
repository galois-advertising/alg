#pragma once
#include <vector>

namespace alg::skiplist {

template<typename T>
class default_skiplist_node_t {
public:
    T val;
    std::vector<default_skiplist_node_t<T>*> nexts;
    default_skiplist_node_t<T>(): val(), next(nullptr) {}
    default_skiplist_node_t<T>(T& t): val(t), next(nullptr) {}
};

}