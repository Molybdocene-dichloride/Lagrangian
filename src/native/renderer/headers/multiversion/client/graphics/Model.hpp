#pragma once

#include <algorithm>
#include <memory>

#include <map>
#include <unordered_map>

#include <multiversion/client/graphics/Type.hpp>
#include <multiversion/client/graphics/Operation.hpp>
#include <multiversion/client/graphics/Icon.hpp>
#include <multiversion/client/graphics/Vertex.hpp>
#include <multiversion/LRenderState.hpp>
//#include <multiversion/client/graphics/Tesselator.hpp>

namespace lagrangian {
	namespace graphics {
        template<class T> std::vector<std::shared_ptr<T>> slice(const Indexes<long>& range, std::vector<std::shared_ptr<T>> ops);

        class LModel { //interface
            public:
            virtual void operate(VertexOperationMap& ops, LRenderState& state) = 0;
            virtual void render(/*Tessellator tess*/) = 0;
        };
        class LConcreteModel : public LModel {
            public:
            std::string id;

            std::vector<std::shared_ptr<Operable>> icons;
            std::vector<std::shared_ptr<Operable>> vertices;

            public:
            std::vector<std::shared_ptr<Operable>> slice(const Indexes<long>& range);

            virtual void operate(VertexOperationMap& ops, LRenderState& state);
            virtual void render(/*Tessellator tess*/);
        };
        class LPackedModel : public LModel {
            std::vector<std::shared_ptr<LModel>> models;

            public:
            virtual void operate(VertexOperationMap& ops, LRenderState& state);
            virtual void render(/*Tessellator tess*/);

            long count();
        };
    }
}