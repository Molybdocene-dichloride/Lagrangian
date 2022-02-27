#pragma once

#include <stl/string>

#include <mcpe/item/Item.hpp>

class ItemStackBase {
    public:
    char filler1[16-4]; // 4
	short damage; // 16
	unsigned char count; //18
	char filler2[84-19];
    virtual int getId() const;
    int getDamageValue() const;
    ItemStackBase(Item const&);
    ItemStackBase(Item const&, int);
    ItemStackBase(Item const&, int, int);
};
class ItemStack : public ItemStackBase {
    public:
    ItemStack(Item const&);
    ItemStack(Item const&, int);
    ItemStack(Item const&, int, int);
};
class ItemInstance : public ItemStackBase {
	public:
	ItemInstance(const Item& param_1,int param_2,int param_3);
	ItemInstance();
};

class ItemStackInfo {
    public:
    std::__ndk1::string nameId;
    int id;
    int data;
    int count;
    ItemStackInfo() {}
    ItemStackInfo(int id, int data, int count) {
        this->id = id;
        this->data = data;
        this->count = count;
    }
    ItemStackInfo(Item& item, int data, int count) {
        this->id = item.itemId;
        this->data = data;
        this->count = count;
    }
    ItemStackInfo(ItemStack& item) {
        this->id = item.getId();
        this->data = item.getDamageValue();
        this->count = item.count;
    }
    bool operator<(const ItemStackInfo& c2) const {
        this->id + this->data + this->count < c2.id + c2.data + c2.count;
    }
};