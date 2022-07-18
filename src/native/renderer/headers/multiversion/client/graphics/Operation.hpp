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

            virtual void apply(T&) = 0;
            virtual void apply(O&) = 0;
        };

        class VertexOperation {
            public:
            virtual void operate(std::vector<Operable>& vs) = 0;
        };

        template<class T> class VertexTransformationOperation : public VertexOperation, public Transformation<Vertex, T> {
            public:
            virtual void apply(Vertex& v) override;
            virtual void operate(std::vector<Operable>& vs) override;
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

            virtual void apply(Vertex& v) override;

            virtual void apply(Vector2<long>& v) override;

            virtual void applyInv(Vector2<long>& v);
        };
    }
}