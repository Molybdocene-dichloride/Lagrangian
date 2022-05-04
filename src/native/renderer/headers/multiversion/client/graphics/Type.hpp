#pragma once

#include <vector>
#include <string>

enum class OperableType {
    VERTEX,
    ICON
};

template<class T> struct Vector3 {T x; T y; T z;};

template<class T> struct Vector2 {T x; T y;};

template<class T> struct Indexes {OperableType type; std::vector<std::string> model_id; std::vector<T> ts;};

class Colour {
    public:
    static Colour NONE;

    unsigned char r; unsigned char g; unsigned char b; unsigned char a;

    Colour(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
    }
};
Colour Colour::NONE = Colour(0, 0, 0, 0);