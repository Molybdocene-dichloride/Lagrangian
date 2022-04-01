#pragma once

#include <vector>
#include <map>

#include <multiversion/client/graphics/Type.hpp>
#include <multiversion/client/graphics/Icon.hpp>

class Tessellator {
    public:
    void vertex(float x, float y, float z);
};

namespace lagrangian {
	namespace graphics {
        class Vertex : public Operable {
            public:
            Vector3<long> pos;
            Vector2<long> uv;
            Colour colour;
        };
        template<class T> class Transformation {
            public:
            T defaultval;
            virtual Transformation<T>& inverse() = 0;

            virtual void apply(T&) = 0;
            virtual void apply(Operable&) = 0;
        };
        class VertexOperation {
            public:
            virtual void operate(std::vector<Operable>& vs) = 0;
        };

        template<class T> class VertexTransformationOperation : public VertexOperation, public Transformation<T> {
            public:
            virtual void apply(Operable& v) override {
                apply(v.uv);
            }
            virtual void operate(std::vector<Operable>& vs) override {
                std::vector<Operable>::iterator it;
                for(it = vs.begin(); it != vs.end(); it++) {
                    apply(*it);
                }
            }
        };

        class UVOperation : public VertexTransformationOperation<Vector2<long>> {
            public:
            UVOperation(Vector2<long> val) {
                defaultval = val;
            }
            UVOperation(long x, long y) {
                defaultval = {.x=x, .y=y};
            }
            virtual void apply(Vertex& v) {
                apply(v.uv);
            }
        };

        class UVScaleOperation : public UVOperation {
            public:
            UVScaleOperation(Vector2<long> val) : UVOperation(val) { }
            UVScaleOperation(long x, long y) : UVOperation(x, y) { }

            virtual Transformation<Vector2<long>>& inverse() override {
                UVScale u = UVScale(1/defaultval.x, 1/defaultval.y);
                static UVScale& us = u;
                return us;
            };

            virtual void apply(Vector2<long>& v) override {
                v.x *= defaultval.x;
                v.y *= defaultval.y;
            }
        };

        class IconOperation : public VertexTransformationOperation<Icon> {
            public:
            IconOperation(Icon& val) {
                defaultval = val;
            }

            virtual void apply(Icon& v) {
                apply(v);
            }
        };
        class OverlayIconOperation : public IconOperation {
            public:
            OverlayIconOperation(Icon& val) : IconOperation(val) {}

            virtual void apply(Icon& v) override {
                //change
            }
        };

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