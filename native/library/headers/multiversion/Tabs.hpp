#pragma once

#include <stl/map>
#include <stl/vector>

#include <multiversion/ItemCategory.hpp>

class ItemCategory;
class ContainerModel;

namespace TabSystem {
	extern std::__ndk1::map<int, ItemCategory> forIt;

	extern int PER_PAGE;

	extern int cat_count;
	extern int cat_count_inCreative;

	extern int page_count;
	extern int current_page;

	void setPage(int page);
	void nextPage();
	void prevPage();
	void populateItems(std::__ndk1::vector<ContainerModel*> cm);
}