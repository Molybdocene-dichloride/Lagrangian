#pragma once

#include <multiversion/client/graphics/Model.hpp>
#include <iostream>

template<class T> std::vector<std::shared_ptr<T>> slice(const Indexes<long>& range, std::vector<std::shared_ptr<T>> ops) {
    std::vector<std::shared_ptr<Operable>> vs{};
    std::vector<long>::const_iterator it;
    for(it = range.ts.begin(); it != range.ts.end(); it++) {
        vs.push_back(std::shared_ptr<T>(ops.at(*it)));
    }
    return vs;
}