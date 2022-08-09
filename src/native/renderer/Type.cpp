#include <multiversion/client/graphics/Type.hpp>

Colour Colour::NONE = Colour{r: 0, g: 0, b: 0, a: 0};

Colour Colour::WHITE = Colour{r: 255, g: 255, b: 255, a: 255};

Colour Colour::BLACK = Colour{r: 0, g: 0, b: 0, a: 255};

template<class T> std::size_t IndexesHash<Indexes<T>>::operator()(Indexes<T> const& s) const {
    std::size_t seed = s.ts.size();
    for(auto x : s.ts) {
        x = ((x >> 16) ^ x) * 0x45d9f3b;
        x = ((x >> 16) ^ x) * 0x45d9f3b;
        x = (x >> 16) ^ x;
        seed ^= x + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
}

{
    if(this->type == other.type && this->model_id == other.model_id && this->ts == other.ts)
}