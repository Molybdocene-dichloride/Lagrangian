#include <multiversion/client/graphics/Operation.hpp>

namespace lagrangian {
	namespace graphics {
        template<class T> void VertexTransformationOperation<T>::apply(Vertex& v) {
            apply(v);
        }
        template<class T> void VertexTransformationOperation<T>::operate(std::vector<Operable*>& vs) {
            std::vector<Operable*>::iterator it;
            for(it = vs.begin(); it != vs.end(); it++) {
                apply(*dynamic_cast<Vertex*>(*it));
            }
        }

        UVOperation::UVOperation(UVOperation& op) : UVOperation(op.defaultval) {}
        UVOperation::UVOperation() : UVOperation(0, 0) {}
        UVOperation::UVOperation(Vector2<long> val) {
            defaultval = val;
        }
        UVOperation::UVOperation(long x, long y) {
            defaultval = {.x=x, .y=y};
        }

        UVScaleOperation::UVScaleOperation() : UVOperation() { }
        UVScaleOperation::UVScaleOperation(Vector2<long> val) : UVOperation(val) { }
        UVScaleOperation::UVScaleOperation(long x, long y) : UVOperation(x, y) { }

        Transformation<Vertex, Vector2<long>>& UVScaleOperation::inverse() {
                UVScaleOperation u(1/defaultval.x, 1/defaultval.y);
                
                static UVScaleOperation& us = u;
                return us;
        }

        void UVScaleOperation::apply(Vertex& v) {
            apply(v.uv);
        }

        void UVScaleOperation::apply(Vector2<long>& v) {
                v.x *= defaultval.x;
                v.y *= defaultval.y;
        }

        void UVScaleOperation::applyInv(Vector2<long>& v) {
                v.x *= -defaultval.x;
                v.y *= -defaultval.y;
        }
    }
}