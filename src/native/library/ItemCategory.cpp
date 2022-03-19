#include <nativejs.h>

#include <innercore/item_registry.h>

#include <multiversion/ItemCategory.hpp>
#include <multiversion/Tabs.hpp>

#include <toString.hpp>

ItemCategory::ItemCategory(std::__ndk1::string id, std::__ndk1::string name, bool isCreative) {
	this->creative_index = -1;
	this->index = CreativeTabs::cat_count;
	this->id = id;
	this->name = name;
	this->isCreative = isCreative;
	this->items = std::__ndk1::vector<ItemStackInfo>();
	this->v_items = std::__ndk1::vector<ItemInstance>();
		
	if(isCreative) {
		this->creative_index = CreativeTabs::cat_count_inCreative;
	}

	Logger::debug("333gret", patch::to_string<int>(this->index).c_str());
	Logger::debug("333gret", this->id.c_str());
}

ItemCategory::ItemCategory(NativeJS::ComplexArgs ca) : ItemCategory(ca.get("id").asString(), ca.get("name").asString(), ca.get("isCreative").asInt()) {}

void ItemCategory::addItem(NativeJS::ComplexArgs ca) {
	Logger::debug("loom", patch::to_string<int>(ca.get(std::string("item") + "_id").asInt()).c_str());
	Logger::debug("loom", patch::to_string<int>(ca.get(std::string("item") + "_data").asInt()).c_str());
	Logger::debug("loom", patch::to_string<int>(ca.get(std::string("item") + "_count").asInt()).c_str());
	
	ItemStackInfo isi = ItemStackInfo(ca.get(std::string("item") + "_id").asInt(), ca.get(std::string("item") + "_data").asInt(), ca.get(std::string("item") + "_count").asInt());
	ItemStackInfo& ise = isi;
	
	this->items.push_back(ise);
}

void ItemCategory::addItem(ItemStackInfo item) {
	this->items.push_back(item);
}

void ItemCategory::setIcon(ItemStackInfo icon) {
	this->icon = icon;
}

void ItemCategory::postInit() {
	for(int i = 0; i < this->items.size(); i++) {
		Logger::debug("Lgyt", patch::to_string<int>(this->items.at(i).id).c_str());
		
		Item* it = ItemRegistry::getItemById(this->items.at(i).id);
		//Item e = *it;
		ItemInstance ii = ItemInstance(*it, this->items.at(i).count, this->items.at(i).data);
		ItemInstance& ie = ii;
	
		Logger::debug("Lgyp", ie.getName().c_str());

		this->v_items.push_back(ie);
	}
}