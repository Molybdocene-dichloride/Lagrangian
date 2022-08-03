#pragma once
#include <mcpe/BlockSource.hpp>
#include <mcpe/BlockPos.hpp>
#include <mcpe/block/Block.hpp>
#include <mcpe/Random.hpp>

class LiquidBlock : public BlockLegacy {
    public:
    //Virtual Tables
	virtual ~LiquidBlock();
	virtual void getAABB(BlockSource&, BlockPos const&, Block const&, AABB&, bool) const;
	virtual void canContainLiquid() const;
	virtual void checkIsPathable(Actor&, BlockPos const&, BlockPos const&) const;
	virtual void mayPick(BlockSource&, Block const&, bool) const;
	virtual void neighborChanged(BlockSource&, BlockPos const&, BlockPos const&) const;
	virtual void getResourceCount(Random&, Block const&, int, bool) const;
	virtual void handleEntityInside(BlockSource&, BlockPos const&, Actor*, Vec3&) const;
	virtual void getColor(Block const&) const;
	virtual void getColorAtPos(BlockSource&, BlockPos const&) const;
	virtual void onGraphicsModeChanged(BlockGraphicsModeChangeContext const&);
	virtual void animateTick(BlockSource&, BlockPos const&, Random&) const;
	virtual void canBeSilkTouched() const;
	virtual void onPlace(BlockSource&, BlockPos const&) const;
	virtual void getMapColor(BlockSource&, BlockPos const&) const;
	public:
    //Methods
    LiquidBlock(std::__ndk1::basic_string<char, std::__ndk1::char_traits<char>, std::__ndk1::allocator<char> > const&, int, Material const&);
    void getDepth(BlockSource&, BlockPos const&) const;
    void emitFizzParticle(BlockSource&, BlockPos const&) const;
    void _getFlow(BlockSource&, BlockPos const&) const;
    void getTickDelay(BlockSource&) const;
    void getHeightFromData(int);
    void getSlopeAngle(BlockSource&, BlockPos const&, Material const&);
    void getBrightness(BlockSource&, BlockPos const&);
    void getRenderedDepth(BlockSource&, BlockPos const&) const;
    void trySpreadFire(BlockSource&, BlockPos const&, Random&) const;
    void solidify(BlockSource&, BlockPos const&, BlockPos const&) const;
    void getHeightFromDepth(int);
};
class LiquidBlockDynamic : public LiquidBlock {
    public:
    //Virtual Tables
	virtual ~LiquidBlockDynamic();
	virtual void entityInside(BlockSource&, BlockPos const&, Actor&) const;
	virtual void onPlace(BlockSource&, BlockPos const&) const;
	virtual void tick(BlockSource&, BlockPos const&, Random&) const;
	public:
    //Methods
    LiquidBlockDynamic(std::__ndk1::basic_string<char, std::__ndk1::char_traits<char>, std::__ndk1::allocator<char> > const&, int, Material const&);
    void _canSpreadTo(BlockSource&, BlockPos const&, BlockPos const&, unsigned char) const;
    void getSpread(BlockSource&, BlockPos const&) const;
    void _spread(BlockSource&, BlockPos const&, int, bool) const;
    void _trySpreadTo(BlockSource&, BlockPos const&, int, BlockPos const&, unsigned char) const;
    void _setStatic(BlockSource&, BlockPos const&, bool) const;
    void _getHighest(BlockSource&, BlockPos const&, int, int&) const;
    void _tick(BlockSource&, BlockPos const&, Random&, bool) const;
    void shouldBecomeStatic(BlockSource&, BlockPos const&, Random&) const;
    void _isWaterBlocking(BlockSource&, BlockPos const&, BlockPos const&, unsigned char) const;
    void _tryingToFlowIntoMatchingSource(BlockPos const&, BlockSource const&) const;
    void _getStartingPass(BlockSource const&, BlockPos const&) const;
    void _getSlopeDistance(BlockSource&, BlockPos const&, int, int) const;
};
