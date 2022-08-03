#include <multiversion/client/graphics/Vertex.hpp>

namespace lagrangian {
	namespace graphics {
        Vertex::Vertex(Vector3<long> pos, Vector2<long> uv, Colour colour) {
            this->pos = pos;
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