#pragma once 
// solopoinnter1202@gmail.com
#include <string>

template <size_t ALPHABET_SIZE>
class trie final {
public:
    class node;
    node * root = nullptr;
    class node {
    public:
        char data = "";
        bool is_word = false;
        node * children[ALPHABET_SIZE];
        node(char ch) : data(ch), is_word(false) {
            for (auto i = 0; i < ALPHABET_SIZE; ++i) {
                children[i] = nullptr;
            }
        }
    };
    trie() : root(new node(' ')) {}
    bool insert(std::string str) { 

    }
};