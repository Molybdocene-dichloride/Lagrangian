#include <multiversion/client/graphics/Model.hpp>

namespace lagrangian {
	namespace graphics {
        template<class T> std::vector<std::shared_ptr<T>> slice(const Indexes<long>& range, std::vector<std::shared_ptr<T>> ops) {
            std::vector<std::shared_ptr<Operable>> vs{};
            std::vector<long>::const_iterator it;
            for(it = range.ts.begin(); it != range.ts.end(); it++) {
                vs.push_back(ops.at(*it));
            }
            return vs;
        }

        std::vector<std::shared_ptr<Operable>> LConcreteModel::slice(const Indexes<long>& range) {
            if(range.type == OperableType::VERTEX) {
                return lagrangian::graphics::slice(range, vertices);
            } else if(range.type == OperableType::ICON) {
                return lagrangian::graphics::slice(range, icons);
            }
        }

        void LConcreteModel::operate(std::map<Indexes<long>, std::shared_ptr<VertexOperation<Operable>>>& ops, LRenderState& state) {
            for(auto it = ops.begin(); it != ops.end(); it++) {
                std::vector<std::shared_ptr<Operable>> ops_slc = slice(it->first);
                std::vector<std::shared_ptr<Operable>> st_slc = lagrangian::graphics::slice(it->first, state.vertices);
                /*if(std::find(i, ops.size(), id) != ops.size())*/ it->second->operate(ops_slc, st_slc);
            }
        }
        void LConcreteModel::render(/*Tessellator tess*/) {
            //for(int e = 0; e < vertices.size(); e++) {
                //tess.vertexUV(vertices.at(e).pos.x, vertices.at(e).pos.y, vertices.at(e).pos.z);
                //tess.color
           //}
        }
        void LPackedModel::operate(std::map<Indexes<long>, std::shared_ptr<VertexOperation<Operable>>>& ops, LRenderState& state) {
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
    }
}