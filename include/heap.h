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
void shift_down(T &data, unsigned begin, unsigned end) {
    auto root = begin;
    while (true) {
        if (auto lchild = left_child(root, end); 
            lchild >=0 && data[lchild] > data[root]) {
            TRACE("swap %d[%d] <-> %d[%d] root=%d", data[lchild], lchild, data[root], root, lchild)
            std::swap(data[lchild], data[root]);
            root = lchild;
        } else if (auto rchild = right_child(root, end); 
            rchild >= 0 && data[rchild] > data[root]) {
            TRACE("swap %d[%d] <-> %d[%d] root=%d", data[rchild], rchild, data[root], root, rchild)
            std::swap(data[rchild], data[root]);
            root = rchild;
        } else {
            break;
        }
    }
}
template <typename T>
void make_heap(T &data) {
    auto root = parent((data.size() - 1));
    while (root >= 0) {
        TRACE("shift_down %d[%d]", data[root], root);
        shift_down(data, root, data.size() - 1);
        root = root - 1;
    }
}

template <typename T>
void heap_sort(T &data) {
    make_heap(data);
    auto len = data.size();
    while (len > 1) {
        std::swap(data[0], data[len - 1]);
        shift_down(data, 0, --len);
    }
}


}