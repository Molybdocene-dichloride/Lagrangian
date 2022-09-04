#pragma once

#include <stl/memory>

namespace mce {
    class RenderMaterialInfo;
}

class MaterialPtr {
    newstd::shared_ptr<mce::RenderMaterialInfo> ptr;
};