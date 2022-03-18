#include <cstdint>
#include <string>

#include <symbol.h>
#include <logger.h>

#include "vtable.h"

#include "stl/utility"

#include <mcpe/tileentity/ContainerModel.hpp>

#include <multiversion/Tabs.hpp>
#include <innercore_callbacks.h>

#include <toString.hpp>

#include "stdCrutch.hpp"

#include <bits/stdc++.h>

newstd::vector<FilteredContainerModel*> CreativeTabs::models = newstd::vector<FilteredContainerModel*>();

newstd::map<int, ItemCategory*> CreativeTabs::forIt = newstd::map<int, ItemCategory*>();

int CreativeTabs::PER_PAGE = 4;

int CreativeTabs::cat_count = 7;
int CreativeTabs::cat_count_inCreative = 4;

int CreativeTabs::page_count = 1;
int CreativeTabs::current_page = 0;

newstd::vector<newstd::shared_ptr<ContainerModel>> CreativeTabs::containers = newstd::vector<newstd::shared_ptr<ContainerModel>>();

newstd::vector<newstd::vector<newstd::pair<ItemInstance,unsigned int>,std::__ndk1::allocator<std::__ndk1::pair<ItemInstance,unsigned int>>>> CreativeTabs::cache;

void CreativeTabs::setPage(int page) {
	if(page < page_count && page >= 0) {
		Logger::debug("noop", patch::to_string<int>(current_page).c_str());
		
		//jclass ccls = getDefaultCallbackClass();
		
		//JavaCallbacks::invokeCallback("invokeAPICallback", "(Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/Throwable;", "CreativePageChanged", page, current_page);
		
		//jmethodID mid_getName = env->GetMethodID(JavaCallbacks::getDefaultCallbackClass(), "getName", "()Ljava/lang/String;");
		//jstring name = env->CallObjectMethod(JavaCallbacks::getDefaultCallbackClass(), mid_getName);
		//const char* str = env->GetStringUTFChars(name, NULL);
		//Logger::debug("joomp", str);
		
		current_page = page;
		Logger::debug("jop", patch::to_string<int>(current_page).c_str());

		if(current_page == 0) return;

		int first_offset = current_page * PER_PAGE;

		VTABLE_FIND_OFFSET(refresh, _ZTV22FilteredContainerModel, _ZN22FilteredContainerModel16refreshContainerEb);
		for(int a = 0; a < PER_PAGE; a++) {
			Logger::debug("Lg0", patch::to_string<size_t>(models.at(a)->items.size()).c_str());
			if(first_offset + a < cat_count_inCreative) {
				Logger::debug("jop", patch::to_string<int>(forIt.at(first_offset + a)->v_items.size()).c_str());
				//models.at(a)->items.resize(forIt.at(first_offset + a)->v_items.size() + 1);
			
			} else {
				//models.at(a)->items.resize(0);

			}
			//VTABLE_CALL<void>(refresh, models.at(a), false);
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

void CreativeTabs::populateItems(CraftingContainerManagerModel* ths) {	
	VTABLE_FIND_OFFSET(setItemsToTab, _ZTV22FilteredContainerModel, _ZN22FilteredContainerModel15setItemInstanceEiRK12ItemInstance);
	VTABLE_FIND_OFFSET(refresh, _ZTV22FilteredContainerModel, _ZN22FilteredContainerModel16refreshContainerEb);
	
	if(current_page == 0) return;
	
	int first_offset = current_page * PER_PAGE;

	for(int a = 0; first_offset + a < cat_count_inCreative && a < PER_PAGE; a++) {

		for(int i = 0; i < forIt.at(first_offset + a)->v_items.size(); i++) {
			Logger::debug("aplortery", patch::to_string<int>(i).c_str());

			Logger::debug("apiuiu", patch::to_string<uintptr_t>(reinterpret_cast<uintptr_t>(&forIt.at(first_offset + a)->v_items.at(i))).c_str());
			
			VTABLE_CALL<void>(setItemsToTab, models.at(a), i, &forIt.at(first_offset + a)->v_items.at(i));

			Logger::debug("aplortery", "dd");
		}
		Logger::debug("sssss", "dddd");
		//VTABLE_CALL<void>(refresh, models.at(a), false);
		Logger::debug("qqqqwww", "wd");
	}
	Logger::debug("aplorte", "derrtoip");
}

void CreativeTabs::invalidateModels(CraftingContainerManagerModel* ths) {
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

	/*Logger::debug("size[]", patch::to_string<size_t>(cm0->items.size()).c_str());
	Logger::debug("size[]", patch::to_string<size_t>(cm1->items.size()).c_str());
	Logger::debug("size[]", patch::to_string<size_t>(cm2->items.size()).c_str());
	Logger::debug("size[]", patch::to_string<size_t>(cm3->items.size()).c_str());
	std::__ndk1::vector<std::__ndk1::pair<ItemInstance,unsigned int>,std::__ndk1::allocator<std::__ndk1::pair<ItemInstance,unsigned int>>>::iterator eet;
	for(eet = cm0->items.begin(); eet != cm0->items.end(); ++eet) {
		//Logger::debug("Lg0", eet->first.c_str());
		//Logger::debug("Lg1", patch::to_string<uintptr_t>(reinterpret_cast<uintptr_t>(&(*eet))).c_str());
		
		//unsigned int ii = std::__ndk1::get<1>(*eet);
		Logger::debug("Lg10", patch::to_string<unsigned int>((*eet).second).c_str());

		//ItemInstance itemi = std::__ndk1::get<0>(*eet);
		Logger::debug("Pointer", patch::to_string<uintptr_t>(reinterpret_cast<uintptr_t>(&(*eet).first)).c_str());
		
		//VTABLE_FIND_OFFSET(getId, _ZTV22FilteredContainerModel, _ZN22FilteredContainerModel16refreshContainerEb);
		//Logger::debug("Lg101", (*eet).first.getName().c_str());
	}
	Logger::debug("Lg101", "conool");

	//newstd::vector<newstd::pair<ItemInstance,unsigned int>,std::__ndk1::allocator<std::__ndk1::pair<ItemInstance,unsigned int>>> items0 = cm0->items;
	//newstd::vector<std::__ndk1::pair<ItemInstance,unsigned int>,std::__ndk1::allocator<std::__ndk1::pair<ItemInstance,unsigned int>>> items1 = cm1->items;
	//std::__ndk1::vector<std::__ndk1::pair<ItemInstance,unsigned int>,std::__ndk1::allocator<std::__ndk1::pair<ItemInstance,unsigned int>>> items2 = cm2->items;
	//std::__ndk1::vector<std::__ndk1::pair<ItemInstance,unsigned int>,std::__ndk1::allocator<std::__ndk1::pair<ItemInstance,unsigned int>>> items3 = cm3->items;

	//cache.push_back(items0);
	//cache.push_back(items1);
	//cache.push_back(items2);
	//cache.push_back(items3);
	*/
	
	//newstd::function<FilterResult(ItemInstance const&)> filtering_function([](ItemInstance const& i) { return (FilterResult) 0; }); 
	
	FilteredContainerModel* nfcm = new FilteredContainerModel((ContainerEnumName)15, 1, (ContainerCategory)3, false, false, nullptr);

	Logger::debug("isFlter_custom", patch::to_string<bool>(nfcm->isFiltering()).c_str());
	Logger::debug("cc_custom", patch::to_string<int>((int)nfcm->getContainerCategory()).c_str());
	Logger::debug("cen_custom", patch::to_string<int>((int)nfcm->getContainerEnumName()).c_str());
	
	
	newstd::shared_ptr<ContainerModel> spcm = newstd::shared_ptr<ContainerModel>(nfcm);
	
	CreativeTabs::containers.clear();
	CreativeTabs::containers.push_back(spcm);
	
	ths->containers.insert(newstd::pair<newstd::string, newstd::shared_ptr<ContainerModel>>("recipe_construction", spcm));
	
	//get
	/*ContainerModel* w = ths->containers.at("inventory_items").get();
	ContainerModel* v = ths->containers.at("hotbar_items").get();
	ContainerModel* x = ths->containers.at("creative_output_items").get();
	ContainerModel* y = ths->containers.at("crafting_output_items").get();
	ContainerModel* z = ths->containers.at("cursor_items").get();
	ContainerModel* t = ths->containers.at("offhand_items").get();

	ContainerModel* a = ths->containers.at("recipe_items").get();
	ContainerModel* b = ths->containers.at("armor_items").get();

	ContainerModel* u = ths->containers.at("crafting_input_items").get();
	ContainerModel* p = ths->containers.at("combined_hotbar_and_inventory_items").get();
	
	ContainerModel* r = ths->containers.at("recipe_search").get();
	
	ContainerCategory wc = w->getContainerCategory();
	ContainerEnumName wen = w->getContainerEnumName();

	ContainerCategory vc1 = v->getContainerCategory();
	ContainerEnumName ven1= v->getContainerEnumName();

	ContainerCategory xc2 = x->getContainerCategory();
	ContainerEnumName xen2 = x->getContainerEnumName();

	ContainerCategory yc3 = y->getContainerCategory();
	ContainerEnumName yen3 = y->getContainerEnumName();

	ContainerCategory zc3 = z->getContainerCategory();
	ContainerEnumName zen3 = z->getContainerEnumName();

	ContainerCategory tc3 = t->getContainerCategory();
	ContainerEnumName ten3 = t->getContainerEnumName();

	ContainerCategory ac3 = a->getContainerCategory();
	ContainerEnumName aen3 = a->getContainerEnumName();

	ContainerCategory bc3 = b->getContainerCategory();
	ContainerEnumName ben3 = b->getContainerEnumName();

	ContainerCategory uc3 = u->getContainerCategory();
	ContainerEnumName uen3 = u->getContainerEnumName();

	ContainerCategory pc3 = p->getContainerCategory();
	ContainerEnumName pen3 = p->getContainerEnumName();

	ContainerCategory rc3 = r->getContainerCategory();
	ContainerEnumName ren3 = r->getContainerEnumName();

	Logger::debug("ContainerCategory", patch::to_string<int>(static_cast<char>(vc1)).c_str());
	Logger::debug("ContainerEnumName", patch::to_string<int>(static_cast<char>(ven1)).c_str());

	Logger::debug("ContainerCategory", patch::to_string<int>(static_cast<char>(wc)).c_str());
	Logger::debug("ContainerEnumName", patch::to_string<int>(static_cast<char>(wen)).c_str());

	Logger::debug("ContainerCategory", patch::to_string<int>(static_cast<char>(xc2)).c_str());
	Logger::debug("ContainerEnumName", patch::to_string<int>(static_cast<char>(xen2)).c_str());

	Logger::debug("ContainerCategory", patch::to_string<int>(static_cast<char>(yc3)).c_str());
	Logger::debug("ContainerEnumName", patch::to_string<int>(static_cast<char>(yen3)).c_str());

	Logger::debug("ContainerCategory", patch::to_string<int>(static_cast<char>(zc3)).c_str());
	Logger::debug("ContainerEnumName", patch::to_string<int>(static_cast<char>(zen3)).c_str());

	Logger::debug("ContainerCategory", patch::to_string<int>(static_cast<char>(tc3)).c_str());
	Logger::debug("ContainerEnumName", patch::to_string<int>(static_cast<char>(ten3)).c_str());
	
	//Logger::debug("ContainerCategory", patch::to_string<int>(static_cast<char>(ac3)).c_str());
	//Logger::debug("ContainerEnumName", patch::to_string<int>(static_cast<char>(aen3)).c_str());
	//Logger::debug("ContainerCategory", patch::to_string<int>(static_cast<char>(bc3)).c_str());
	//Logger::debug("ContainerEnumName", patch::to_string<int>(static_cast<char>(ben3)).c_str());
	//Logger::debug("ContainerCategory", patch::to_string<int>(static_cast<char>(uc3)).c_str());
	//Logger::debug("ContainerEnumName", patch::to_string<int>(static_cast<char>(uen3)).c_str());
	//Logger::debug("ContainerCategory", patch::to_string<int>(static_cast<char>(pc3)).c_str());
	//Logger::debug("ContainerEnumName", patch::to_string<int>(static_cast<char>(pen3)).c_str());
	//Logger::debug("ContainerCategory", patch::to_string<int>(static_cast<char>(rc3)).c_str());
	//Logger::debug("ContainerEnumName", patch::to_string<int>(static_cast<char>(ren3)).c_str());*/

}