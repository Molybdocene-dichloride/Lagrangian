#include <multiversion/client/graphics/Model.hpp>

namespace lagrangian {
	namespace graphics {
        std::vector<Operable*> LConcreteModel::slice(const Indexes<long>& range) { //smart pointers!
            if(range.type == OperableType::VERTEX) {
                return slice(vertices, range);
            } else if(range.type == OperableType::ICON) {
                return slice(icons, range);
            }
        }

        void LConcreteModel::operate(std::map<Indexes<long>, VertexOperation*>& ops, LRenderState& state) {
            std::map<Indexes<long>, VertexOperation*>::iterator it;
            for(it = ops.begin(); it != ops.end(); it++) {
                if(std::find(it->first.model_id.begin(), it->first.model_id.end(), id) != it->first.model_id.end()) it->second->operate(slice(it->first), slice(it->first, state));
            }
        }
        void LConcreteModel::render(/*Tessellator tess*/) {
            //for(int e = 0; e < vertices.size(); e++) {
                //tess.vertexUV(vertices.at(e).pos.x, vertices.at(e).pos.y, vertices.at(e).pos.z);
                //tess.color
           //}
        }
        void LPackedModel::operate(std::map<Indexes<long>, VertexOperation*>& ops, LRenderState& state) {
            for(int i = 0; i < count(); i++) {
                models.at(i)->operate(ops, state);
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

        std::vector<Operable*> slice(std::vector<Operable*> ops, const Indexes<long>& range) { //smart pointers!
            std::vector<Operable*> vs{};
            std::vector<long>::const_iterator it;
            for(it = range.ts.begin(); it != range.ts.end(); it++) {
                vs.push_back(ops.at(*it));
            }
            return vs;
        }
    }
}