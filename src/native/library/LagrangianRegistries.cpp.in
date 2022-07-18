#include <LagrangianRegistries.hpp>
#include <toString.hpp>

CreativeItemRegistry* LagrangianRegistries::_vanillaCreativeRegister;

std::__ndk1::map<std::__ndk1::string, ItemCategory*> LagrangianRegistries::categories = std::__ndk1::map<std::__ndk1::string, ItemCategory*>();

std::__ndk1::map<std::__ndk1::string, CreativeItemGroupCategory> LagrangianRegistries::registered = std::__ndk1::map<std::__ndk1::string, CreativeItemGroupCategory>();

void LagrangianRegistries::postInit() {
	_vanillaCreativeRegister = CreativeItemRegistry::mCurrentRegistry;
	std::__ndk1::map<std::__ndk1::string, ItemCategory*>::iterator at;
        for(at = categories.begin(); at != categories.end(); ++at) {
		at->second->postInit();
		registered.insert(std::__ndk1::pair<std::__ndk1::string, CreativeItemGroupCategory>(at->first, *_vanillaCreativeRegister->newCreativeCategory(at->second->id, CreativeItemCategory(at->second->index))));
		Logger::debug("333gret", patch::to_string<int>(at->second->index).c_str());
		Logger::debug("333gret", at->second->id.c_str());
	}
}
void LagrangianRegistries::registerCategory(ItemCategory* cic) {
	categories.insert(std::__ndk1::pair<std::__ndk1::string&, ItemCategory*>(cic->id, cic));
		
	Logger::debug("333gret", patch::to_string<int>(cic->index).c_str());
	Logger::debug("333gret", cic->id.c_str());

	CreativeTabs::cat_count++;
	if(cic->isCreative) {
		CreativeTabs::forIt.insert(std::__ndk1::pair<int, ItemCategory*>(cic->creative_index, cic));
		if(CreativeTabs::cat_count_inCreative / 4 >= CreativeTabs::page_count) CreativeTabs::page_count++;
		CreativeTabs::cat_count_inCreative++;
  	}
}