#pragma once

#include "mcpe/item/Item.hpp"
#include <stl/map>
#include <stl/vector>

#include <mcpe/tileentity/ContainerModel.hpp>
#include <multiversion/ItemCategory.hpp>

class ItemCategory;

class CreativeTabs : public ItemCategory {
	public:
	static std::__ndk1::vector<FilteredContainerModel*> models;

	static std::__ndk1::map<int, ItemCategory*> forIt;

	static int PER_PAGE;

	static int cat_count;
	static int cat_count_inCreative;

	static int page_count;
	static int current_page;

	static std::__ndk1::vector<std::__ndk1::vector<std::__ndk1::pair<ItemInstance,unsigned int>,std::__ndk1::allocator<std::__ndk1::pair<ItemInstance,unsigned int>>>> cache;

	static void setPage(int page);
	static void nextPage();
	static void prevPage();
	static void populateItems();
	
	static void invalidateModels(CraftingContainerManagerModel* ths);
	private:
	ItemStackInfo icon;
	int creative_index;
	public:
	//CreativeTabs(NativeJS::ComplexArgs ca);
	//CreativeTabs(std::__ndk1::string id, bool isCreative = false);

	//void setIcon(ItemStackInfo icon);
};