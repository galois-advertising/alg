#pragma once
#include <list>

namespace alg::min_stack {

template <typename T>
class min_stack final {
    std::list<T> store;
    std::list<T> min_store;
public:
    bool empty() {
        return store.empty();
    }
    void push(const T& t) {
        if (min_store.empty()) {
            min_store.push_back(t);
        } else {
            min_store.push_back(std::min(t, min_store.back()));
        }
        store.push_back(t);
    }
    void pop() {
        store.pop_back();
        min_store.pop_back();
    }
    T& top() {
        return store.back();
    }
    T& min() {
        return min_store.back();
    }
};
}