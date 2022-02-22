#pragma once

#include <stl/string>
#include <stl/unordered_map>

#include <mcpe/math/BlockPos.hpp>

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

class Container {};

class ContainerModel {};
class ExpandoContainerModel : public ContainerModel {};
class FilteredContainerModel : public ExpandoContainerModel {};

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