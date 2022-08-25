#pragma once

enum BlockActorType {
    SOMETHING
};

typedef UIProfanityContext OldspeakContext; //Mojang distopy fuck you!

class BlockActor {//from Ghidra
    

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

