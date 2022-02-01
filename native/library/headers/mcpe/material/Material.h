#ifndef _MATERIAL_H
#define _MATERIAL_H

//This header template file is generated by Disassembler.

class Material {
public:
    //Fields
    char filler_Material[UNKNOW_SIZE];
public:
    //Methods
    Material(MaterialType, Material::Settings, float);
    ~Material();
    void isFlammable() const;
    void _setNotBlockingPrecipitation();
    void _setNeverBuildable();
    void isSolid() const;m
    void _setNotSolid();
    void _setSuperHot();
    void isAlwaysDestroyable() const;
    void _setReplaceable();
    void _setNotAlwaysDestroyable();
    void isReplaceable() const;
    void teardownMaterials();
    void _setNotBlockingMotion();
    void addMaterial(std::__ndk1::unique_ptr<Material, std::__ndk1::default_delete<Material> >);
    void getBlocksMotion() const;
    void _setSolid();
    void operator!=(Material const&) const;
    void initMaterials();
    void getMaterial(MaterialType);
    void isSolidBlocking() const;
    void _setupSurfaceMaterials();
    void getTranslucency() const;
    void isType(MaterialType) const;
    void isSuperHot() const;
    void isNeverBuildable() const;
    void operator==(Material const&) const;
    void _setFlammable();
    void isLiquid() const;
    void getBlocksPrecipitation() const;
    void isTopSolid(bool, bool) const;
public:
    //Objects
    static Material * mInitialized;
    static Material * mMaterials;
};//Material

#endif // _MATERIAL_H
