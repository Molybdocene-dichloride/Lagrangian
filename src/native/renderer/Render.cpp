#pragma once

#include <multiversion/client/graphics/Render.hpp>

namespace lagrangian {
	namespace graphics {
        void LRenderPipeline::operate(LModel& vs) {
            vs.operate(ops);
        }

        void LRenderer::render(LRenderPipeline& p, LModel& vs) {
            //p.operate(vs);

            //vs.render(tess);
        }
    }
}