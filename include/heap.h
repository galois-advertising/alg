#pragma once
#include <iterator>
#include <algorithm>
#include "log.h"

namespace alg {


inline int parent(unsigned int i) {
    if (int res = (i - 1) / 2; res >= 0) {
        TRACE("parent(%u) = %d", i, res);
        return res;
    }
    else {
        TRACE("parent(%u) = %d", i, -1);
        return -1;
    }
}

inline int left_child(unsigned int i, unsigned int end) {
    if (int res = i * 2 + 1; res <= end) {
        TRACE("left_child(%u, %u) = %d", i, end, res);
        return res;
    }
    else {
        TRACE("left_child(%u, %u) = %d", i, end, -1);
        return -1;
    }
}

inline int right_child(unsigned int i, unsigned int end) {
    if (int res = i * 2 + 2; res <= end) {
        TRACE("right_child(%u, %u) = %d", i, end, res);
        return res;
    }
    else {
        TRACE("right_child(%u, %u) = %d", i, end, -1);
        return -1;
    }
}

template <typename T>
bool default_cmp(const T& a, const T& b) {
    return a < b;
}

template < typename T >
using cmp_t = typename std::add_pointer<bool(const typename T::value_type&, const typename T::value_type&)>::type;

template <typename T>
void shift_down(T &data, unsigned begin, unsigned end, cmp_t<T> cmp) {
    auto root = begin;
    while (true) {
        auto swap = root;
        if (auto lchild = left_child(root, end); 
            lchild >=0 && !cmp(data[lchild], data[root])) {
            swap = lchild;
            TRACE("swap target = %d[lchild]", swap);
        } 
        if (auto rchild = right_child(root, end); 
            rchild >= 0 && !cmp(data[rchild], data[swap])) {
            swap = rchild;
            TRACE("swap target = %d[rchild]", swap);
        } 
        if (swap == root) {
            return;
        } else {
            TRACE("swap %d[%d] <-> %d[%d] root=%d", data[swap], swap, data[root], root,swap);
            std::swap(data[swap], data[root]);
            root = swap;
        }
    }
}
template <typename T>
void make_heap(T &data, cmp_t<T> cmp = default_cmp<typename T::value_type>) {
    for (auto root = parent(data.size() - 1); root >= 0; --root) {
        TRACE("shift_down %d[%d]", data[root], root);
        shift_down(data, root, data.size() - 1, cmp);
    }
}

template <typename T>
void pop_heap(T &data, size_t last, cmp_t<T> cmp = default_cmp<typename T::value_type>) {
    std::swap(data[0], data[last]);
    shift_down(data, 0, end - 1);
}

template <typename T>
void heap_sort(T &data, cmp_t<T> cmp = default_cmp<typename T::value_type>) {
    make_heap(data, cmp);
    TRACE("make_heap done", "");
    for (auto last = data.size() - 1; last > 0; --last) {
        TRACE("[%d] ok", data[0]);
        std::swap(data[0], data[last]);
        shift_down(data, 0, last - 1, cmp);
    }
}


}