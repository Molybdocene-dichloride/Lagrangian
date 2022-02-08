#pragma once

#include <stl/string>

struct ItemCategory {
	std::__ndk1::string id;
	int index;
	public:
	ItemCategory(int index, std::__ndk1::string id) {
		this->index = index;
		this->id = id;
	}
};