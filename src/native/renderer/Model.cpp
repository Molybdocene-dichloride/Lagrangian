#include <multiversion/client/graphics/Model.hpp>
#include <iostream>

namespace lagrangian {
	namespace graphics {
        template<class T> std::vector<std::shared_ptr<T>> slice(const Indexes<long>& range, std::vector<std::shared_ptr<T>> ops) {
            std::vector<std::shared_ptr<Operable>> vs{};
            std::vector<long>::const_iterator it;
            for(it = range.ts.begin(); it != range.ts.end(); it++) {
                vs.push_back(std::shared_ptr<T>(ops.at(*it)));
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

        void LConcreteModel::operate(VertexOperationMap& ops, LRenderState& state) {
            ///for(long i = 0; i < vertices.size(); i++) {
                //if(state.vertices.count(i) > 0) {
                    //iscopy = true;
                    //break;
                //}
            //}

            //copy

            for(int i = state.vertices.size(); i < vertices.size(); i++) {
                state.vertices.insert(state.vertices.begin() + i, std::shared_ptr<Operable>(new Vertex()));
            }
            
            for(auto it = ops.begin(); it != ops.end(); it++) {
                std::vector<std::shared_ptr<Operable>> ops_slc = slice(it->first);
                std::vector<std::shared_ptr<Operable>> st_slc = lagrangian::graphics::slice(it->first, state.vertices);
                
                //std::cout << ((std::find(it->first.model_id.begin(), it->first.model_id.end(), id) - it->first.model_id.begin()) != -1) << std::endl;

                if((std::find(it->first.model_id.begin(), it->first.model_id.end(), id) - it->first.model_id.begin()) != -1) {
                    std::cout << "id is exists" << std::endl;
                    it->second->operate(ops_slc, st_slc);
                }
            }
        }
        void LConcreteModel::render(/*Tessellator tess*/) {
            //for(int e = 0; e < vertices.size(); e++) {
                //tess.vertexUV(vertices.at(e).pos.x, vertices.at(e).pos.y, vertices.at(e).pos.z);
                //tess.color
           //}
        }
        void LPackedModel::operate(VertexOperationMap& ops, LRenderState& state) {
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