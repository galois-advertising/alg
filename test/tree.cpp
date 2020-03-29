#include <list>
#include <iostream>
#include "tree.h"

using namespace std;

int main() {
    std::list<int> tvalues{1,2,-1,-1,3,4,6,-1,-1,7,-1,-1,5,-1,8,-1,-1};
    auto node = alg::create_from_pre_order(tvalues, -1);
    alg::in_order_traversal(node, [](int& i){std::cout<<i<<",";});std::cout<<std::endl;
    alg::in_order_traversal_iteratively(node, [](int& i){std::cout<<i<<",";});std::cout<<std::endl;
    alg::pre_order_traversal(node, [](int& i){std::cout<<i<<",";});std::cout<<std::endl;
    alg::pre_order_traversal_iteratively(node, [](int& i){std::cout<<i<<",";});std::cout<<std::endl;
    alg::post_order_traversal(node, [](int& i){std::cout<<i<<",";});std::cout<<std::endl;
    //alg::in_order_traversal_iteratively(node, [](int& i){std::cout<<i<<",";});
    return 0;
}



