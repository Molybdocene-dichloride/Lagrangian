#pragma once

#include <stl/string>

#include <mcpe/block/Block.hpp>
#include <mcpe/math/BlockPos.hpp>
#include <mcpe/ContainerModel.hpp>

#include <mcpe/creative/CreativeItemRegistry.hpp>
#include <mcpe/creative/CreativeItemCategory.hpp>
#include <mcpe/creative/CreativeItemGroupCategory.hpp>

#include <innercore/global_context.h>

#include <multiversion/ItemCategory.hpp>
#include <multiversion/Tabs.hpp>

enum class ContainerID : char {
	UNK,
};

class Player {
	public:
	virtual const int getCreativeItemList();
};

class ServerPlayer : public Player {

};
class LocalPlayer : public Player {

};

class ContainerManagerModel {
	public:
	public:
	void* filler[4];
	ContainerID ci;
	void* filler2[6];
	std::__ndk1::unordered_map<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::shared_ptr<ContainerModel>,std::__ndk1::hash<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>,std::__ndk1::equal_to<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>,std::__ndk1::allocator<std::__ndk1::pair<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>const,std::__ndk1::shared_ptr<ContainerModel>>>> containers;
	public:
	virtual ContainerID getContainerId();
};

static_assert(offsetof(ContainerManagerModel, ci) == 20, "CreativeItemRegistry items position");
static_assert(offsetof(ContainerManagerModel, containers) == 48, "CreativeItemRegistry items position");

class CraftingContainerManagerModel : public ContainerManagerModel {
	public:
	CraftingContainerManagerModel(ContainerID param_1,Player& param_2,bool param_3,
          bool param_4,bool param_5,BlockPos const& param_6, std::__ndk1::string const& param_7);
};

//FilteredContainerModel::setItemInstance(int, ItemInstance const&) vtable

typedef unsigned char ContainerEnumName;
class ContainerEnumNameHasher {
	size_t operator()(ContainerEnumName c) const {
		return 11;
	}
};
extern std::__ndk1::unordered_map<ContainerEnumName, std::__ndk1::string,ContainerEnumNameHasher> ContainerCollectionNameMap;

namespace LagrangianRegistries {
	CreativeItemRegistry* _vanillaCreativeRegister;
	std::__ndk1::map<std::__ndk1::string, ItemCategory> categories = std::__ndk1::map<std::__ndk1::string, ItemCategory>();

	std::__ndk1::map<std::__ndk1::string, CreativeItemGroupCategory> registered = std::__ndk1::map<std::__ndk1::string, CreativeItemGroupCategory>();

	void postInit() {
		_vanillaCreativeRegister = CreativeItemRegistry::mCurrentRegistry;
		std::__ndk1::map<std::__ndk1::string, ItemCategory>::iterator at;
        	for(at = categories.begin(); at != categories.end(); ++at) {
			at->second.postInit();
			registered.insert(std::__ndk1::pair<std::__ndk1::string, CreativeItemGroupCategory>(at->first, *_vanillaCreativeRegister->newCreativeCategory(at->second.id, CreativeItemCategory(at->second.index))));
			Logger::debug("333gret", patch::to_string<int>(at->second.index).c_str());
			Logger::debug("333gret", at->second.id.c_str());
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
		
		Logger::debug("333gret", patch::to_string<int>(cic.index).c_str());
		Logger::debug("333gret", cic.id.c_str());

		TabSystem::cat_count++;
		if(cic.isCreative) {
			TabSystem::forIt.insert(std::__ndk1::pair<int, ItemCategory&>(cic.creative_index, cic));

			if(TabSystem::cat_count_inCreative / 4 >= TabSystem::page_count) TabSystem::page_count++;
			TabSystem::cat_count_inCreative++;
  		}
	}
}
