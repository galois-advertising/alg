#pragma once
#include <unordered_map>
#include <list>
#include <memory>
using namespace std;

template <typename KT, typename VT>
class lru_cache {
public:
    using node_t = typename std::pair<KT, VT>;
    using list_t = typename std::list<node_t>;
    using map_t = typename std::unordered_map<KT, typename list_t::iterator>;
private:
    list_t _l;
    map_t _m;
    size_t cap;
public:
    lru_cache(int capacity) : cap(capacity) {}
    
    const VT* get(KT key) {
        if (auto pos = _m.find(key); pos != _m.end()) {
            _l.splice(_l.begin(), _l, pos->second);
            return &_l.front().second;
        } else {
            return nullptr;
        }
    }
    void put(KT key, const VT& value) {
        if (auto pos = _m.find(key); pos != _m.end()) {
            (*pos->second).second = value;
            _l.splice(_l.begin(), _l, pos->second);
        } else {
            _l.push_front(std::make_pair(key, value));
            _m[key] = _l.begin();
            if (_l.size() > cap) {
                _m.erase((*std::prev(_l.end())).first);
                _l.pop_back();
            } 
        }
    }
};