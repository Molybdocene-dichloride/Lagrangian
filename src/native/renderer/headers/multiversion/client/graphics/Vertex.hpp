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

            Vertex(Vector3<long> pos, Vector2<long> uv, Colour colour) {
                this->pos = pos;
                this->uv = uv;
                this->colour = colour;
            }

            void clear() {
				this->pos.x = 0;
                this->pos.y = 0;
                this->pos.z = 0;

                this->uv.x = 0;
                this->uv.y = 0;

                this->colour = Colour::NONE;
			}
        };
    }
}