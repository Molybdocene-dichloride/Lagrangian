#pragma once

#include <multiversion/client/graphics/Operation.hpp>

namespace lagrangian {
	namespace graphics { 
        class IconOperation : public VertexTransformationOperation<Icon> {
            public:
            IconOperation(Icon& val) {
                defaultval = val;
            }

            virtual void apply(Icon& v) {
                apply(v);
            }
        };
        class OverlayIconOperation : public IconOperation {
            public:
            OverlayIconOperation(Icon& val) : IconOperation(val) {}

            virtual void apply(Icon& v) override {
                //change
            }
        };
    }
}