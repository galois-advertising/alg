#include <iostream>
#include <list>
#include <algorithm>
#include "list.h"
using namespace std;



int main() {
    alg::list::default_list_node_t<int> * list = nullptr;
    std::list<int> input{1,2,3,4,5,6,7,9};
    std::for_each(input.begin(), input.end(), 
        [&list](int &i) {alg::list::insert<int>(&list, i);});
    auto cp = alg::list::copy<int>(list);
    return 0;
}