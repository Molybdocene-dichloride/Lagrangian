#include <string>

#include <symbol.h>
#include <logger.h>

#include "vtable.h"

#include <mcpe/tileentity/ContainerModel.hpp>

#include <multiversion/Tabs.hpp>
#include <innercore_callbacks.h>

#include <toString.hpp>

std::__ndk1::vector<ContainerModel*> CreativeTabs::models = std::__ndk1::vector<ContainerModel*>();

std::__ndk1::map<int, ItemCategory> CreativeTabs::forIt = std::__ndk1::map<int, ItemCategory>();

int CreativeTabs::PER_PAGE = 4;

int CreativeTabs::cat_count = 7;
int CreativeTabs::cat_count_inCreative = 4;

int CreativeTabs::page_count = 1;
int CreativeTabs::current_page = 0;
//
void CreativeTabs::setPage(int page) {
	if(page < page_count && page > 0) {
		Logger::debug("jokier", patch::to_string<int>(current_page).c_str());
		Callbacks::invokeCallback("CreativePageChanged", page, current_page);
		Logger::debug("joc", patch::to_string<int>(current_page).c_str());
		//JavaCallbacks::invokeCallback("CreativePageChanged", "", page, current_page);
		current_page = page;
		Logger::debug("jokier_uu", patch::to_string<int>(current_page).c_str());
	}
}
void CreativeTabs::nextPage() {
	setPage(current_page + 1);
}
void CreativeTabs::prevPage() {
	setPage(current_page - 1);
}
void CreativeTabs::populateItems() {
	VTABLE_FIND_OFFSET(setItemsToTab, _ZTV22FilteredContainerModel, _ZN22FilteredContainerModel15setItemInstanceEiRK12ItemInstance);
	if(current_page == 0) return;
	int first_offset = current_page * PER_PAGE;
	Logger::debug("derr", patch::to_string<int>(first_offset).c_str());
	for(int a = 0; first_offset + a < cat_count_inCreative && a < PER_PAGE; a++) {
		Logger::debug("derr", patch::to_string<int>(a).c_str());
		for(int i = 0; i < forIt.at(first_offset + a).v_items.size(); i++) {
			Logger::debug("aplortery", patch::to_string<int>(i).c_str());
			VTABLE_CALL<void>(setItemsToTab, models.at(a), i, forIt.at(first_offset + a).v_items.at(i));
		}
	}
}

void CreativeTabs::deo(CraftingContainerManagerModel* ths) {
	std::__ndk1::unordered_map<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::shared_ptr<ContainerModel>,std::__ndk1::hash<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>,std::__ndk1::equal_to<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>,std::__ndk1::allocator<std::__ndk1::pair<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>const,std::__ndk1::shared_ptr<ContainerModel>>>>::iterator at;
	for(at = ths->containers.begin(); at != ths->containers.end(); ++at) {
		Logger::debug("Lg0", at->first.c_str());
		Logger::debug("Lg1", patch::to_string<uintptr_t>(reinterpret_cast<uintptr_t>(at->second.get())).c_str());
	}
	ContainerModel* cm0 = ths->containers.at("recipe_nature").get();
	ContainerModel* cm1 = ths->containers.at("recipe_construction").get();
	ContainerModel* cm2 = ths->containers.at("recipe_items").get();
	ContainerModel* cm3 = ths->containers.at("recipe_equipment").get();
	CreativeTabs::models.push_back(cm0);
	CreativeTabs::models.push_back(cm1);
	CreativeTabs::models.push_back(cm2);
	CreativeTabs::models.push_back(cm3);
}