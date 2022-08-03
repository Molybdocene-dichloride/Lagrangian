#pragma once
#include <logger.h>
#include <mod.h>
#include <symbol.h>
#include <hook.h>

#include <mcpe/item/ItemStack.hpp>
#include <mcpe/block/Liquid.hpp>

namespace LiquidSystem {
	std::__ndk1::unorderedmap<std::__ndk1::string, CustomLiquidBlock*> customBlks;
	void enableInfinitySources(std::__ndk1::string id) {
		customBlks[id]->getMaterial().enableInfinitySources();
	}
	void disableInfinitySources(std::__ndk1::string id) {
		customBlks[id]->getMaterial().disableInfinitySources();
	}
	
	void newLiquidBlock(std::__ndk1::string id, CustomLiquidBlock* lblock) {
		customBlks[id] = lblock;
	}
	void registerLiquidBlocks(LegacyBlockRegistry::LegacyBlockFactory* factory) {
		for(std::__ndk1::unorderedmap<std::__ndk1::string, CustomLiquidBlock*>::iterator i = customBlks.begin(); i < customBlks.end(); ++i) {
			BlockRegistry::registerBlock(customBlks[i], new LegacyBlockRegistry::LegacyBlockProvider(factory));
		}
	}
	
	CustomLiquidMaterial* toCLM(Material* mat) {
		if(CustomLiquidMaterial* v = dynamic_cast<CustomLiquidMaterial*>(mat)) {
			return v;
		} else if(mat.type == MaterialType::Water || mat.type == MaterialType::Lava) {
			return new CustomLiquidMaterial(mat);
		}
	}
}

class CustomLiquidMaterial : public Material {
	private bool isInfinity;
	private short maxSpread;
	private short viscosity;
	CustomLiquidMaterial(Material& mat, bool isInfinity, short maxSpread, short viscosity) {
		CustomLiquidMaterial(mat.type, Material::Settings::Default, mat.getTranslucency(), isInfinity, maxSpread, viscosity);
	} //CustomLiquidMaterial, Water or Lava only
	CustomLiquidMaterial(MaterialType type, Material::Settings settings, float f0, bool isInfinity, short maxSpread, short viscosity) {
		Material(type, settings, f0);
		this->isInfinity = isInfinity;
		this->maxSpread = maxSpread;
		this->viscosity = viscosity;
	}
		
	BlockPos _getFlow(BlockSource& source, BlockPos const& pos, short side) const {
		BlockPos bp = RotationTransforms::getRelativeCoords(pos.x, pos.y, pos.z, side);
			
		if(source.getBlock(bp).id == 0 || source.getBlock(bp).canContainLiquid()) return bp;
		return pos;
	}
	bool isInfinity() {
		return this->isInfinity;
	}
	void enableInfinitySources() {
		this->isInfinity = true;
	}
	void disableInfinitySources() {
		this->isInfinity = false;
	}
	short getMaxSpread() {
		return this->maxSpread;
	}
	short getViscosity() {
		return this->viscosity;
	}
};
class CustomLiquidBlock : public LiquidBlockDynamic {
	CustomLiquidBlock(std::__ndk::string const& name, CustomLiquidMaterial const& material) {
		LiquidBlockDynamic(name, material);
	} //CustomLiquidMaterial
	BlockPos getFlow(BlockSource& source, BlockPos const& pos, short side) const {
		return this->getMaterial()._getFlow(source, pos, side);
	}
	int getTickDelay(BlockSource& source) const {
		return this->getMaterial().getViscosity();
	}
	void tick(BlockSource& source, BlockPos const& pos, Random& rand) const {
		short data = data;
			
		BlockPos flow = this->getFlow(source, pos, 0);
		if(pos == flow) {
			BlockPos flow2 = this->getFlow(source, pos, 2);
			BlockPos flow3 = this->getFlow(source, pos, 3);
			BlockPos flow4 = this->getFlow(source, pos, 4);
			BlockPos flow5 = this->getFlow(source, pos, 5);
				
			if(flow2 != pos) source.setBlock(pos.x, pos.y, pos.z, this, this->data + 1);
			if(flow3 != pos) source.setBlock(pos.x, pos.y, pos.z, this, this->data + 1);
			if(flow4 != pos) source.setBlock(pos.x, pos.y, pos.z, this, this->data + 1);
			if(flow5 != pos) source.setBlock(pos.x, pos.y, pos.z, this, this->data + 1);
		} else {
			source.setBlock(pos.x, pos.y, pos.z, this, 0);
		}
	}
};

Callback::addCallback("initializeModItems", CALLBACK([], (), {
	LiquidSystem::registerLiquidBlocks(this);
}));
