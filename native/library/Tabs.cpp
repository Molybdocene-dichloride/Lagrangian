#include <string>

#include <symbol.h>
#include <logger.h>

#include "vtable.h"

#include "stl/utility"

#include <mcpe/tileentity/ContainerModel.hpp>

#include <multiversion/Tabs.hpp>
#include <innercore_callbacks.h>

#include <toString.hpp>

std::__ndk1::vector<FilteredContainerModel*> CreativeTabs::models = std::__ndk1::vector<FilteredContainerModel*>();

std::__ndk1::map<int, ItemCategory*> CreativeTabs::forIt = std::__ndk1::map<int, ItemCategory*>();

int CreativeTabs::PER_PAGE = 4;

int CreativeTabs::cat_count = 7;
int CreativeTabs::cat_count_inCreative = 4;

int CreativeTabs::page_count = 1;
int CreativeTabs::current_page = 0;

std::__ndk1::vector<std::__ndk1::vector<std::__ndk1::pair<ItemInstance,unsigned int>,std::__ndk1::allocator<std::__ndk1::pair<ItemInstance,unsigned int>>>> CreativeTabs::cache;

void CreativeTabs::setPage(int page) {
	if(page < page_count && page >= 0) {
		Logger::debug("noop", patch::to_string<int>(current_page).c_str());
		
		//jclass ccls = getDefaultCallbackClass();
		//JavaCallbacks::invokeCallback(ccls, "invokeAPICallback", "(Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/Throwable;", "CreativePageChanged", page, current_page);
		current_page = page;
		Logger::debug("jop", patch::to_string<int>(current_page).c_str());

		if(current_page == 0) return;

		int first_offset = current_page * PER_PAGE;

		VTABLE_FIND_OFFSET(refresh, _ZTV22FilteredContainerModel, _ZN22FilteredContainerModel16refreshContainerEb);
		for(int a = 0; a < PER_PAGE; a++) {
			if(first_offset + a < cat_count_inCreative) {
				Logger::debug("jop", patch::to_string<int>(forIt.at(first_offset + a)->v_items.size()).c_str());
				models.at(a)->items.resize(forIt.at(first_offset + a)->v_items.size() + 1);
			} else {
				models.at(a)->items.resize(0);
			}
			VTABLE_CALL<void>(refresh, models.at(a), false);
			//LagrangianRegistries::_vanillaCreativeRegister.categories(LagrangianRegistries::registries.at[]);
		}
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
	VTABLE_FIND_OFFSET(refresh, _ZTV22FilteredContainerModel, _ZN22FilteredContainerModel16refreshContainerEb);
	
	if(current_page == 0) return;
	
	int first_offset = current_page * PER_PAGE;

	Logger::debug("niobiv0", patch::to_string<int>(current_page).c_str());
	Logger::debug("niobiv1", patch::to_string<int>(PER_PAGE).c_str());

	Logger::debug("niobiv", patch::to_string<int>(first_offset).c_str());

	for(int a = 0; first_offset + a < cat_count_inCreative && a < PER_PAGE; a++) {
		Logger::debug("UBLASD", patch::to_string<int>(first_offset + a).c_str());
		Logger::debug("UBLASD", patch::to_string<int>(a).c_str());

		for(int i = 0; i < forIt.at(first_offset + a)->v_items.size(); i++) {
			Logger::debug("aplortery", patch::to_string<int>(i).c_str());
			
			/*std::__ndk1::pair<ItemInstance, unsigned int> pr(forIt.at(first_offset + a)->v_items.at(i), i);
			Logger::debug("aplorte", patch::to_string<int>(i).c_str());
			
			std::__ndk1::vector<std::__ndk1::pair<ItemInstance,unsigned int>,std::__ndk1::allocator<std::__ndk1::pair<ItemInstance,unsigned int>>>::iterator it = models.at(a)->items.begin() + i;

			models.at(a)->items.insert(it, pr);*/
			VTABLE_CALL<void>(setItemsToTab, models.at(a), i, forIt.at(first_offset + a)->v_items.at(i));
		}
		VTABLE_CALL<void>(refresh, models.at(a), false);
	}
	Logger::debug("aplorte", "derrtoip");
}

void CreativeTabs::invalidateModels(CraftingContainerManagerModel* ths) {
	std::__ndk1::unordered_map<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::shared_ptr<ContainerModel>,std::__ndk1::hash<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>,std::__ndk1::equal_to<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>,std::__ndk1::allocator<std::__ndk1::pair<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>const,std::__ndk1::shared_ptr<ContainerModel>>>>::iterator at;
	for(at = ths->containers.begin(); at != ths->containers.end(); ++at) {
		Logger::debug("Lg0", at->first.c_str());
		Logger::debug("Lg1", patch::to_string<uintptr_t>(reinterpret_cast<uintptr_t>(at->second.get())).c_str());
	}

	CreativeTabs::models.clear();
	
	FilteredContainerModel* cm0 = (FilteredContainerModel*) ths->containers.at("recipe_construction").get();
	FilteredContainerModel* cm1 = (FilteredContainerModel*) ths->containers.at("recipe_equipment").get();
	FilteredContainerModel* cm2 = (FilteredContainerModel*) ths->containers.at("recipe_items").get();
	FilteredContainerModel* cm3 = (FilteredContainerModel*) ths->containers.at("recipe_nature").get();
	CreativeTabs::models.push_back(cm0);
	CreativeTabs::models.push_back(cm1);
	CreativeTabs::models.push_back(cm2);
	CreativeTabs::models.push_back(cm3);

	CreativeTabs::cache.clear();

	//std::__ndk1::vector<std::__ndk1::pair<ItemInstance,unsigned int>,std::__ndk1::allocator<std::__ndk1::pair<ItemInstance,unsigned int>>> items0 = cm0->items;
	//std::__ndk1::vector<std::__ndk1::pair<ItemInstance,unsigned int>,std::__ndk1::allocator<std::__ndk1::pair<ItemInstance,unsigned int>>> items1 = cm1->items;
	//std::__ndk1::vector<std::__ndk1::pair<ItemInstance,unsigned int>,std::__ndk1::allocator<std::__ndk1::pair<ItemInstance,unsigned int>>> items2 = cm2->items;
	//std::__ndk1::vector<std::__ndk1::pair<ItemInstance,unsigned int>,std::__ndk1::allocator<std::__ndk1::pair<ItemInstance,unsigned int>>> items3 = cm3->items;
	Logger::debug("Lg0", "fretka");
	std::__ndk1::vector<std::__ndk1::pair<ItemInstance,unsigned int>,std::__ndk1::allocator<std::__ndk1::pair<ItemInstance,unsigned int>>>::iterator eet;
	for(eet = cm0->items.begin(); eet != cm0->items.end(); ++eet) {
		//Logger::debug("Lg0", eet->first.c_str());
		Logger::debug("Lg1", patch::to_string<uintptr_t>(reinterpret_cast<uintptr_t>(&(*eet))).c_str());
		unsigned int ii = std::__ndk1::get<1>(*eet);
		Logger::debug("Lg10", patch::to_string<unsigned int>(ii).c_str());

		ItemInstance itemi = std::__ndk1::get<0>(*eet);
		Logger::debug("Lg101", patch::to_string<uintptr_t>(reinterpret_cast<uintptr_t>(&itemi)).c_str());
	}
	//cache.push_back(items0);
	//cache.push_back(items1);
	//cache.push_back(items2);
	//cache.push_back(items3);
}