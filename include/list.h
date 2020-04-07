
#pragma once
#include <list>
#include <stack>
#include <functional>
#include <queue>
#include "log.h"
#include "default_list_node.h"

namespace alg::list {

template <typename T, typename list_node_t = default_list_node_t<T>>
void insert(list_node_t** list, const T& val) {
    if (list == nullptr) {
        return;
    }
    if (*list == nullptr) {
        *list = new list_node_t(val);
        return;
    }
    auto pos = (*list);
    while (pos->next != nullptr) {
        pos = pos->next;
    }
    pos->next = new list_node_t(val);
}

template <typename T, typename list_node_t = default_list_node_t<T>>
using copy_callback_t = std::function<void(list_node_t*, list_node_t*)>;

template <typename T, typename list_node_t = default_list_node_t<T>>
list_node_t* copy(list_node_t* list, copy_callback_t<T, list_node_t> callback = {}) {
    if (list == nullptr) {
        return nullptr;
    }
    list_node_t* result = nullptr;
    auto pos = &result;
    while (list) {
        if ((*pos) == nullptr) {
            (*pos) = new list_node_t(list->val);
            if (callback) {
                callback(list, *pos);
            }
        } 
        pos = &(*pos)->next;
        list = list->next;
    }
    return result;
}


};