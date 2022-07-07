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

struct Colour {
    static Colour NONE;

    unsigned char r; unsigned char g; unsigned char b; unsigned char a;
};

Colour Colour::NONE = Colour{.r = 0, .g = 0, .b = 0, .a = 0};