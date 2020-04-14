#pragma once
#include <unordered_map>
#include <vector>
#include <random>

namespace alg {
template<typename K, typename V> 
class randomized_set {
    using index_t = size_t;
    std::unordered_map<K, index_t> hash_store;
    std::vector<std::pair<K, V>> vec_store;
public:
    bool insert(const K& k, const V& v) {
        if (auto res = hash_store.find(k); res != hash_store.end()) {
            vec_store[res->second].second = v;
            return false;
        } else {
            vec_store.push_back(std::make_pair(k, v));
            hash_store[k] = vec_store.size() - 1;
        }
        return true;
    }

    bool erase(const K& k) {
        if (auto res = hash_store.find(k); res != hash_store.end()) {
            hash_store[vec_store.back().first] = res->second;
            std::swap(vec_store[res->second], vec_store[vec_store.size() - 1]);
            vec_store.pop_back();
            hash_store.erase(res);
            return true;
        }
        return false;
    }

    K& random_get() {
         std::random_device rd;
         std::mt19937 gen(rd());
         std::uniform_int_distribution<> dis(0, vec_store.size() - 1);
        return vec_store[dis(gen)].second;

    }
};
}