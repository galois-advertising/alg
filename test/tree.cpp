#include <list>
#include <iostream>
#include "tree.h"

using namespace std;
using namespace alg;


/*

    1
  /   \
2       3
      /   \
     4     5
   /   \    \
  6     7    8

*/
#undef _DEBUG
int main() {
    std::list<int> tvalues{1,2,-1,-1,3,4,6,-1,-1,7,-1,-1,5,-1,8,-1,-1};
    auto node = alg::tree::create_from_pre_order(tvalues, -1);
    std::function<void(int&)> visit = [&node](int& i){std::cout<<i<<",";};
    //alg::tree::in_order_traversal(node, visit);std::cout<<std::endl;
    alg::tree::in_order_traversal_iteratively(node, visit);std::cout<<std::endl;
    for (auto pos = alg::tree::tree_iterator<alg::tree::INORDER, int>(node); 
        pos != alg::tree::tree_iterator<alg::tree::INORDER, int>(); ++pos) {
        std::cout<<(*pos).val<<",";
    }
    std::cout<<std::endl;
    alg::tree::print<int>(node);
    auto cond = [](const alg::tree::default_tree_node_t<int>& node){ return node.val == 3;};
    auto find_result = alg::tree::find_if<int>(node, 
        static_cast<std::function<bool(const alg::tree::default_tree_node_t<int>&)>>(cond));
    std::cout<<find_result->val<<std::endl;

    //alg::tree::pre_order_traversal(node, visit);std::cout<<std::endl;
    //alg::tree::pre_order_traversal_iteratively(node, visit);std::cout<<std::endl;
    //for (auto pos = alg::tree::tree_iterator<alg::tree::PREORDER, int>(node); 
    //    pos != alg::tree::tree_iterator<alg::tree::PREORDER, int>(); ++pos) {
    //    TRACE("%d", (*pos).val);
    //}
    //std::cout<<std::endl;
    //alg::tree::post_order_traversal(node, visit);std::cout<<std::endl;
    ////alg::in_order_traversal_iteratively(node, visit);
    //alg::tree::breadth_first_search_traversal(node, visit);std::cout<<std::endl;

    return 0;
}



