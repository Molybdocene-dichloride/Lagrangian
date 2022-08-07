#include <multiversion/client/graphics/Render.hpp>

namespace lagrangian {
	namespace graphics {
        void LRenderPipeline::operate(LModel& vs, LRenderState& state) {
            vs.operate(ops, state);
        }

        void render(LModel& vs) {
            //vs.render(tess);
        }

        void render(LModel& vs, LRenderPipeline& p) {
            //render(vs, p, {.verts, .icons});
        }

        void LRenderer::render(LModel& vs, LRenderPipeline& p, LRenderState& state) {
            //p.operate(vs, state);

            //render(vs);
        }

        void LRenderer::begin() {
            //tess.end();
        }

        void LRenderer::draw() {
            //tess.end();
        }
    }
}