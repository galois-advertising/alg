#include <iostream>
#include "randomized_set.h"


int main() {
    alg::randomized_set<int, int> s;
    std::cout<<s.insert(0, 1110)<<std::endl;
    std::cout<<s.insert(0, 2220)<<std::endl;
    std::cout<<s.insert(1, 1111)<<std::endl;
    std::cout<<s.insert(2, 1112)<<std::endl;
    std::cout<<s.insert(3, 1113)<<std::endl;
    std::cout<<s.insert(4, 1114)<<std::endl;
    std::cout<<s.insert(5, 1115)<<std::endl;
    std::cout<<s.insert(6, 1116)<<std::endl;
    for (auto i = 0; i < 6; i++) {
        std::cout<<">"<<s.random_get()<<std::endl;
    }
    std::cout<<s.erase(1)<<std::endl;
    std::cout<<s.erase(11)<<std::endl;
    std::cout<<s.erase(2)<<std::endl;
    std::cout<<s.erase(3)<<std::endl;
    std::cout<<s.erase(4)<<std::endl;
    std::cout<<s.erase(5)<<std::endl;
    std::cout<<s.erase(6)<<std::endl;
    return 0;
}