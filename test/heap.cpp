#include <iostream>
#include <vector>
#include "heap.h"



int main() {
    std::vector<int> input{3,4,5,2,6,1};
    alg::heap_sort(input);
    for (auto i : input) {
        std::cout<<i<<",";
    }
    std::cout<<std::endl;
    return 0;
}