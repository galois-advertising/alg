#pragma once
#include <vector>

namespace alg {
    std::vector<unsigned int> fast_divisors(unsigned int num) {
        std::vector<unsigned int> result{};
        for (auto d = 1; d * d <= num; d++) {
            if (num % d == 0) {
                result.push_back(d);
                if (num / d != d) {
                    result.push_back(num / d);
                }
            }
        }
        return result;
    }
}