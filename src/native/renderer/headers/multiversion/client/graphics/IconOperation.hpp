#pragma once

#include <multiversion/client/graphics/Operation.hpp>

namespace lagrangian {
	namespace graphics {
        template<class O> class MonoTransformation {
            public:
            O defaultval;

            //MonoTransformation<O>& inverse() = 0;
            virtual void apply(O&) = 0;
        };
        class IconOperation : public VertexOperation<Icon>, public MonoTransformation<Icon> {
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