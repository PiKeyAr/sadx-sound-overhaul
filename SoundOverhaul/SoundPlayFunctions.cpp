#include "stdafx.h"

int DelayedSoundCount = 0;

MiniSoundQueue DelayedSounds[] = {
	{ -1, NULL, 0, 0, 0, NULL, false },
	{ -1, NULL, 0, 0, 0, NULL, false },
	{ -1, NULL, 0, 0, 0, NULL, false },
	{ -1, NULL, 0, 0, 0, NULL, false },
	{ -1, NULL, 0, 0, 0, NULL, false },
	{ -1, NULL, 0, 0, 0, NULL, false },
	{ -1, NULL, 0, 0, 0, NULL, false },
	{ -1, NULL, 0, 0, 0, NULL, false },
	{ -1, NULL, 0, 0, 0, NULL, false },
	{ -1, NULL, 0, 0, 0, NULL, false },
	{ -1, NULL, 0, 0, 0, NULL, false },
	{ -1, NULL, 0, 0, 0, NULL, false },
	{ -1, NULL, 0, 0, 0, NULL, false },
	{ -1, NULL, 0, 0, 0, NULL, false },
	{ -1, NULL, 0, 0, 0, NULL, false },
	{ -1, NULL, 0, 0, 0, NULL, false },
	{ -1, NULL, 0, 0, 0, NULL, false },
	{ -1, NULL, 0, 0, 0, NULL, false },
	{ -1, NULL, 0, 0, 0, NULL, false },
	{ -1, NULL, 0, 0, 0, NULL, false },
};

int PlaySound_StandardTimer_Delay(SoundIDs ID, void* entity, int pri, int volume)
{
	for (int i = 0; i < 20; i++)
	{
		if (DelayedSounds[i].sound_id == -1)
		{
			DelayedSounds[i].sound_id = ID;
			DelayedSounds[i].entity1 = (EntityData1*)entity;
			DelayedSounds[i].min_index = pri;
			DelayedSounds[i].volume = volume;
			DelayedSounds[i].is3d = false;
			DelayedSoundCount++;
			return 1;
		}
	}
	return PlaySound_StandardTimer(ID, entity, pri, volume);
}

int PlaySound_FadeOut(int ID, EntityData1* entity, int index, int volume, int timer)
{
	Sint32 v4; // eax
	Sint32 v6; // eax
	int v7; // ecx
	v4 = SoundQueue_GetFreeIndex(index);
	if (v4 < 0)
	{
		return -1;
	}
	SoundQueue[v4].timer = timer;
	SoundQueue[v4].pri = -1;
	SoundQueue[v4].flags = 0x215;
	SoundQueue[v4].id = ID;
	SoundQueue[v4].pan = 0;
	SoundQueue[v4].volume = volume;
	SoundQueue[v4].volume_max = volume;
	SoundQueue[v4].pitch = 0;
	return 1;
}

int PlaySound_XYZ_IgnoreDuplicates(int ID, EntityData1* entity, int index, int volume, float x, float y, float z)
{
	Sint32 v4; // eax
	Sint32 v6; // eax
	int v7; // ecx
	v4 = SoundQueue_GetFreeIndex(index);
	if (v4 < 0)
	{
		return -1;
	}
	SoundQueue[v4].entity = entity;
	SoundQueue[v4].timer = 120;
	SoundQueue[v4].pri = -1;
	SoundQueue[v4].flags = (SoundFlags)0x111;
	SoundQueue[v4].id = ID;
	SoundQueue[v4].pan = 0;
	SoundQueue[v4].volume = volume;
	SoundQueue[v4].volume_max = volume;
	SoundQueue[v4].pitch = 0;
	SoundQueue[v4].pos.x = x;
	SoundQueue[v4].pos.y = y;
	SoundQueue[v4].pos.z = z;
	return 1;
}

int QueueBullet(int sound_id, EntityData1* entity, int min_index, int volume, float x, float y, float z)
{
	Sint32 v4; // eax
	Sint32 v6; // eax
	int v7; // ecx
	v4 = SoundQueue_GetFreeIndex(min_index);
	if (v4 < 0)
	{
		return -1;
	}
	SoundQueue[v4].entity = entity;
	SoundQueue[v4].timer = 120;
	SoundQueue[v4].pri = -1;
	SoundQueue[v4].flags = (SoundFlags)0x111;
	SoundQueue[v4].id = sound_id;
	SoundQueue[v4].pan = 0;
	SoundQueue[v4].volume = volume;
	SoundQueue[v4].volume_max = volume;
	SoundQueue[v4].pitch = 0;
	SoundQueue[v4].pos.x = x;
	SoundQueue[v4].pos.y = y;
	SoundQueue[v4].pos.z = z;
	return 1;
}

