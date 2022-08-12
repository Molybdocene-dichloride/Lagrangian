#pragma once

template<class T> std::size_t IndexesHash<T>::operator()(Indexes<T> const& s) const {
    std::size_t seed = s.ts.size();
    for(auto x : s.ts) {
        x = ((x >> 16) ^ x) * 0x45d9f3b;
        x = ((x >> 16) ^ x) * 0x45d9f3b;
        x = (x >> 16) ^ x;
        seed ^= x + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
}

template<class T> bool Indexes<T>::operator==(const Indexes<T>& other) const {
    if(this->type == other.type && this->model_id == other.model_id && this->ts == other.ts) return true;
    
    return false;
}