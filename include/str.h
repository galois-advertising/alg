#pragma once
#include <string>
#include <vector>
#include <map>
#include <list>
#include <tuple>

namespace alg::string {
using q_t = size_t;
using ch_t = char;
using dfa_t = std::map<std::pair<q_t, ch_t>, q_t>;
using alpha_table_t = const std::vector<ch_t>;
static const std::vector<ch_t> default_alpha_table{
    'a','b','c','d','e','f','g','h','j','i','k','l','m',
    'n','o','p','q','r','s','t','u','v','w','x','y','z',
    'A','B','C','D','E','F','G','H','J','I','K','L','M',
    'N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
};

bool endswith(const std::string& str, const std::string& postfix) {
    if (postfix.size() == 0) {
        return false;
    }
    if (postfix.size() > str.size()) {
        return false;
    }
    if (str.substr(str.size() - postfix.size()) == postfix) {
        return true;
    }
    return false;
}

dfa_t generator_dfa(std::string pattern, alpha_table_t& alpha_table = default_alpha_table) {
    dfa_t dfa;
    for (q_t q = 0; q <= pattern.size(); q++) {
        for (auto ch : alpha_table) {
            //dfa[{q, ch}] = 0;
            for (int len = pattern.size(); len >= 0; len--) {
                auto current = (pattern.substr(0, q) + ch);
                auto prefix = pattern.substr(0, len);
                if (endswith(current, prefix)) {
                    dfa[{q, ch}] = len;
                    break;
                }
            }
        }
    }
    return dfa;
}
std::vector<std::string> search(std::string S, std::vector<std::string>& words) {
    std::vector<std::string> result;
    using dfa = std::tuple<q_t, q_t, dfa_t, std::string>;
    std::list<dfa> lst;
    for (const auto& w : words) {
        dfa t = std::make_tuple(0, w.size(), generator_dfa(w), w);
        lst.push_back(t);
    }
    for (auto ch : S) {
        for (auto& dfa : lst) {
            if (std::get<0>(dfa) == std::get<1>(dfa)) {
                continue;
            }
            if (auto res = std::get<2>(dfa).find({std::get<0>(dfa), ch}); res != std::get<2>(dfa).end()) {
                std::get<0>(dfa) = res->second;
            } else {
                std::get<0>(dfa) = 0;
            }
            if (std::get<0>(dfa) == std::get<1>(dfa)) {
                result.push_back(std::get<3>(dfa));
            }
        }
    }
    return result;
}

}