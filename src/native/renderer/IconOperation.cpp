#pragma once

#include <multiversion/client/graphics/Operation.hpp>

namespace lagrangian {
	namespace graphics {
        template<class O> class MonoTransformation {
            public:
            O defaultval;
            virtual MonoTransformation<O>& inverse() = 0;

            virtual void apply(O&) = 0;
        };
        class IconOperation : public VertexOperation, MonoTransformation<Icon> {
            public:
            IconOperation(IconOperation& op) : IconOperation(op.defaultval) {}
            IconOperation() {
                this->defaultval = Icon();
            }
            IconOperation(Icon& val) {
                this->defaultval = val;
            }
        };
        class OverlayIconOperation : public IconOperation {
            public:
            OverlayIconOperation() : IconOperation() {}
            OverlayIconOperation(Icon& val) : IconOperation(val) {}

            virtual void apply(Icon& v) override {
                //change

            }
        };
    }
}