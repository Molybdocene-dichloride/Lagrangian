#pragma once

#include <stl/string>

#include <mcpe/item/ItemStack.hpp>

struct ItemCategory {
	std::__ndk1::string id;
	int index;
	bool isCreative;
	ItemStackInfo icon;
	std::__ndk1::vector<ItemStackInfo> items;
	//list<ItemGroupInfo> items;
	public:
	ItemCategory(int index, std::__ndk1::string id) {
		this->index = index;
		this->id = id;
		this->isCreative = false;
		this->items = std::__ndk1::vector<ItemStackInfo>();
	}
	ItemCategory(int index, std::__ndk1::string id, bool isCreative) {
		ItemCategory(index, id);
		this->isCreative = isCreative;
	}
	void addItem(ItemStackInfo item) {
		this->items.push_back(item);
	}

	void setIcon(ItemStackInfo icon) {
		this->icon = icon;
	}
};

namespace TabSystem {
	const int per_page = 4;
	int page_count = 0;
	int current_page = 0;

	bool invalidated = true;

	void nextPage() {
		setPage(current_page + 1);
	}
	void prevPage() {
		setPage(current_page - 1);
	}
	void setPage(int page) {
		current_page = page;
	}
}