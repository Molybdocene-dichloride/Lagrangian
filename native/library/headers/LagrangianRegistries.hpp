#pragma once

#include <stl/string>

#include <mcpe/creative/CreativeItemRegistry.hpp>

namespace LagrangianRegistries {
	CreativeItemRegistry* _vanillaCreativeRegister;
	void prepare() {
		_vanillaCreativeRegister = CreativeItemRegistry.mCurrentRegistry;
	}
	void registryEffect(PotionEffect* effect) {
		mMobEffects.add(effect.nms());
	}
	/*PotionEffect* getEffect(id) {
		return eff;
	}*/
	CreativeItemGroupCategory* registerCategory(std::__ndk1::string& id, CreativeItemCategory& cic) {
  		return _vanillaCreativeRegister->newCreativeItemCategory(id, cic);
	}
	CreativeItemGroupCategory* getCategory(CreativeItemCategory& cic) {
	  return _vanillaCreativeRegister->getCreativeCategory(id, cic);
	}
}
