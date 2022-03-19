#pragma once

#include <stl/string>
#include <stl/vector>

#include <mcpe/block/Block.hpp>
#include <mcpe/math/BlockPos.hpp>
#include <mcpe/item/ItemStack.hpp>

#include <nativejs.h>

class ContainerModel;

class ItemCategory {
	public:
	int index;
	int creative_index;
	std::__ndk1::string id;
	std::__ndk1::string name;

	std::__ndk1::vector<ItemStackInfo> items;
	std::__ndk1::vector<ItemInstance> v_items;

	bool isCreative;
	ItemStackInfo icon;
	public:
	ItemCategory(NativeJS::ComplexArgs ca);
	ItemCategory(std::__ndk1::string id, std::__ndk1::string name, bool isCreative = false);
	
	void addItem(NativeJS::ComplexArgs ca);
	void addItem(ItemStackInfo item);
	void setIcon(ItemStackInfo icon);

	void postInit();
};