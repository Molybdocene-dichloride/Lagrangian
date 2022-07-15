#pragma once

#include <multiversion/client/graphics/IconOperation.hpp>

namespace lagrangian {
	namespace graphics {
        template<class O> class O defaultval;
        template<class O> class MonoTransformation::MonoTransformation<O>& inverse() = 0;

        template<class O> class MonoTransformation::apply(O&) = 0;

        IconOperation::IconOperation(IconOperation& op) : IconOperation(op.defaultval) {}
        IconOperation::IconOperation() {
            this->defaultval = Icon();
        }
        IconOperation::IconOperation(Icon& val) {
            this->defaultval = val;
        }
        OverlayIconOperation::OverlayIconOperation() : IconOperation() {}
        OverlayIconOperation::OverlayIconOperation(Icon& val) : IconOperation(val) {}

        virtual void OverlayIconOperation::apply(Icon& v) override {
            //change
        }
    }
}