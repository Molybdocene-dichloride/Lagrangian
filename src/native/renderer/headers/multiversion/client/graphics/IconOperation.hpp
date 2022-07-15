#pragma once

#include <multiversion/client/graphics/Operation.hpp>

namespace lagrangian {
	namespace graphics {
        template<class O> class MonoTransformation {
            public:
            O defaultval;

            virtual void apply(O&) = 0;
        };
        class IconOperation : public VertexOperation, MonoTransformation<Icon> {
            public:
            IconOperation(IconOperation& op);
            IconOperation();
            IconOperation(Icon& val);
        };
        class OverlayIconOperation : public IconOperation {
            public:
            OverlayIconOperation();
            OverlayIconOperation(Icon& val);

            virtual void apply(Icon& v) override;
        };
    }
}