void PlaySound_Delayed(int sound_id, EntityData1* a2, int min_index, int volume, int timer, EntityData1* a6)
{
	for (int i = 0; i < LengthOfArray(DelayedSounds); i++)
	{
		if (DelayedSounds[i].sound_id == -1)
		{
			DelayedSounds[i].sound_id = sound_id;
			DelayedSounds[i].entity1 = a2;
			DelayedSounds[i].min_index = min_index;
			DelayedSounds[i].volume = volume;
			DelayedSounds[i].timer = timer;
			DelayedSounds[i].is3d = true;
			DelayedSounds[i].volume_max = (int)a6;
			DelayedSoundCount++;
			return;
		}
	}
	PlaySound_3D_Timer_pri(sound_id, a2, min_index, volume, timer, a6);
}

int StopSound_Fade(int num)
{
	for (int i = 0; i < 36; i++)
	{
		if (SoundQueue[i].id == num)
		{
			SoundQueue[i].flags |= 0x204;
			SoundQueue[i].timer = 100;
		}
	}
	return 0;
}

void AlarmFix(SoundIDs sound_id, EntityData1* entity, int pri, int volume, float x, float y, float z)
{
	signed int v7; // ebx
	double v8; // st7
	double v9; // st6
	double v10; // st5
	unsigned __int8 v12; // c0
	unsigned __int8 v13; // c3
	Sint32 index; // eax
	int v15; // ebx
	Sint32 v16; // ecx

	v7 = 0;
	if (Camera_Data1)
	{
		v8 = x - Camera_Data1->Position.x;
		v9 = y - Camera_Data1->Position.y;
		v10 = z - Camera_Data1->Position.z;
		v7 = 0x1000;
	}
	index = SoundQueue_GetOtherThing(sound_id, entity);
	if (index < 0)
	{
		index = SoundQueue_GetFreeIndex(pri);
		if (index < 0)
		{
			return;
		}
		v15 = v7 | 1;
	}
	else
	{
		v15 = SoundQueue[index].flags & 1;
	}
	v16 = index;
	SoundQueue[v16].volume = volume;
	SoundQueue[v16].volume_max = volume;
	SoundQueue[v16].entity = entity;
	SoundQueue[v16].pos.x = x;
	SoundQueue[v16].pan = 0;
	SoundQueue[v16].pitch = 0;
	SoundQueue[v16].id = sound_id;
	SoundQueue[v16].pos.y = y;
	SoundQueue[v16].flags = v15 | 0x110;
	SoundQueue[v16].timer = 96;
	SoundQueue[v16].pri = -1;
	SoundQueue[v16].pos.z = z;
}

Sint32 FreezerFix(SoundIDs sound_id, EntityData1* entity, int pri, int volume, int playlength, float x, float y, float z)
{
	unsigned __int8 v12; // c0
	unsigned __int8 v13; // c3
	int _i; // eax
	int flag_play; // ecx
	int i; // eax

	_i = SoundQueue_GetOtherThing(sound_id, entity);
	if (_i < 0)
	{
		_i = SoundQueue_GetFreeIndex(pri);
		if (_i < 0)
		{
			return -1;
		}
		flag_play = 0x1001;
	}
	else
	{
		flag_play = SoundQueue[_i].flags & 1;
	}
	i = _i;
	SoundQueue[i].flags = flag_play | 0x130;
	SoundQueue[i].volume = volume;
	SoundQueue[i].volume_max = volume;
	SoundQueue[i].pri = pri;
	SoundQueue[i].timer = playlength + 1;
	SoundQueue[i].pos.x = x;
	SoundQueue[i].pos.y = y;
	SoundQueue[i].pos.z = z;
	SoundQueue[i].entity = entity;
	SoundQueue[i].id = sound_id;
	SoundQueue[i].pan = 0;
	SoundQueue[i].pitch = 0;
	return 0;
}

/*
//Ended up not using it
int CustomSound(int ID, EntityData1* entity, int index, int volume, int volume_max, int length, int flags, float x, float y, float z)
{
	Sint32 v4; // eax
	Sint32 v6; // eax
	int v7; // ecx
	v4 = SoundQueue_GetFreeIndex(index);
	if (v4 < 0)
	{
		return -1;
	}
	SoundQueue[v4].entity = entity;
	SoundQueue[v4].timer = length;
	SoundQueue[v4].pri = -1;
	SoundQueue[v4].flags = flags;
	SoundQueue[v4].id = ID;
	SoundQueue[v4].pan = 0;
	SoundQueue[v4].volume = volume;
	SoundQueue[v4].volume_max = volume_max;
	SoundQueue[v4].pitch = 0;
	SoundQueue[v4].pos.x = x;
	SoundQueue[v4].pos.y = y;
	SoundQueue[v4].pos.z = z;
	SoundQueueOriginEntities[v4] = entity;
	return 1;
}
*/