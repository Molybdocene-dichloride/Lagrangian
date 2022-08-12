#include <multiversion/client/graphics/Operation.hpp>
#include <iostream>

namespace lagrangian {
	namespace graphics {
        template<class T> void VertexTransformationOperation<T>::apply(Vertex& v, Vertex& state) {
            apply(v, state);
        }
        template<class T> void VertexTransformationOperation<T>::operate(std::vector<std::shared_ptr<Vertex>>& vs, std::vector<std::shared_ptr<Vertex>>& state) {
            for(int i = 0; i < vs.size(); i++) {
                apply(*vs.at(i), *state.at(i));
                std::cout << "state->uv.x" << std::endl;
                std::cout << state.at(i)->uv.x << std::endl;
                std::cout << state.at(i)->uv.y << std::endl;

                std::cout << state.at(i).use_count() << std::endl;
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

        UVScaleOperation UVScaleOperation::inverse() {
                UVScaleOperation u(1/defaultval.x, 1/defaultval.y);

                return u;
        }

        void UVScaleOperation::apply(Vertex& v, Vertex& statev) {
            apply(v.uv, statev.uv);
        }

        void UVScaleOperation::apply(Vector2<long>& v, Vector2<long>& statev) {
                statev.x = v.x * defaultval.x;
                statev.y = v.y * defaultval.y;
                std::cout << "statev.y" << std::endl;
                std::cout << statev.x << std::endl;
                std::cout << statev.y << std::endl;
        }

        void UVScaleOperation::applyInv(Vector2<long>& v, Vector2<long>& statev) {
                statev.x = v.x * -defaultval.x;
                statev.y = v.y * -defaultval.y;
        }
    }
}