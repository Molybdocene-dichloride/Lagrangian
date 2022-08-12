#pragma once

#include <memory>

namespace lagrangian {
	namespace graphics {
        class LRenderState { //result and cache
            public:
            std::vector<std::shared_ptr<Operable>> icons;
            std::vector<std::shared_ptr<Operable>> vertices;

            LRenderState() {
                icons = std::vector<std::shared_ptr<Operable>>();
                vertices = std::vector<std::shared_ptr<Operable>>();
            }
        };
    }
}