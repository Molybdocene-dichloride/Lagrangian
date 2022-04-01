#pragma once

#include <vector>
#include <map>

#include <multiversion/client/graphics/Type.hpp>
#include <multiversion/client/graphics/Operation.hpp>
#include <multiversion/client/graphics/Icon.hpp>
#include <multiversion/client/graphics/Vertex.hpp>

class Tessellator {
    public:
    void vertex(float x, float y, float z);
};

namespace lagrangian {
	namespace graphics {
        class LModel {
            public:
            //std::vector<Magick::Image> textures;
            std::vector<Vertex> vertices;

            std::vector<Vertex> slice(Range<long> range) {
                return std::vector<Vertex>(vertices.begin() + range.min, vertices.begin() + range.max);
            }
        };
        class LRenderPipeline {
            public:
            std::map<Range<long>, VertexOperation> ops;

            void operate(LModel& vs) {
                std::map<Range<long>, VertexOperation>::iterator it;
                for(it = ops.begin(); it != ops.end(); it++) {
                    it->second.apply(vs.slice(it->first));
                }
            }
        };
        
        namespace LRenderer {
            Tessellator tess;
            void render(LRenderPipeline& p, LModel& vs) {
                p.operate(vs);

                for(int e = 0; e < vs.vertices.size(); e++) {
                    tess.vertex(vs.vertices.at(e).pos.x, vs.vertices.at(e).pos.y, vs.vertices.at(e).pos.z);
                }
            }
        }
    }
}