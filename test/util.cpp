#include <iostream>
#include "util.h"

int main() {
    for (auto i : alg::fast_divisors(100)) {
        std::cout<<i<<std::endl;
    }
    return 0;
}