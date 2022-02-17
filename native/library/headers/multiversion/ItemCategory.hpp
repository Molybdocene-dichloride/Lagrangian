#pragma once

#include <stl/string>
#include <stl/vector>

#include <mcpe/block/Block.hpp>
#include <mcpe/math/BlockPos.hpp>
#include <mcpe/item/ItemStack.hpp>

class ContainerModel;

class ItemCategory {
	public:
	std::__ndk1::string id;
	int index;
	int creative_index;
	bool isCreative;
	ItemStackInfo icon;
	std::__ndk1::vector<ItemStackInfo> items;
	std::__ndk1::vector<ItemInstance> v_items;
	//list<ItemGroupInfo> items;
	public:
	ItemCategory(std::__ndk1::string id, bool isCreative = false);
	void addItem(ItemStackInfo item);
	void setIcon(ItemStackInfo icon);
};