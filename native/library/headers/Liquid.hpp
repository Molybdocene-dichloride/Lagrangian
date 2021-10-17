#pragma once
#include <logger.h>
#include <mod.h>
#include <symbol.h>
#include <hook.h>

#include <mcpe/item/ItemStack.hpp>
#include <mcpe/block/Liquid.hpp>

namespace LiquidSystem {
  std::__ndk1::unorderedmap<unsigned int, CustomLiquidMaterial*> custom;
	void enableInfinitySources(std::__ndk1::string id) {
		custom[BlockRegistry::Pool->get(id.c_str())].enableInfinitySources();
	}
	void enableInfinitySources(unsigned int id) {
		custom[id].enableInfinitySources();
	}
	void disableInfinitySources(std::__ndk1::string id) {
		custom[BlockRegistry::Pool->get(id.c_str())].disableInfinitySources();
	}
	void disableInfinitySources(unsigned int id) {
		custom[id].disableInfinitySources();
	}
	
	void registerLiquidBlock(CustomLiquidBlock* lblock, BlockProvider* pr) {
		BlockRegistry::registerBlock(lblock, pr);
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
		char FILLER[UNKNOWN_SIZE];
		private bool isInfinity;
		private short maxSpread;
		private short viscosity;
		CustomLiquidMaterial(Material& mat, isInfinity, maxSpread, viscosity) : CustomLiquidMaterial(mat.type, Settings::Default, mat.getTranslucency(), isInfinity, maxSpread, viscosity) {
			
		} //CustomLiquidMaterial, Water or Lava only
		CustomLiquidMaterial(MaterialType type, Material::Settings settings, float f0) : Material(type, settings, f0) {
			this->isInfinity = isInfinity;
			this->maxSpread = maxSpread;
			this->viscosity = viscosity;
		}
		
		Vec3 _getFlow(BlockSource& source, BlockPos const& pos, short rotation) const {
			BlockPos bp = getRelative(pos, rotation);
			if(source.getBlock(bp).id == 0) return bp;
			return pos;
		}
		int getTickDelay(BlockSource& source) {
			return this->getViscosity();
		}
		bool isInfinitySourcesEnabled() {
			return this->isInfinity;
		};
		void enableInfinitySources() {
			this->isInfinity = true;
		};
		void disableInfinitySources() {
			this->isInfinity = false;
		};
		short getMaxSpread() {
			return this->maxSpread;
		};
		short getViscosity() {
			return this->viscosity;
		};
	};
	class CustomLiquidBlock : public LiquidBlockDynamic {
		CustomLiquidBlock(std::string const& name, CustomLiquidMaterial const& material) : BlockLegacy(name, material) {}; //CustomLiquidMaterial
		Vec3 getFlow(BlockSource& source, BlockPos const& pos, short rotation) const {
			return this->getMaterial()._getFlow(source, pos, rotation);
		}
		int getTickDelay(BlockSource& source) {
			return this->getMaterial().getViscosity();
		}
		void tick(BlockSource& source, BlockPos const& pos, Random& rand) const {
			short data =;
			
			Vec3 flow = this->getFlow(source, pos, 0);
			if(pos == flow) {
				Vec3 flow2 = this->getFlow(source, pos, 2);
				Vec3 flow3 = this->getFlow(source, pos, 3);
				Vec3 flow4 = this->getFlow(source, pos, 4);
				Vec3 flow5 = this->getFlow(source, pos, 5);
				
				if(flow2 != pos) source.setBlock(pos.x, pos.y, pos.z, this, data + 1);
				if(flow3 != pos) source.setBlock(pos.x, pos.y, pos.z, this, data + 1);
				if(flow4 != pos) source.setBlock(pos.x, pos.y, pos.z, this, data + 1);
				if(flow5 != pos) source.setBlock(pos.x, pos.y, pos.z, this, data + 1);
			} else {
				source.setBlock(pos.x, pos.y, pos.z, this, 0);
			}
		}
	};
