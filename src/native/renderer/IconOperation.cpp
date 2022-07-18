#include <multiversion/client/graphics/IconOperation.hpp>

namespace lagrangian {
	namespace graphics {

        IconOperation::IconOperation(IconOperation& op) : IconOperation(op.defaultval) {}
        IconOperation::IconOperation() {
            this->defaultval = Icon();
        }
        IconOperation::IconOperation(Icon& val) {
            this->defaultval = val;
        }
        OverlayIconOperation::OverlayIconOperation() : IconOperation() {}
        OverlayIconOperation::OverlayIconOperation(Icon& val) : IconOperation(val) {}

        void OverlayIconOperation::apply(Icon& v) {
            //change
        }
    }
}