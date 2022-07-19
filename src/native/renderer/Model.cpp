#include <multiversion/client/graphics/Model.hpp>

namespace lagrangian {
	namespace graphics {
        std::vector<Operable*>& LConcreteModel::slice(const Indexes<long>& range) { //smart pointers!
            if(range.type == OperableType::VERTEX) {
                std::vector<Operable*> vs{};
                std::vector<long>::const_iterator it;
                for(it = range.ts.begin(); it != range.ts.end(); it++) {
                    vs.push_back(vertices.at(*it));
                }
                return vs;
            } else if(range.type == OperableType::ICON) {
                std::vector<Operable*> vs{};
                std::vector<long>::const_iterator it;
                for(it = range.ts.begin(); it != range.ts.end(); it++) {
                    vs.push_back(icons.at(*it));
                }
                return vs;
            }
        }

        void LConcreteModel::operate(std::map<Indexes<long>, VertexOperation*>& ops) {
            std::map<Indexes<long>, VertexOperation*>::iterator it;
            for(it = ops.begin(); it != ops.end(); it++) {
                if(std::find(it->first.model_id.begin(), it->first.model_id.end(), id) != it->first.model_id.end()) it->second->operate(slice(it->first));
            }
        }
        void LConcreteModel::render(/*Tessellator tess*/) {
            //for(int e = 0; e < vertices.size(); e++) {
                //tess.vertexUV(vertices.at(e).pos.x, vertices.at(e).pos.y, vertices.at(e).pos.z);
                //tess.color
           //}
        }
        void LPackedModel::operate(std::map<Indexes<long>, VertexOperation*>& ops) {
            for(int i = 0; i < count(); i++) {
                models.at(i)->operate(ops);
            }
        }
        void LPackedModel::render(/*Tessellator tess*/) {
            //for(int i = 0; i < count(); i++) {
               // models.at(i).render(tess);
            //}
        }

        long LPackedModel::count() {
            return models.size();
        }
    }
}