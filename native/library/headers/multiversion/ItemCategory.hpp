#pragma once

#include <stl/string>

struct ItemCategory {
	std::__ndk1::string id;
	int index;
	bool isCreative;
	public:
	ItemCategory(int index, std::__ndk1::string id) {
		this->index = index;
		this->id = id;
		this->isCreative = false;
	}
	ItemCategory(int index, std::__ndk1::string id, bool isCreative) {
		ItemCategory(index, id);
		this->isCreative = isCreative;
	}
};