typedef unsigned char   undefined;

typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined3;
typedef unsigned int    undefined4;
typedef unsigned long long    undefined5;
typedef unsigned long long    undefined6;
typedef unsigned long long    undefined7;
typedef unsigned long long    undefined8;

struct Vec3 { /* PlaceHolder Structure */
    float x;
    float y;
    float z;
};

struct AABB { /* PlaceHolder Structure */
    struct Vec3 start;
    struct Vec3 end;
    struct bool empty;
};

struct BlockPos { /* PlaceHolder Structure */
    float x;
    float y;
    float z;
};

struct BlockActor { /* PlaceHolder Structure */
    undefined * * vtable;
    int counter; /* Created by retype action */
    struct Block * block;
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
    struct BlockPos position; /* Created by retype action */
    struct AABB aabb;
    undefined field25_0x45;
    undefined field26_0x46;
    undefined field27_0x47;
    BlockActorType type;
    struct BlockActorRendererId renderer_id;
    undefined field30_0x4d;
    undefined field31_0x4e;
    undefined field32_0x4f;
    struct basic_string custom_name;
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
    undefined1 field_strange; /* Created by retype action */
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
    uint repair_cost; /* Created by retype action */
    bool client_side_only; /* Created by retype action */
    bool movable; /* Created by retype action */
    bool custom_name_saved; /* Created by retype action */
    bool can_render_name; /* Created by retype action */
    undefined field62_0x70;
    undefined field63_0x71;
    undefined field64_0x72;
    undefined field65_0x73;
    undefined field66_0x74;
    undefined field67_0x75;
    undefined field68_0x76;
    undefined field69_0x77;
    undefined1 entity_interlock; /* Created by retype action */
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
    bool changed; /* Created by retype action */
};

