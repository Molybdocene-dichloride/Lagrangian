#pragma once

#include <memory>
#include <vector>
#include <map>

#include <multiversion/client/graphics/Type.hpp>
#include <multiversion/client/graphics/Icon.hpp>
#include <multiversion/client/graphics/Vertex.hpp>

namespace lagrangian {
	namespace graphics {
        template <class Out, class In> std::shared_ptr<Out> operation_cast(const std::shared_ptr<In> in) {
            In* raw = in.get();

            Out* raw_to = (Out*) raw;

            return std::shared_ptr<Out>(raw_to);
        }

        template<class O, class T> class Transformation {
            public:
            T defaultval;

            virtual void apply(T&, T&) = 0;
            virtual void apply(O&, O&) = 0;
        };

        template<class T> class VertexOperation {
            public:
            virtual void operate(std::vector<std::shared_ptr<T>>& vs, std::vector<std::shared_ptr<T>>& state) = 0;
        };

        template<class T> class VertexTransformationOperation : public VertexOperation<Vertex>, public Transformation<Vertex, T> {
            public:
            virtual void apply(Vertex& v, Vertex& state) override;
            virtual void operate(std::vector<std::shared_ptr<Vertex>>& vs, std::vector<std::shared_ptr<Vertex>>& state) override;
        };

        class UVOperation : public VertexTransformationOperation<Vector2<long>> {
            public:
            UVOperation(UVOperation& op);
            UVOperation();
            UVOperation(Vector2<long> val);
            UVOperation(long x, long y);
        };

        class UVScaleOperation : public UVOperation {
            public:
            UVScaleOperation();
            UVScaleOperation(Vector2<long> val);
            UVScaleOperation(long x, long y);

            virtual Transformation<Vertex, Vector2<long>>& inverse();

            virtual void apply(Vertex& v, Vertex& statev) override;

            virtual void apply(Vector2<long>& v, Vector2<long>& statev) override;

            virtual void applyInv(Vector2<long>& v, Vector2<long>& statev);
        };
    }
}