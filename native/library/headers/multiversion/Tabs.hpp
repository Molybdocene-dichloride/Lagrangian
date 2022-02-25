#pragma once

#include <stl/map>
#include <stl/vector>

#include <mcpe/tileentity/ContainerModel.hpp>
#include <multiversion/ItemCategory.hpp>

class ItemCategory;

namespace CreativeTabs {
	extern std::__ndk1::vector<FilteredContainerModel*> models;

	extern std::__ndk1::map<int, ItemCategory*> forIt;

	extern int PER_PAGE;

	extern int cat_count;
	extern int cat_count_inCreative;

	extern int page_count;
	extern int current_page;

	extern std::__ndk1::vector<std::__ndk1::vector<std::__ndk1::pair<ItemInstance,unsigned int>,std::__ndk1::allocator<std::__ndk1::pair<ItemInstance,unsigned int>>>> cache;

	void setPage(int page);
	void nextPage();
	void prevPage();
	void populateItems();
	
	void invalidateModels(CraftingContainerManagerModel* ths);
}