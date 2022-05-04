#pragma once

#include <vector>
#include <map>

#include <multiversion/client/graphics/Type.hpp>
#include <multiversion/client/graphics/Icon.hpp>
#include <multiversion/client/graphics/Vertex.hpp>

namespace lagrangian {
	namespace graphics {
        template<class O, class T> class Transformation {
            public:
            T defaultval;
            virtual Transformation<O, T>& inverse() = 0;

            virtual void apply(T&) = 0;
            virtual void apply(O&) = 0;
        };

        class VertexOperation {
            public:
            virtual void operate(std::vector<Operable>& vs) = 0;
        };

        template<class T> class VertexTransformationOperation : public VertexOperation, public Transformation<Vertex, T> {
            public:
            virtual void apply(Vertex& v) override {
                apply(v);
            }
            virtual void operate(std::vector<Operable>& vs) override {
                std::vector<Operable>::iterator it;
                for(it = vs.begin(); it != vs.end(); it++) {
                    apply(*dynamic_cast<Vertex*>(&*it));
                }
            }
        };

        class UVOperation : public VertexTransformationOperation<Vector2<long>> {
            public:
            UVOperation(UVOperation& op) : UVOperation(op.defaultval) {}
            UVOperation() : UVOperation(0, 0) {}
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
            UVScaleOperation() : UVOperation() { }
            UVScaleOperation(Vector2<long> val) : UVOperation(val) { }
            UVScaleOperation(long x, long y) : UVOperation(x, y) { }

            virtual Transformation<Vertex, Vector2<long>>& inverse() override {
                UVScaleOperation u = UVScaleOperation(1/defaultval.x, 1/defaultval.y);
                static UVScaleOperation& us = u;
                return us;
            };

            virtual void apply(Vector2<long>& v) override {
                v.x *= defaultval.x;
                v.y *= defaultval.y;
            }
        };
    }
}