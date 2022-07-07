#pragma once

#include <vector>
#include <map>
#include <string>
#include <algorithm>

#include <multiversion/client/graphics/Type.hpp>
#include <multiversion/client/graphics/Operation.hpp>
#include <multiversion/client/graphics/Icon.hpp>
#include <multiversion/client/graphics/Vertex.hpp>
#include <multiversion/client/graphics/Tesselator.hpp>
#include <multiversion/client/graphics/Model.hpp>

namespace lagrangian {
	namespace graphics {
        class LRenderPipeline {
            public:
            std::map<Indexes<long>, VertexOperation> ops;

            void operate(LModel& vs) {
                vs.operate(ops);
            }
        };

        namespace LRenderer {
            Tessellator tess;
            void render(LRenderPipeline& p, LModel& vs) {
                
                
                p.operate(vs);

                vs.render(tess);
            }
        }
    }
}