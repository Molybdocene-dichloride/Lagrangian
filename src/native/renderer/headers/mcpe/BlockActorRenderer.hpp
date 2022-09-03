#pragma once

typedef unsigned char    undefined;

typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined3;
typedef unsigned int    undefined4;
typedef unsigned long long    undefined5;
typedef unsigned long long    undefined6;
typedef unsigned long long    undefined7;
typedef unsigned long long    undefined8;

class BaseActorRenderContext;
class BlockActorRenderData;
class BlockActor;
class Tessellator;

enum BlockActorRendererId {
    DefaultRenderer      = 0x0,
    ChestRenderer        = 0x1,
    SignRenderer         = 0x2,
    SpawnerRenderer      = 0x3,
    SkullRenderer        = 0x4,
    EnchantRenderer      = 0x5,
    PistonarmRenderer    = 0x6,
    FrameRenderer        = 0x7,
    MovingblockRenderer  = 0x8,
    ChalkboardRenderer   = 0x9,
    BeaconRenderer       = 0x0A,
    EndgatewayRenderer   = 0x0B,
    EnderchestRenderer   = 0x0C,
    ShulkerBoxRenderer   = 0x0D,
    CommandblockRenderer = 0x0E,
    BedRenderer          = 0x0F,
    BannerRenderer       = 0x10,
    ConduitRenderer      = 0x11,
    LecternRenderer      = 0x12,
    BellRenderer         = 0x13,
    CampfireRenderer     = 0x14
};

class Actor;

class HashedString;

class MaterialPtr;

class ActorShaderManager {
    virtual ~ActorShaderManager();
    virtual void _getOverlayColor(Actor&, float) const;
};

class BaseActorRenderer : public ActorShaderManager {
    public:
    BaseActorRenderer();

    virtual ~BaseActorRenderer();
};

class BlockActorRenderer : public BaseActorRenderer { //from Ghidra, maybe move part of members to BaseActorRenderer
    public:
    //undefined * * vtable;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    undefined field5_0x8;
    undefined field6_0x9;
    undefined field7_0xa;
    undefined field8_0xb;
    undefined field9_0xc;
    undefined field10_0xd;
    undefined field11_0xe;
    undefined field12_0xf;
    undefined field13_0x10;
    undefined field14_0x11;
    undefined field15_0x12;
    undefined field16_0x13;
    undefined field17_0x14;
    undefined field18_0x15;
    undefined field19_0x16;
    undefined field20_0x17;
    undefined field21_0x18;
    undefined field22_0x19;
    undefined field23_0x1a;
    undefined field24_0x1b;
    MaterialPtr * material_ptr;
    undefined field26_0x20;
    undefined field27_0x21;
    undefined field28_0x22;
    undefined field29_0x23;
    MaterialPtr * tag_material_ptr;
    undefined field31_0x28;
    undefined field32_0x29;
    undefined field33_0x2a;
    undefined field34_0x2b;
    MaterialPtr * text_material_ptr;

    BlockActorRenderer();
    //_renderModel(ScreenContext&, dragon::RenderMetadata const&, Model&, mce::ClientTexture const&, mce::MaterialPtr const&, mce::ClientTexture const&) const;
    //_renderModel(ScreenContext&, dragon::RenderMetadata const&, Model&, mce::ClientTexture const&) const;
    //_renderModel(ScreenContext&, dragon::RenderMetadata const&, Model&, mce::ClientTexture const&, mce::ClientTexture const&) const;
    
    virtual ~BlockActorRenderer();
    virtual void render(BaseActorRenderContext&, BlockActorRenderData&) = 0; //for rendering
    virtual void renderAlpha(BaseActorRenderContext&, BlockActorRenderData&);
    virtual void extractText(Tessellator&, BlockActor&, newstd::string const&, newstd::vector<int> const&, Vec3, bool);
};