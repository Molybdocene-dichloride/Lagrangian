#include <multiversion/ItemCategory.hpp>
#include <multiversion/Tabs.hpp>

ItemCategory::ItemCategory(std::__ndk1::string id, bool isCreative) {
	this->creative_index = -1;
	this->index = TabSystem::cat_count;
	this->id = id;
	this->isCreative = isCreative;
	this->items = std::__ndk1::vector<ItemStackInfo>();
	this->v_items = std::__ndk1::vector<ItemInstance>();
		
	if(isCreative) {
		this->creative_index = TabSystem::cat_count_inCreative;
	}
}
void ItemCategory::addItem(ItemStackInfo item) {
		this->items.push_back(item);
}

void ItemCategory::setIcon(ItemStackInfo icon) {
	this->icon = icon;
}