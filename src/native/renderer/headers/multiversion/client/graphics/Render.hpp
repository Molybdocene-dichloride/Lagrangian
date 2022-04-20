#pragma once

#include <vector>
#include <map>
#include <string>
#include <algorithm>

#include <multiversion/client/graphics/Type.hpp>
#include <multiversion/client/graphics/Operation.hpp>
#include <multiversion/client/graphics/Icon.hpp>
#include <multiversion/client/graphics/Vertex.hpp>

namespace lagrangian {
	namespace graphics {
        class LModel {
            public:
            virtual void operate(std::map<Indexes<long>, VertexOperation>& ops) = 0;
            virtual void render(Tessellator tess) = 0;
        };
        class LConcreteModel : public LModel {
            std::string id;

            std::vector<Icon> icons;
            std::vector<Vertex> vertices;

            public:
            std::vector<Operable> slice(Indexes<long>& range) {
                if(range.type == OperableType::VERTEX) {
                    std::vector<Vertex> vs{};
                    std::vector<long>::iterator it;
                    for(it = range.ts.begin(); it != range.ts.end(); it++) {
                        vs.insert(vertices.at(range.ts.at(it)));
                    }
                    return vs;
                } else if(range.type == OperableType::ICON) {
                    std::vector<Icon> vs{};
                    std::vector<long>::iterator it;
                    for(it = range.ts.begin(); it != range.ts.end(); it++) {
                        vs.insert(icons.at(range.ts.at(it)));
                    }
                    return vs;
                }
            }

            virtual void operate(std::map<Indexes<long>, VertexOperation>& ops) {
                std::map<Indexes<long>, VertexOperation>::iterator it;
                for(it = ops.begin(); it != ops.end(); it++) {
                    if(std::find(it->first.model_id.begin(), it->first.model_id.end(), id) != it->first.model_id.end()) it->second.apply(slice(it->first));
                }
            }
            virtual void render(Tessellator tess) {
                for(int e = 0; e < vertices.size(); e++) {
                    tess.vertex(vertices.at(e).pos.x, vertices.at(e).pos.y, vertices.at(e).pos.z);
                }
            }
        };
        class LPackedModel : public LModel {
            std::vector<LModel> models;

            public:
            virtual void operate(std::map<Indexes<long>, VertexOperation>& ops) {
                for(int i = 0; i < count(); i++) {
                    models.at(i).operate(ops);
                }
            }
            virtual void render(Tessellator tess) {
                for(int i = 0; i < count(); i++) {
                    models.at(i).render(tess);
                }
            }

            long count() {
                return models.size();
            }
        };
        class LRenderPipeline {
            public:
            std::map<Indexes<long>, VertexOperation> ops;

            void operate(LModel& vs) {
                vs.operate(ops);
            }
        };

        namespace LRenderer {
            Tessellator tess;
            void render(LRenderPipeline& p, LModel& vs) {
                
                
                p.operate(vs);

                vs.render(tess);
            }
        }
    }
}