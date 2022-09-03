#pragma once

#include <mcpe/math/BlockPos.hpp>
#include <mcpe/math/Vec3.hpp>

#include <mcpe/block/Block.hpp>

#include "Tesselator.hpp"

class AirAndSimpleBlockBits;
class TextureUVCoordinateSet;

class BlockTessellator { //from Ghidra
    public:



    void tessellateInWorld(Tessellator&, Block const&, BlockPos const&, TextureUVCoordinateSet const&); //Func with hardcoded tessellation
    void tessellateInWorld(Tessellator&, Block const&, BlockPos const&, bool); //Func with hardcoded tessellation

    void tessellateAll(Tessellator&, Block const&, Vec3 const&, TextureUVCoordinateSet const&);
    void tessellateBlockInWorld(Tessellator&, Block const&, BlockPos const&, AirAndSimpleBlockBits const*);
};