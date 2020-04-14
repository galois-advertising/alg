#include <iostream>
#include "trie.h"

int main() {
    alg::trie tr;
    tr.insert("first");
    tr.insert("firtt");
    tr.insert("friend");
    std::cout<<tr.find("fir")<<"|"<<tr.find("friend")<<"|"<<tr.find("asdfafs")<<std::endl;
    if (tr.find("abcd")) {
        std::cout<<"yes"<<std::endl;
    }
    std::cout<<tr<<std::endl;
    return 0;
}