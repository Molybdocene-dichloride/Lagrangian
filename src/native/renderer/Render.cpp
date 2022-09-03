#include <multiversion/client/graphics/Render.hpp>

namespace lagrangian {
	namespace graphics {
        void LRenderPipeline::operate(LModel& vs, LRenderState& state) {
            vs.operate(ops, state);
        }

        void tessellate(LModel& vs) {
            //vs.tessellate(tess);
        }

        void tessellate(LModel& vs, LRenderPipeline& p) {
            //tessellate(vs, p, {.verts, .icons});
        }

        void LRenderer::tessellate(LModel& vs, LRenderPipeline& p, LRenderState& state) {
            //p.operate(vs, state);

            //tessellate(vs);
        }

        void LRenderer::begin() {
            //tess.end();
        }

        void LRenderer::draw() {
            //tess.end();
        }
    }
}