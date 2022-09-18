typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned char    byte;
typedef unsigned int    dword;
typedef int    int3;
typedef long double    longdouble;
typedef long long    longlong;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned int    uint3;
typedef unsigned long    ulong;
typedef unsigned long long    ulonglong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined3;
typedef unsigned int    undefined4;
typedef unsigned long long    undefined5;
typedef unsigned long long    undefined6;
typedef unsigned long long    undefined7;
typedef unsigned long long    undefined8;
typedef unsigned short    ushort;
typedef int    wchar_t;
typedef unsigned short    word;
typedef struct TextureAtlas TextureAtlas, *PTextureAtlas;

typedef struct shared_ptr<Bedrock::EnableNonOwnerReferences::ControlBlock> shared_ptr<Bedrock::EnableNonOwnerReferences::ControlBlock>, *Pshared_ptr<Bedrock::EnableNonOwnerReferences::ControlBlock>;

typedef struct shared_ptr<AtlasItemManager> shared_ptr<AtlasItemManager>, *Pshared_ptr<AtlasItemManager>;

typedef struct ParsedAtlasData ParsedAtlasData, *PParsedAtlasData;

typedef struct AtlasParameters AtlasParameters, *PAtlasParameters;

typedef struct set set, *Pset;

typedef struct ImageResourceManager ImageResourceManager, *PImageResourceManager;

typedef struct vector vector, *Pvector;

typedef struct ResourceLocation ResourceLocation, *PResourceLocation;

typedef struct PageSettings PageSettings, *PPageSettings;

typedef struct ResourceManager<std::__ndk1::shared_ptr<mce::Image>,ResourceLocation,ImageTrackerTemplate<ImageResourceManager>,std::__ndk1::shared_ptr<mce::Image>,std::__ndk1::unordered_map> ResourceManager<std::__ndk1::shared_ptr<mce::Image>,ResourceLocation,ImageTrackerTemplate<ImageResourceManager>,std::__ndk1::shared_ptr<mce::Image>,std::__ndk1::unordered_map>, *PResourceManager<std::__ndk1::shared_ptr<mce::Image>,ResourceLocation,ImageTrackerTemplate<ImageResourceManager>,std::__ndk1::shared_ptr<mce::Image>,std::__ndk1::unordered_map>;

typedef dword ResourceFileSystem;

typedef struct PathBuffer<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>> PathBuffer<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>, *PPathBuffer<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>;

typedef struct basic_string basic_string, *Pbasic_string;

typedef struct Color Color, *PColor;

typedef struct unordered_map unordered_map, *Punordered_map;

struct shared_ptr<AtlasItemManager> { /* PlaceHolder Structure */
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct set { /* PlaceHolder Structure */
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct AtlasParameters {
    int mPadSize;
    int mReductionMips;
    uint mColorMipCount;
};

struct unordered_map { /* PlaceHolder Structure */
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
    undefined field24_0x18;
    undefined field25_0x19;
    undefined field26_0x1a;
    undefined field27_0x1b;
};

struct basic_string { /* PlaceHolder Structure */
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
};

struct Color { /* PlaceHolder Structure */
    float r;
    float g;
    float b;
    float a;
};

struct PageSettings { /* PlaceHolder Structure */
    struct basic_string mResourceName;
    struct basic_string mJsonKey; /* Created by retype action */
    struct basic_string mFileSuffix; /* Created by retype action */
    struct basic_string mDefaultTexture; /* Created by retype action */
    struct Color mDefaultColor;
    bool mFadeMip;
    bool mApplyTint;
    bool mApplyOverlay;
};

struct shared_ptr<Bedrock::EnableNonOwnerReferences::ControlBlock> { /* PlaceHolder Structure */
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct PathBuffer<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>> { /* PlaceHolder Structure */
};

struct ResourceLocation { /* PlaceHolder Structure */
    ResourceFileSystem mFileSystem;
    struct PathBuffer<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>> pathBuffer;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    undefined field5_0x8;
    undefined field6_0x9;
    undefined field7_0xa;
    undefined field8_0xb;
    undefined * field9_0xc;
    ulonglong mPathHash;
    ulonglong full_hash;
};

struct vector { /* PlaceHolder Structure */
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
};

struct ParsedAtlasData { /* PlaceHolder Structure */
    struct ResourceLocation resourceLocation;
    struct PageSettings page_settings; /* Created by retype action */
    undefined field2_0x63;
    int mJsonPadSize;
    uint mJsonNumberOfMips;
    struct vector atlas_nodes_list; /* Created by retype action */
};

struct ResourceManager<std::__ndk1::shared_ptr<mce::Image>,ResourceLocation,ImageTrackerTemplate<ImageResourceManager>,std::__ndk1::shared_ptr<mce::Image>,std::__ndk1::unordered_map> { /* PlaceHolder Structure */
    struct unordered_map mContainer;
};

struct ImageResourceManager { /* PlaceHolder Structure */
    struct ResourceManager<std::__ndk1::shared_ptr<mce::Image>,ResourceLocation,ImageTrackerTemplate<ImageResourceManager>,std::__ndk1::shared_ptr<mce::Image>,std::__ndk1::unordered_map> field0_0x0;
};

struct TextureAtlas { /* PlaceHolder Structure */
    struct shared_ptr<Bedrock::EnableNonOwnerReferences::ControlBlock> mControlBlock;
    struct shared_ptr<AtlasItemManager> atlasItemManager;
    struct ParsedAtlasData mParsedAtlasData; /* Created by retype action */
    struct AtlasParameters params;
    struct set mResources;
    struct ImageResourceManager mResourceManager;
    struct vector mFileWatcherHandle;
};

