#pragma once
#include <functional>

namespace alg::tree {

template <typename T>
using visit_t = std::function<void(T&)>;

};