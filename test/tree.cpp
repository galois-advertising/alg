#include <list>
#include <iostream>
#include "tree.h"

using namespace std;

int main() {
    std::list<int> tvalues{1,2,-1,-1,3,4,6,-1,-1,7,-1,-1,5,-1,8,-1,-1};
    auto node = create_from_in_order(tvalues, -1);
    in_order_traversal(node, [](const int& i){std::cout<<i<<",";});
    return 0;
}



