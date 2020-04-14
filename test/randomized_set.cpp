#include <iostream>
#include "randomized_set.h"


int main() {
    alg::randomized_set<int, int> s;
    std::cout<<s.insert(5, 1115)<<std::endl;
    std::cout<<s.insert(6, 1116)<<std::endl;
    for (auto i = 0; i < 6; i++) {
        std::cout<<">"<<s.random_get()<<std::endl;
    }
    std::cout<<s.erase(6)<<std::endl;
    return 0;
}