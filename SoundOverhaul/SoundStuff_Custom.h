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

struct SEVolumeOverride
{
    int ID;
    int srcvol;
    int dstvol;
};

struct SEDistanceOverride
{
    int ID;
    int dist_min;
    int dist_max;
    int volume;
};