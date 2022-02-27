#pragma once

#include <stl/string>

#include <mcpe/block/Block.hpp>
#include <mcpe/math/BlockPos.hpp>
#include <mcpe/tileentity/ContainerModel.hpp>

#include <mcpe/creative/CreativeItemRegistry.hpp>
#include <mcpe/creative/CreativeItemCategory.hpp>
#include <mcpe/creative/CreativeItemGroupCategory.hpp>

#include <innercore/global_context.h>

#include <multiversion/ItemCategory.hpp>
#include <multiversion/Tabs.hpp>

namespace LagrangianRegistries {
	extern CreativeItemRegistry* _vanillaCreativeRegister;
	extern std::__ndk1::map<std::__ndk1::string, ItemCategory*> categories;

	extern std::__ndk1::map<std::__ndk1::string, CreativeItemGroupCategory> registered;

	void postInit();
	/*void registryEffect(PotionEffect* effect) {
		mMobEffects.add(effect.nms());
	}*/
	/*PotionEffect* getEffect(id) {
		return eff;
	}*/
	void registerCategory(ItemCategory* cic);
}
