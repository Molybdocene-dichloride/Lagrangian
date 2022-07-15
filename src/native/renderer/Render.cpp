#pragma once

#include <multiversion/client/graphics/Render.hpp>

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
            //Tessellator tess;
            void render(LRenderPipeline& p, LModel& vs) {
                
                
                p.operate(vs);

                vs.render(tess);
            }
        }
    }
}