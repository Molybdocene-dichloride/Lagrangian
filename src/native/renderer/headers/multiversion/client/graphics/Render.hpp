#pragma once

#include <vector>
#include <map>
#include <string>
#include <algorithm>

#include <multiversion/client/graphics/Type.hpp>
#include <multiversion/client/graphics/Operation.hpp>
#include <multiversion/client/graphics/Icon.hpp>
#include <multiversion/client/graphics/Vertex.hpp>
//#include <mcpe/Tesselator.hpp>
#include <multiversion/client/graphics/Model.hpp>
#include <multiversion/LRenderState.hpp>

namespace lagrangian {
	namespace graphics {
        class LRenderPipeline {
            public:
            std::map<Indexes<long>, std::shared_ptr<VertexOperation<Operable>>> ops;

            void operate(LModel& vs, LRenderState& state);
        };
        namespace LRenderer {
            //Tessellator tess;

            void begin(); //To Do
            void render(LModel& vs);
            void render(LModel& vs, LRenderPipeline& p);
            void render(LModel& vs, LRenderPipeline& p, LRenderState& state);
            void draw();
        }
    }
}