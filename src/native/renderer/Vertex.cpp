#include <multiversion/client/graphics/Vertex.hpp>

namespace lagrangian {
	namespace graphics {
        Vertex::Vertex() {
            this->pos = {.x = 0, .y = 0, .z = 0};
            this->uv = {.x = 0, .y = 0};
            this->colour = Colour::NONE;
        }
        Vertex::Vertex(Vector3<long> pos) {
            this->pos = pos;
            this->uv = {.x = 0, .y = 0};
            this->colour = Colour::NONE;
        }
        Vertex::Vertex(Vector3<long> pos, Vector2<long> uv, Colour colour) : Vertex(pos) {
            this->uv = uv;
            this->colour = colour;
        }

        void Vertex::clear() {
			this->pos.x = 0;
            this->pos.y = 0;
            this->pos.z = 0;

            this->uv.x = 0;
            this->uv.y = 0;

            this->colour = Colour::NONE;
		}
    }
}