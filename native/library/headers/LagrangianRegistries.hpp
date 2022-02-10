#pragma once

#include <stl/string>

#include <mcpe/creative/CreativeItemRegistry.hpp>
#include <mcpe/creative/CreativeItemCategory.hpp>
#include <mcpe/creative/CreativeItemGroupCategory.hpp>

typedef int ContainerEnumName;
class ContainerEnumNameHasher {
	size_t operator()(ContainerEnumName c) const {
		return 11;
	}
};
extern std::__ndk1::unordered_map<ContainerEnumName, std::__ndk1::string,ContainerEnumNameHasher> ContainerCollectionNameMap;

namespace LagrangianRegistries {
	CreativeItemRegistry* _vanillaCreativeRegister;
	std::__ndk1::map<std::__ndk1::string, ItemCategory> categories;

	std::__ndk1::map<std::__ndk1::string, CreativeItemGroupCategory> registered;

	void registerAll() {
		_vanillaCreativeRegister = CreativeItemRegistry::mCurrentRegistry;
		std::__ndk1::map<std::__ndk1::string, ItemCategory>::iterator at;
        for(at = categories.begin(); at != categories.end(); ++at) {
			_vanillaCreativeRegister->newCreativeCategory(at->second.id, CreativeItemCategory(at->second.index));
		}
	}
	/*void registryEffect(PotionEffect* effect) {
		mMobEffects.add(effect.nms());
	}*/
	/*PotionEffect* getEffect(id) {
		return eff;
	}*/
	void registerCategory(ItemCategory& cic) {
  		categories.insert(std::__ndk1::pair<std::__ndk1::string&, ItemCategory&>(cic.id, cic));
	}
}
