#pragma once

#include <multiversion/client/graphics/Type.hpp>
#include <multiversion/client/graphics/Operation.hpp>
#include <multiversion/client/graphics/Icon.hpp>
#include <multiversion/client/graphics/Vertex.hpp>
#include <multiversion/client/graphics/Tesselator.hpp>

namespace lagrangian {
	namespace graphics {
        class LModel {
            public:
            virtual void operate(std::map<Indexes<long>, VertexOperation>& ops) = 0;
            virtual void render(/*Tessellator tess*/) = 0;
        };
        class LConcreteModel : public LModel {
            std::string id;

            std::vector<Icon> icons;
            std::vector<Vertex> vertices;

            public:
            std::vector<Operable> slice(Indexes<long>& range);

            virtual void operate(std::map<Indexes<long>, VertexOperation>& ops);
            virtual void render(/*Tessellator tess*/);
        };
        class LPackedModel : public LModel {
            std::vector<LModel> models;

            public:
            virtual void operate(std::map<Indexes<long>, VertexOperation>& ops);
            virtual void render(/*Tessellator tess*/);

            long count();
        };
    }
}