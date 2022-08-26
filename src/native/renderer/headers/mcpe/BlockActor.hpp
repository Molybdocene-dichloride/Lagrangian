#pragma once

struct Vec3 {
    float x;
    float y;
    float z;
};

struct AABB {
    Vec3 start;
    Vec3 end;
    bool empty;
};

struct BlockPos {
    int x;
    int y;
    int z;
};

enum BlockActorType {
    Furnace          = 0x01,
    Chest            = 0x02,
    NetherReactor    = 0x03,
    Sign             = 0x04,
    MobSpawner       = 0x05,
    Skull            = 0x06,
    FlowerPot        = 0x07,
    BrewingStand     = 0x08,
    EnchantingTable  = 0x09,
    DaylightDetector = 0x0A,
    Music            = 0x0B,
    Comparator       = 0x0C,
    Dispenser        = 0x0D,
    Dropper          = 0x0E,
    Hopper           = 0x0F,
    Cauldron         = 0x10,
    ItemFrame        = 0x11,
    Piston           = 0x12,
    Moving           = 0x13,
    Chalkboard       = 0x14,
    Beacon           = 0x15,
    EndPortal        = 0x16,
    EnderChest       = 0x17,
    EndGateway       = 0x18,
    ShulkerBox       = 0x19,
    CommandBlock     = 0x1A,
    Bed              = 0x1B,
    Banner           = 0x1C,

    Structure      = 0x20,
    Jukebox        = 0x21,
    ChemistryTable = 0x22,
    Conduit        = 0x23,
    Jigsaw         = 0x24,
    Lectern        = 0x25,
    BlastFurnace   = 0x26,
    Smoker         = 0x27,
    Bell           = 0x28,
    Campfire       = 0x29,
    Barrel         = 0x2A,
    Beehive        = 0x2B,
};

typedef unsigned char undefined;
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined3;
typedef unsigned int undefined4;
typedef unsigned long long undefined5;
typedef unsigned long long undefined6;
typedef unsigned long long undefined7;
typedef unsigned long long undefined8;

typedef UIProfanityContext OldspeakContext; //Mojang distopy fuck you!

class BlockActor {//from Ghidra
    public:
    //undefined * * vtable; auto
    int counter;
    Block * block;
    undefined field3_0xc;
    undefined field4_0xd;
    undefined field5_0xe;
    undefined field6_0xf;
    undefined field7_0x10;
    undefined field8_0x11;
    undefined field9_0x12;
    undefined field10_0x13;
    undefined field11_0x14;
    undefined field12_0x15;
    undefined field13_0x16;
    undefined field14_0x17;
    undefined field15_0x18;
    undefined field16_0x19;
    undefined field17_0x1a;
    undefined field18_0x1b;
    undefined field19_0x1c;
    undefined field20_0x1d;
    undefined field21_0x1e;
    undefined field22_0x1f;
    BlockPos position;
    AABB aabb;
    undefined field25_0x45;
    undefined field26_0x46;
    undefined field27_0x47;
    BlockActorType type;
    BlockActorRendererId renderer_id;
    undefined field30_0x4d;
    undefined field31_0x4e;
    undefined field32_0x4f;
    newstd::string custom_name;
    undefined field34_0x51;
    undefined field35_0x52;
    undefined field36_0x53;
    undefined field37_0x54;
    undefined field38_0x55;
    undefined field39_0x56;
    undefined field40_0x57;
    undefined field41_0x58;
    undefined field42_0x59;
    undefined field43_0x5a;
    undefined field44_0x5b;
    undefined1 field_strange;
    undefined field46_0x5d;
    undefined field47_0x5e;
    undefined field48_0x5f;
    undefined field49_0x60;
    undefined field50_0x61;
    undefined field51_0x62;
    undefined field52_0x63;
    undefined field53_0x64;
    undefined field54_0x65;
    undefined field55_0x66;
    undefined field56_0x67;
    uint repair_cost;
    bool client_side_only;
    bool movable;
    bool custom_name_saved;
    bool can_render_name;
    undefined field62_0x70;
    undefined field63_0x71;
    undefined field64_0x72;
    undefined field65_0x73;
    undefined field66_0x74;
    undefined field67_0x75;
    undefined field68_0x76;
    undefined field69_0x77;
    undefined1 entity_interlock;
    undefined field71_0x79;
    undefined field72_0x7a;
    undefined field73_0x7b;
    undefined field74_0x7c;
    undefined field75_0x7d;
    undefined field76_0x7e;
    undefined field77_0x7f;
    undefined field78_0x80;
    undefined field79_0x81;
    undefined field80_0x82;
    undefined field81_0x83;
    undefined field82_0x84;
    undefined field83_0x85;
    undefined field84_0x86;
    undefined field85_0x87;
    undefined field86_0x88;
    undefined field87_0x89;
    undefined field88_0x8a;
    undefined field89_0x8b;
    undefined field90_0x8c;
    undefined field91_0x8d;
    undefined field92_0x8e;
    undefined field93_0x8f;
    bool changed;

    BlockActor(BlockActorType, BlockPos const&, newstd::string const&);
    virtual ~BlockActor();
    virtual void load(Level &, CompoundTag const &, DataLoadHelper &); //from Element Zero and Ghidra
    virtual bool save(CompoundTag &) const;
    virtual bool saveItemInstanceData(CompoundTag &);
    virtual void saveBlockData(CompoundTag &, BlockSource &) const;
    virtual void loadBlockData(CompoundTag const &, BlockSource &, DataLoadHelper &);
    virtual void onCustomTagLoadDone(BlockSource &);
    virtual void tick(BlockSource &);
    virtual bool isFinished();
    virtual void onChanged(BlockSource &);
    virtual bool isMovable(BlockSource &);
    virtual bool isCustomNameSaved();
    virtual void onPlace(BlockSource &);
    virtual void onMove();
    virtual void onRemoved(BlockSource &);
    virtual void triggerEvent(int, int);
    virtual void clearCache();
    virtual void onNeighborChanged(BlockSource &, BlockPos const &);
    virtual float getShadowRadius(BlockSource &) const;
    virtual bool hasAlphaLayer() const;
    virtual class BlockActor *getCrackEntity(BlockSource &, BlockPos const &);
    virtual void getDebugText(newstd::vector<newstd::string> &, BlockPos const &);
    virtual newstd::string const &getCustomName() const;
    virtual newstd::string const &getFilteredCustomName(OldspeakContext const &);
    virtual newstd::string getName() const;
    virtual void setCustomName(newstd::string const &) const;
    virtual newstd::string getImmersiveReaderText(BlockSource &);
    virtual int getRepairCost() const;
    virtual class PistonBlockActor *getOwningPiston(BlockSource &);
    virtual class Container *getContainer();
    virtual class Container const *getContainer() const;
    virtual float getDeletionDelayTimeSeconds() const;
    virtual void onChunkLoaded(LevelChunk &);
    virtual void onChunkUnloaded(LevelChunk &);
    virtual void _getUpdatePacket(BlockSource *param_1);
    virtual void _onUpdatePacket(CompoundTag const&, BlockSource&);
    virtual void _playerCanUpdate(Player const&) const;
};

