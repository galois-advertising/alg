#pragma once
#include "default_skiplist_node.h"


namespace alg::skiplist {

template <typename T, typename list_node_t = default_skiplist_node_t<T>>
void insert(::stdlist<T>& values, const T& null) {
}
}