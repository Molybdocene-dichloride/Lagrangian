#pragma once

#include <stl/string>

#include <stl/vector>

#include <stl/unordered_map>

#include <mcpe/math/BlockPos.hpp>

#include <mcpe/item/ItemStack.hpp>

#include <innercore/item_registry.h>

enum class ContainerID : char {
	UNK,
};

enum class ContainerCategory : char {
	UNK,
};
enum class ContainerEnumName : char {
	UNK,
};

class ContainerEnumNameHasher {
	size_t operator()(ContainerEnumName c) const {
		return 11;
	}
};

class Player {
	public:
	virtual const int getCreativeItemList();
};

class ServerPlayer : public Player {

};
class LocalPlayer : public Player {

};

class ContainerModel {
	ContainerCategory getContainerCategory();
	ContainerEnumName getContainerEnumName();
};
class ExpandoContainerModel : public ContainerModel {
	public:
	void* filler[24];
	std::__ndk1::vector<std::__ndk1::pair<ItemInstance,unsigned int>,std::__ndk1::allocator<std::__ndk1::pair<ItemInstance,unsigned int>>> items;
};

static_assert(offsetof(ExpandoContainerModel, items) == 96, "CreativeItemRegistry items position");

class FilteredContainerModel : public ExpandoContainerModel {
	FilteredContainerModel(ContainerEnumName, int, ContainerCategory, bool, bool, std::__ndk1::function<FilterResult (ItemInstance const&)>);
};

class ContainerManagerModel {
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