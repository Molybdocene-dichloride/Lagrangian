#include <string>

#include <symbol.h>
#include <logger.h>

#include "vtable.h"

#include <multiversion/Tabs.hpp>

int TabSystem::PER_PAGE = 4;

int TabSystem::cat_count = 7;
int TabSystem::cat_count_inCreative = 4;

int TabSystem::page_count = 0;
int TabSystem::current_page = 0;

void TabSystem::setPage(int page) {
	current_page = page;
}
void TabSystem::nextPage() {
	setPage(current_page + 1);
}
void TabSystem::prevPage() {
	setPage(current_page - 1);
}
void TabSystem::populateItems(std::__ndk1::vector<ContainerModel*> cm) {
	/*VTABLE_FIND_OFFSET(setItemsToTab, _ZTV22FilteredContainerModel, _ZN22FilteredContainerModel15setItemInstanceEiRK12ItemInstance);
	if(current_page == 0) return;
	int first_offset = current_page * PER_PAGE;
	for(int a = 0; first_offset + a < cat_count_inCreative && a < PER_PAGE; a++) {
		for(int i : forIt.at(first_offset + a).v_items) {
			VTABLE_CALL<void>(setItemsToTab, cm.at(a), i, forIt.at(first_offset + a).v_items.at(i));
		}
	}*/
}