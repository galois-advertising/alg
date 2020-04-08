#include <iostream>
#include "randomized_set.h"


int main() {
    alg::randomized_set<int, int> s;
    s.insert(0, 1110);
    s.insert(1, 1111);
    s.insert(2, 1112);
    s.insert(3, 1113);
    s.insert(4, 1114);
    s.insert(5, 1115);
    s.insert(6, 1116);
    for (auto i = 0; i < 5; i++) {
        std::cout<<">"<<s.random_get()<<std::endl;
    }
    s.erase(1);
    s.erase(2);
    s.erase(3);
    s.erase(4);
    s.erase(5);
    s.erase(6);
    return 0;
}