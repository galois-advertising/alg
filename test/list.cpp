#include <iostream>
#include <list>
#include <algorithm>
#include "list.h"
using namespace std;



int main() {
    using node_t = alg::list::default_list_node_t<int>;
    node_t* list = nullptr;
    std::list<int> input{1,2,3,4,5,6,7,9};
    std::for_each(input.begin(), input.end(), 
        [&list](int &i) {alg::list::insert<int>(&list, i);});
    alg::list::copy_callback_t<int> callback = [](node_t* a, node_t* b){std::cout<<a->val<<"|"<<b->val<<std::endl;};
    alg::list::copy<int>(list, callback);
    return 0;
}