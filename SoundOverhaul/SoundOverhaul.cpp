#include <SADXModLoader.h>
#include "Trampoline.h"

struct SoundEntry
{
	int MaxIndex; //Maximum index? Can be 0xFFFFFFFF
	int PlayLength; //0xFFFFFFFF to loop indefinitely
	void *SourceEntity; //Sound stops when entity is destroyed
	int Flags; //3D sound related, ANDs with 1, 10, 100, 200, 800, 2000, 4000, 0x11 in PlaySound2, 0x801 in PlaySound, | 0x10 in DualEntity, 
	int SoundID;
	int Whatever; //Only used in PlaySound which sets it to 0x00000008
	int VolumeA;
	int VolumeB;
	int null; //Always 0
	NJS_VECTOR origin;
	int NoIndex; //Only used when a free index can't be found (set to 0xFFFFFFFF)
	float null_2; //Unused
};

FunctionPointer(Sint32, sub_424FC0, (int a1, EntityData1 *a2, int a3, int a4, float x, float y, float z), 0x424FC0);
FunctionPointer(ObjectMaster*, LoadIceCapBomb, (NJS_VECTOR *a1), 0x4F5E50);
FunctionPointer(void, IceCapBomber_Main, (ObjectMaster *), 0x4EC2E0);
FunctionPointer(void, IceCapBomber_Display, (ObjectMaster *a1), 0x4EC310);
FunctionPointer(ObjectMaster*, sub_64FD00, (int a1, int a2, int a3), 0x64FD00);
FunctionPointer(void, sub_42FE00, (ObjectMaster *a1, NJS_ACTION *a2, NJS_TEXLIST *a3, float a4, char a5, char a6), 0x42FE00);
FunctionPointer(void, sub_4314D0, (int a1), 0x4314D0);
FunctionPointer(void, OErupt_PlaySound, (int a1, EntityData1 *a2, int a3, int a4, int a5, EntityData1 *a6), 0x424880);
FunctionPointer(Sint32, QueueSoundAtPosition, (int sound_id, EntityData1 *a2, int a3, int a4, float x, float y, float z), 0x424FC0);
DataPointer(int, FramerateSetting_Config, 0x0089295C);
DataPointer(int, FramerateSetting, 0x0389D7DC);
DataPointer(int, SoundQueueThing, 0x004250AE);
DataArray(SoundEntry, SoundQueue, 0x3B292F8, 100);
static bool SnowSoundFixed = false;

SoundFileInfo E101mkIISoundList_list[] = {
	{ 0, "COMMON_BANK00" },
	{ 1, "E101_BANK01" },
	{ 2, "CHECK_SHEET_BANK02" },
	{ 4, "E101R_BANK04" },
	{ 5, "" }
};

SoundFileInfo FinalEggSoundList_list[] = {
	{ 0, "COMMON_BANK00" },
	{ 1, "FINAL_EGG_BANK01" },
	{ 2, "CHECK_SHEET_BANK02" },
	{ 4, "ENEMY_SET_BANK04" },
	{ 5, "FINAL_EGG_BANK05" }
};

SoundList FinalEggSoundList = { arraylengthandptr(FinalEggSoundList_list) };
SoundList E101mkIISoundList = { arraylengthandptr(E101mkIISoundList_list) };

void PlaySpindash(int id, EntityData1 *Data1, int a3, EntityData1 *a4, int a5)
{
	QueueSound_DualEntity(767, Data1, 1, 0, 160);
}

void TailsWhatAmIGonnaDoWithYou()
{
	sub_64FD00(0, 1335, 1800);
}

void WhoahSomethingBuggingYou()
{
	if (VoiceLanguage)
	{
		LoadSoundList(70);
		LoadSoundList(72);
	}
	else
	{
		LoadSoundList(69);
		LoadSoundList(71);
	}
}

void IceCapBomberFix(int sound_id, EntityData1 *entity, int min_index, int volume, float x, float y, float z)
{
	QueueSoundAtPosition(sound_id, EntityData1Ptrs[0], min_index, volume, x, y, z);
}

void PlayCharacterHurtVoice(int ID, void *a2, int a3, void *a4)
{
	PlaySound(ID, a2, a3, a4);
	if ( GetCurrentCharacterID() == Characters_Gamma )
	{
		PlaySound(1431, 0, 0, 0);
	}
	else
	{
		PlaySound(23, 0, 0, 0);
	}
}

void DolphinSoundFix(int a1, EntityData1 *a2, int a3, int a4, int a5, EntityData1 *a6)
{
	if (FramerateSetting >= 2) OErupt_PlaySound(a1, a2, a3, a4, a5, a6);
	else OErupt_PlaySound(a1, a2, a3, a4, a5 * 2, a6);
}

