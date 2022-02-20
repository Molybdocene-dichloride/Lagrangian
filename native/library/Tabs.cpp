#include <string>

#include <symbol.h>
#include <logger.h>

#include "vtable.h"

#include <mcpe/tileentity/ContainerModel.hpp>

#include <multiversion/Tabs.hpp>

std::__ndk1::vector<ContainerModel*> CreativeTabs::models = std::__ndk1::vector<ContainerModel*>();

std::__ndk1::map<int, ItemCategory> CreativeTabs::forIt = std::__ndk1::map<int, ItemCategory>();

int CreativeTabs::PER_PAGE = 4;

int CreativeTabs::cat_count = 7;
int CreativeTabs::cat_count_inCreative = 4;

int CreativeTabs::page_count = 1;
int CreativeTabs::current_page = 0;

void CreativeTabs::setPage(int page) {
	if(page < page_count) {
		Callbacks::invokeCallback("CreativePageChanged", page, current_page);
		JavaCallbacks::invokeCallback("CreativePageChanged", "", page, current_page);
		current_page = page;
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
	for(int a = 0; first_offset + a < cat_count_inCreative && a < PER_PAGE; a++) {
		for(int i = 0; i < forIt.at(first_offset + a).v_items.size(); i++) {
			VTABLE_CALL<void>(setItemsToTab, models.at(a), i, forIt.at(first_offset + a).v_items.at(i));
		}
	}
}