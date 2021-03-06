#pragma once
#include <string>
#include <memory>
namespace alg {
class trie final {
public:
    static const size_t ALPHABET_SIZE = 26;
    class node;
    std::shared_ptr<node> root = nullptr;
    class node {
    public:
        char data = ' ';
        bool is_word = false;
        size_t count = 0;
        std::shared_ptr<node> children[ALPHABET_SIZE];
        node(char ch) : data(ch), is_word(false), count(0) {
            for (auto i = 0; i < ALPHABET_SIZE; ++i) {
                children[i] = nullptr;
            }
        }
    };

    trie() : root(std::make_shared<node>(' ')) {}
    trie(const trie& ) = delete;

    void insert(std::string str) { 
        auto pos = root;
        for (auto ch : str) {
            auto index = ch - 'a';
            if (pos->children[index] == nullptr) {
                pos->children[index] = std::make_shared<node>(ch);
            } 
            pos->children[index]->count++;
            pos = pos->children[index];
        }
        pos->is_word = true;
    }

    bool find(std::string str) {
        auto pos = root;
        for (auto ch : str) {
            auto index = ch - 'a';
            if (pos->children[index] == nullptr) {
                return false;
            } else {
                pos = pos->children[index];
            }
        }
        if (!pos->is_word) {
            return false;
        }
        return true;
    }
    bool startsWith(std::string str) {
        auto pos = root;
        for (auto ch : str) {
            auto index = ch - 'a';
            if (pos->children[index] == nullptr) {
                return false;
            } else {
                pos = pos->children[index];
            }
        }
        return true;
    }

};
std::ostream& operator<< (std::ostream& os, const typename trie::node& node) {
    os<<"["<<node.data<<":";
    for (auto p : node.children) {
        if (p) {
            os<<*p;
        }
    }
    os<<"]";
    return os;
}

std::ostream& operator<< (std::ostream& os, const trie& tr) {
    if (tr.root) {
        os<<*tr.root;
    }
    return os;
}
}