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

namespace lagrangian {
	namespace graphics {
        class LRenderPipeline {
            public:
            std::map<Indexes<long>, VertexOperation*> ops;

            void operate(LModel& vs);
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