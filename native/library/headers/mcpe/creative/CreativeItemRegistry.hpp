#pragma once

#include <stl/string>
#include <stl/vector>
#include <stl/map>

#include <stl/unordered_map>

#include <mcpe/item/ItemStack.hpp>

#include <mcpe/creative/CreativeItemCategory.hpp>
#include <mcpe/creative/CreativeItemGroupCategory.hpp>
#include <mcpe/creative/CreativeGroupInfo.hpp>
#include <mcpe/creative/CreativeItemEntry.hpp>

class CreativeItemRegistry { /* PlaceHolder Structure */
    public:
    void* filler[2];
    std::__ndk1::vector<CreativeItemEntry>* items;
    void* filler1[14-12];
    std::__ndk1::vector<CreativeGroupInfo>* groups;
    void* filler2[32-20];
    //std::__ndk1::unordered_map<CreativeItemCategory,CreativeItemGroupCategory,std::__ndk1::hash<CreativeItemCategory>,std::__ndk1::equal_to<CreativeItemCategory>,std::__ndk1::allocator<std::__ndk1::pair<CreativeItemCategory_const,CreativeItemGroupCategory>>>* categories;
	
	public:
    //Methods
    CreativeItemRegistry();
    ~CreativeItemRegistry();
    CreativeItemGroupCategory* newCreativeCategory(std::__ndk1::basic_string<char, std::__ndk1::char_traits<char>, std::__ndk1::allocator<char> > const&, CreativeItemCategory);
    void reset();
    void setCurrentRegistry(std::__ndk1::unique_ptr<CreativeItemRegistry, std::__ndk1::default_delete<CreativeItemRegistry> >&&);
    void logRegistry(std::__ndk1::basic_string<char, std::__ndk1::char_traits<char>, std::__ndk1::allocator<char> > const&);
    //CreativeItemEntry newItemEntry(TypedServerNetId<CreativeItemNetIdTag, unsigned int, 0u> const&, ItemInstance const&);
    CreativeItemGroupCategory* getCreativeCategory(CreativeItemCategory);
    CreativeGroupInfo getCreativeGroup(unsigned int);
    //void _forEachCreativeItemInstance(std::__ndk1::function<bool (ItemInstance&)>);
    void resetGroups();
    CreativeItemEntry newItemEntry(ItemInstance const&);
    static CreativeItemRegistry* current();
    CreativeItemEntry getItemEntry(unsigned int);
    void takeCreativeList(std::__ndk1::vector<CreativeItemEntry, std::__ndk1::allocator<CreativeItemEntry> >&&);
    void forEachCreativeItemInstance(std::__ndk1::function<bool (ItemInstance&)>);
    void updateNetIdMap();
    CreativeGroupInfo newCreativeGroup(CreativeItemCategory, HashedString const&, ItemInstance const&);
    std::__ndk1::vector<CreativeItemEntry>* getCreativeItemEntries();
    CreativeItemRegistry getOrCreateCurrent();
    //CreativeItemEntry findCreativeItemEntry(TypedServerNetId<CreativeItemNetIdTag, unsigned int, 0u> const&);
    CreativeItemEntry findCreativeItemEntry(ItemInstance const&);
    void clear();
	
    public:
    //Objects
    static CreativeItemRegistry* mCurrentRegistry;
    //static CreativeItemRegistry* mCreativeListMutex;
};

static_assert(offsetof(CreativeItemRegistry, items) == 8, "CreativeItemRegistry items position");
static_assert(offsetof(CreativeItemRegistry, groups) == 20, "CreativeItemRegistry groups position");
//static_assert(offsetof(CreativeItemRegistry, categories) == 32, "CreativeItemRegistry categories position");

