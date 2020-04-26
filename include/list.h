
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

template <typename T, typename list_node_t = default_list_node_t<T>>
void sort(list_node_t** head, bool(*cmp)(const list_node_t*, const list_node_t*)) {
    if (head == nullptr || *head == nullptr || (*head)->next == nullptr) {
        return;
    }
    auto last_ordered = *head;
    //                | 5 6 7 8 10 4 3 1 2
    // last_ordered = |          ^
    while (last_ordered != nullptr) {
        auto first_unordered = last_ordered->next;
        //                   | 5 6 7 8 10 4 3 1 2
        // first_unordered = |            ^
        if (first_unordered == nullptr) {
            break;
        }
        if (cmp(last_ordered, first_unordered)) {
            //if first_unordered is already ordered, just update the last_ordered;
            last_ordered = first_unordered;
        } else {
            // find the right position for first_unordered from head;
            // the "right position" is after "insert_position"
            // insert_position always behind insert_position_s_next for one step
            list_node_t* insert_position = nullptr;
            auto insert_position_s_next = *head;
            while(cmp(insert_position_s_next, first_unordered)) {
                insert_position = insert_position_s_next;
                insert_position_s_next = insert_position_s_next->next;
            }
            if (insert_position == nullptr) {
                // insert_position_s_next move zero steps, so insert_position is nullptr
                // this means we should insert it before head.
                // and reset the *head
                last_ordered->next = first_unordered->next;
                first_unordered->next = *head;
                *head = first_unordered;
            } else {
                // normal 
                last_ordered->next = first_unordered->next;
                first_unordered->next = insert_position->next;
                insert_position->next = first_unordered;
            }
        }
    }
}

template <typename T, typename list_node_t = default_list_node_t<T>>
void merge_sort(list_node_t** head, bool(*cmp)(const list_node_t*, const list_node_t*)) {
}


};