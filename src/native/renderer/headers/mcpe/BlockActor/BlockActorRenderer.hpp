#pragma once

#include "../render/MaterialPtr.hpp"

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

class ActorShaderManager { //from Ghidra
    public:
    //undefined * * vtable;
    MaterialPtr entity_material_ptr;
    MaterialPtr transparent_entity_material_ptr;
    MaterialPtr static_material_ptr;

    virtual ~ActorShaderManager();
    virtual void _getOverlayColor(Actor&, float) const;
};

class BaseActorRenderer : public ActorShaderManager { //from Ghidra
    public:
    MaterialPtr material_ptr;
    MaterialPtr tag_material_ptr;
    MaterialPtr text_material_ptr;

    BaseActorRenderer();

    virtual ~BaseActorRenderer();
};

class BlockActorRenderer : public BaseActorRenderer { //from Ghidra
    public:
    //not unique members

    BlockActorRenderer();
    //_renderModel(ScreenContext&, dragon::RenderMetadata const&, Model&, mce::ClientTexture const&, mce::MaterialPtr const&, mce::ClientTexture const&) const;
    //_renderModel(ScreenContext&, dragon::RenderMetadata const&, Model&, mce::ClientTexture const&) const;
    //_renderModel(ScreenContext&, dragon::RenderMetadata const&, Model&, mce::ClientTexture const&, mce::ClientTexture const&) const;
    
    virtual ~BlockActorRenderer();
    virtual void render(BaseActorRenderContext&, BlockActorRenderData&) = 0; //for rendering
    virtual void renderAlpha(BaseActorRenderContext&, BlockActorRenderData&);
    virtual void extractText(Tessellator&, BlockActor&, newstd::string const&, newstd::vector<int> const&, Vec3, bool);
};