#include <iostream>
#include <vector>
#include "str.h"
static const std::vector<alg::string::ch_t> alpha_table{
    'a','b', 'c'
};
int main() {
    for (auto t : alg::string::dfa("ababaca", alpha_table)) {
        if (t.second != 0) {
            printf("d(%lu, %c) = %lu\n", t.first.first, t.first.second, t.second);
        }
    }

    return 0;
}