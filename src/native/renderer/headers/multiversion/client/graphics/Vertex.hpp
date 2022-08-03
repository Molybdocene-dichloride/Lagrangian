#pragma once

#include <multiversion/client/graphics/Type.hpp>
#include <multiversion/client/graphics/Operable.hpp>

namespace lagrangian {
	namespace graphics {
        class Vertex : public Operable {
            public:
            Vector3<long> pos;
            Vector2<long> uv;
            Colour colour = Colour::NONE;

            Vertex(Vector3<long> pos, Vector2<long> uv, Colour colour);

            void clear();
        };
    }
}