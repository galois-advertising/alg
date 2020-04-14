#include <iostream>
#include <list>
#include "log.h"
#include "min_stack.h"



int main() {
    alg::min_stack::min_stack<int> msta;
    std::list<int> input{-2, 0, 1};
    for (auto i : input) {
        msta.push(i);
        TRACE("push: %d, min: %d", i, msta.min());
    }
    while (!msta.empty()) {
        TRACE("pop: %d, min: %d", msta.top(), msta.min());
        msta.pop();
    }
    return 0;
}