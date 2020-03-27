#pragma once

struct MiniSoundQueue
{
    int sound_id;
    EntityData1* entity1;
    int min_index;
    int volume;
    int timer;
    int volume_max;
    bool is3d;
};

struct SEFadeoutData
{
    int ID;
    int start;
    int speed;
};

struct SEDistanceOverride
{
    int ID;
    int dist_min;
    int dist_max;
    int volume;
};

struct ChaoSoundIDOverride
{
    int address;
    __int16 id;
};

enum SA1DCChaoSounds_SFX
{
    SE_BANK_1_AL = 0x257,
    SE_AL_KONKON = 0x258,
    SE_AL_TREE_YUSA = 0x259,
    SE_AL_FRUIT_FALL = 0x25A,
    SE_AL_VMUOPEN = 0x25B,
    SE_AL_VMUBUTTON = 0x25C,
    SE_AL_PON = 0x25D,
    SE_AL_06 = 0x25E,
    SE_AL_CAPTURE_KYUKYU = 0x25F,
    SE_AL_CAPTURE_KYUPIN = 0x260,
    SE_AL_09 = 0x261,
    SE_AL_10 = 0x262, //cursor in race
    SE_AL_11 = 0x263,
    SE_AL_HIRAMEKI = 0x264,
    SE_AL_KOKE = 0x265,
    SE_AL_UMARERU = 0x266,
    SE_AL_FLY = 0x267,
    SE_AL_FOOTSTEP_L = 0x268,
    SE_AL_17 = 0x269,
    SE_AL_18 = 0x26A,
    SE_AL_19 = 0x26B,
    SE_AL_EAT = 0x26C,
    SE_AL_21 = 0x26D, //cursor in race 2
    SE_AL_RAPPA2 = 0x26E, //Chao plays trumpet
    SE_AL_SWIM = 0x26F,
    SE_AL_SWIM2 = 0x270,
    SE_AL_25 = 0x271,
    SE_AL_26 = 0x272, //another cursor?
    SE_AL_DORE_OPEN = 0x273,
    SE_AL_28 = 0x274,
    SE_AL_PICK = 0x275,
    SE_AL_RAKUGAKI = 0x276,
    SE_AL_31 = 0x277, //Chao plays drum
    SE_AL_BOING = 0x278,
    SE_AL_SUNAHORI = 0x279, //Chao digs (?)
    SE_AL_34 = 0x27A,
    SE_AL_35 = 0x27B,
    SE_AL_DOPUN = 0x27C,
    SE_AL_HOUKI = 0x27D,
    SE_AL_PEN = 0x27E,
    SE_AL_KUJAKU = 0x27F,
    SE_AL_TUBAME = 0x280,
    SE_AL_OUMU = 0x281,
    SE_AL_BANBI = 0x282,
    SE_AL_GORILLA = 0x283,
    SE_AL_LION = 0x284,
    SE_AL_ZOU = 0x285,
    SE_AL_PHOO = 0x286,
    SE_AL_47 = 0x287, //empty, used for fire
    SE_AL_WARP = 0x288,
    SE_AL_49 = 0x289, //empty, used for goo
    SE_AL_50 = 0x28A,
    SE_AL_START = 0x28B,
    SE_AL_TAIKO = 0x28C,
    SE_AL_RAPPA = 0x28D,
    SE_AL_FUE = 0x28E,
    SE_AL_THINBAL = 0x28F,
    SE_AL_AGOGOBELL = 0x290,
    SE_AL_TAMBOURINE = 0x291,
    SE_AL_BONGO = 0x292,
    SE_AL_SUZU = 0x293,
};

enum SA1DCChaoSounds_BG //unused for now
{
    SE_BANK_5_AL = 0x373,
    SE_AL_MUSHI = 0x374,
    SE_AL_ZATTOU = 0x375,
    SE_AL_BEACH = 0x376,
    SE_AL_SPRING = 0x377,
    SE_AL_04 = 0x378,
};