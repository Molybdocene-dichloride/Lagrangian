#pragma once

#include <vector>
#include <map>

#include <multiversion/client/graphics/Type.hpp>
#include <multiversion/client/graphics/Icon.hpp>
#include <multiversion/client/graphics/Vertex.hpp>

namespace lagrangian {
	namespace graphics {
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