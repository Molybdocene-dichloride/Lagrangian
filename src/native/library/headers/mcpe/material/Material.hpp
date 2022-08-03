#pragma once
enum class MaterialType {
	DIRT = 1,
	WOOD,
	STONE,
	IRON,
	WATER,
	LAVA,
	WOOL,
	DECORATION = 8,
	PLANT,
	SAND = 14,
	TORCH,
	PORTAL = 25,
	CIRCUIT = 28,
	LAMP = 30,
	OIL
};

class Material {
	public:
	enum Settings : int {
		Default
	};
	Material(MaterialType, Material::Settings, float);

	bool getBlocksMotion() const;
	bool getBlocksPrecipitation() const; //bool?!
	float getTranslucency() const;

	bool isType(MaterialType) const;

	bool isSolidBlocking() const;
	bool isFlammable() const;
	bool isNeverBuildable() const;
	bool isAlwaysDestroyable() const;
	bool isReplaceable() const;
	bool isLiquid() const;
	bool isSolid() const;
	bool isTopSolid(bool, bool) const;
	bool isSuperHot() const;

	void _setReplaceable();
	void _setFlammable();
	void _setNotAlwaysDestroyable();
	void _setNeverBuildable();
	void _setNotBlockingMotion();
	void _setNotBlockingPrecipitation();
	void _setNotSolid();
	void _setSolid();
	void _setSuperHot();

	static void initMaterials();
	static void _setupSurfaceMaterials();
	static void teardownMaterials();
	static Material const& getMaterial(MaterialType);
	static void addMaterial(std::__ndk1::unique_ptr<Material, std::__ndk1::default_delete<Material>>);

	void operator!=(Material const&) const;
	void operator==(Material const&) const;
	
	// static fields
	static std::vector<std::__ndk1::unique_ptr<Material>> mMaterials;
	static bool mInitialized;

};
