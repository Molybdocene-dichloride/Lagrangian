#pragma once

namespace lagrangian {
	namespace graphics {
        class LRenderState { //result and cache
            std::vector<Icon*> icons;
            std::vector<Vertex*> vertices;
        };
    }
}