void EggWalkerMissileFix(int sound_id, EntityData1 *a2, int a3, int a4, int a5, EntityData1 *a6)
{
	OErupt_PlaySound(sound_id, a2, a3, a4, a5, EntityData1Ptrs[0]);
}

int BoaFix(int ID, EntityData1 *entity, int index, int volume, float x, float y, float z)
{
	Sint32 v4; // eax
	Sint32 v6; // eax
	int v7; // ecx
	v4 = SoundQueue_GetFreeIndex(index);
	if (v4 < 0)
	{
		return -1;
	}
	SoundQueue[v4].SourceEntity = entity;
	SoundQueue[v4].PlayLength = 120;
	SoundQueue[v4].MaxIndex = -1;
	SoundQueue[v4].Flags = 0x111;
	SoundQueue[v4].SoundID = ID;
	SoundQueue[v4].Whatever = 0;
	SoundQueue[v4].VolumeA = volume;
	SoundQueue[v4].VolumeB = 0;
	SoundQueue[v4].null = 0;
	SoundQueue[v4].origin.x = x;
	SoundQueue[v4].origin.y = y;
	SoundQueue[v4].origin.z = z;
	return 1;
}

extern "C"
{
	__declspec(dllexport) void __cdecl Init()
	{
		WriteCall((void*)0x79FCE4, BoaFix); //Recreate a "bug" from the DC version to create deeper sound
		WriteData<1>((char*)0x42508D, 0x11u); //Fix for sounds playing multiple times over
		WriteCall((void*)0x57B00C, EggWalkerMissileFix); //Missing entity fix
		//Missing sound fixes
		WriteCall((void*)0x4507FA, PlayCharacterHurtVoice); //Makes Sonic and Gamma play hurt sounds
		WriteCall((void*)0x6CE25C, WhoahSomethingBuggingYou); //Load the player soundbanks to play the "whoah!" voice when Knuckles attacks Sonic/Tails
		//Various sound cutoff fixes
		WriteCall((void*)0x496F33, PlaySpindash); //Prevent the cutoff of the spindash (supposed to fade out but it's broken in SADX)
		WriteCall((void*)0x5ECB4F, PlaySound2); //Go up! Full speed ahead!
		WriteData<2>((void*)0x53881F, 0x90u); //Enable ambient sound in MR Final Egg base
		WriteData<1>((char*)0x571AAF, 0x08); //Fix Egg Hornet sound loop
		WriteData<1>((char*)0x6AF86B, 0i8); //I forgot to put in the landing gear!
		WriteData<1>((char*)0x6CE07B, 0i8); //There's no landing gear in this mode!
		WriteData<1>((char*)0x6CA530, 0x34); //Goin' down! Aaaah! Look out below!
		WriteCall((void*)0x6E96B9, TailsWhatAmIGonnaDoWithYou);
		WriteCall((void*)0x4FADCF, DolphinSoundFix);
		//Missing soundbank sounds fixes
		SoundLists[35] = E101mkIISoundList;
		SoundLists[37] = FinalEggSoundList; //Final Egg
		//Cutscene soundbank fixes
		WriteData<1>((char*)0x66DC76, 111); //Gamma steals Froggy
		WriteData<1>((char*)0x6A40C8, 108); //Amy talking to Gamma (Amy's story)
		WriteData<1>((char*)0x677F8B, 108); //Amy talking to Gamma (Gamma's story)
	}

	__declspec(dllexport) void __cdecl OnFrame()
	{
		auto entity = EntityData1Ptrs[0];
		//Sound queue framerate fix
		if (FramerateSetting >= 2 && SoundQueueThing != 120)
		{
			WriteData((int*)0x4250AE, 120); //Fixes the QueueSoundAtPosition function to work properly at 30 FPS
		}
		if (FramerateSetting < 2 && SoundQueueThing == 120)
		{
			WriteData((int*)0x4250AE, 240); //Fixes the QueueSoundAtPosition function to work properly at 60 FPS
		}
		//Ice Cap/Sand Hill thing
		if (CurrentLevel != 8 || CurrentAct != 2 || GameState == 3 || GameState == 4 || GameState == 7 || GameState == 21) SnowSoundFixed = false;
		if (entity != nullptr)
		{
			if (CurrentLevel == 8 && CurrentAct == 2)
			{
				if (SnowSoundFixed == false && entity->Status & Status_Ground && entity->Action == 62)
				{
					entity->Status &= ~Status_Ground;
					entity->Status &= ~Status_Unknown3;
					SnowSoundFixed = true;
				}
			}
		}
	}

	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}