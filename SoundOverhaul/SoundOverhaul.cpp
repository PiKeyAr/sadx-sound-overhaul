#include <SADXModLoader.h>
#include "IniFile.hpp"
#include "Trampoline.h"
#include "SoundStuff.h"


//PlaySound-like functions
//Standard
FunctionPointer(int, PlaySound_StandardTimer, (int ID, void* entity, int pri, int volume), 0x423D70);
FunctionPointer(int, PlaySound_Loop, (int ID, void* entity, int pri, int volume), 0x423E20);
FunctionPointer(Sint32, PlaySound_Timer, (int ID, void* entity, int pri, int volume, int playlength), 0x423F50);
//Positional
FunctionPointer(void, PlaySound_Positional_Timer, (int ID, EntityData1* entity, int pri, int volume, int length, float x, float y, float z), 0x424000);
FunctionPointer(void, PlaySound_Positional_StandardTimer, (int ID, EntityData1* entity, int pri, int volume, float x, float y, float z), 0x424FC0);
//3D
FunctionPointer(void, PlaySound_3D_Timer_Priority, (int ID, EntityData1 *entity, int pri, int volume, int playlength, EntityData1 *entity_origin), 0x424880);
FunctionPointer(void, PlaySound_3D_Timer, (int ID, EntityData1* entity, int pri, int volume, int playlength, EntityData1* entity_origin), 0x424920);
FunctionPointer(void, PlaySound_Pseudo3D, (int ID, EntityData1* entity, int index, int volume, int length, float x, float y, float z), 0x424100);
FunctionPointer(void, PlaySound_3D_WithCamera_Timer, (int ID, EntityData1* entity, int pri, int volume, int playlength, float unused_multiplier, EntityData1* origin_entity), 0x4249E0);

FunctionPointer(ObjectMaster*, Cutscene_PlaySoundWithPitch, (int a1, int a2, int a3), 0x64FD00);
DataPointer(int, FramerateSetting_Config, 0x0089295C);
DataPointer(int, FramerateSetting, 0x0389D7DC);
DataPointer(int, TimerValue_PlaySound_Positional_StandardTimer, 0x004250AE);
DataArray(SoundEntry, SoundQueue, 0x3B292F8, 100);
DataArray(SoundFileInfo, SoundList_E101, 0x90F820, 5);
DataArray(SoundFileInfo, SoundList_HotShelter, 0x90F8F0, 5);

//Config stuff
bool BoaBoaFix = true;
bool ClassicRingPan = true;
bool FixSoundVolume = true;
bool SpindashFade = true;
bool DelayedSoundsEnabled = true;
bool AdvancedVolumeControl = true;
int MovieVolumeSO = 100;
int MovieVolume_Real = 0;
int MusicVolumeBoost = 5100;
int VoiceVolumeBoost = 0;

//Other stuff
bool SnowSoundFixed = false;
int DelayedSoundCount = 0;
int MusicVolumeConv = 0;

int VoiceVolumeConv = 0;
int VolumeFixesApplied = false;

int ConvertLinearToDirectX(int value, int max)
//Solution by JohnBolton, taken from https://www.gamedev.net/forums/topic/337397-sound-volume-question-directsound/?tab=comments#comment-3197281
{
	if (value == 0)
	{
		return -10000;
	}
	else
	{
		return (int)floorf(2000.0f * log10f((float)(value) / (float)max) + 0.5f);
	}
}

static void __cdecl SetSoundVolume_r(int queue_id, int volume);
static Trampoline SetSoundVolume_t(0x4101A0, 0x4101A5, SetSoundVolume_r);
static void __cdecl SetSoundVolume_r(int queue_id, int volume)
{
	auto original = reinterpret_cast<decltype(SetSoundVolume_r)*>(SetSoundVolume_t.Target());
	if (FixSoundVolume)
	{
		//Get 3D flags
		int v2 = SoundQueue[queue_id].Flags;
		//Calculate original volume value from DSound crap
		int conv_volume = ((volume / 2) + 640) / 5;
		//If the volume is -10000 or the sound is 3D, run the original function
		if (volume == -10000 || v2 & 0x4000)
		{
			original(queue_id, volume);
			return;
		}
		//If the volume is above 110, just set the maximum possible volume
		else if (SoundQueue[queue_id].CurrentVolume >= 110)
		{
			original(queue_id, 0); //-128 to 127
		}
		//Else convert the volume using the formula and pass it
		else
		{
			PrintDebug("Sound ID %d, DSound original: %d, Ingame: %d, Queue volume: %d, DSound converted: %d\n", SoundQueue[queue_id].SoundID, volume, conv_volume, SoundQueue[queue_id].CurrentVolume, ConvertLinearToDirectX(conv_volume + 128, 255));
			original(queue_id, ConvertLinearToDirectX(conv_volume + 128, 255)); //-128 to 127
			return;
		}
	}
	else original(queue_id, volume);
}

int PlaySound_FadeOut(int ID, EntityData1* entity, int index, int volume)
{
	Sint32 v4; // eax
	Sint32 v6; // eax
	int v7; // ecx
	v4 = SoundQueue_GetFreeIndex(index);
	if (v4 < 0)
	{
		return -1;
	}
	SoundQueue[v4].PlayTime = 120;
	SoundQueue[v4].Priority = -1;
	SoundQueue[v4].Flags = 0x205;
	SoundQueue[v4].SoundID = ID;
	SoundQueue[v4].Panning = 0;
	SoundQueue[v4].CurrentVolume = volume;
	SoundQueue[v4].MaxVolume = volume;
	SoundQueue[v4].PitchShift = 0;
	return 1;
}

void PlaySpindash(int id, EntityData1 *Data1, int a3, EntityData1 *a4, int a5)
{
	if (CharObj2Ptrs[0])
	{
		if (!SpindashFade) PlaySound_Timer(767, Data1, 1, 0, 160);
		else if (CharObj2Ptrs[0]->Upgrades & Upgrades_LightShoes) PlaySound_FadeOut(767, Data1, 1, 0);
		else PlaySound_Timer(767, Data1, 1, 0, 160);
	}
	else PlaySound_Timer(767, Data1, 1, 0, 160);
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

void PlayCharacterHurtVoice(int ID, void *a2, int a3, int a4)
{
	PlaySound_StandardTimer(ID, a2, a3, a4);
	if ( GetCurrentCharacterID() == Characters_Gamma )
	{
		PlaySound_StandardTimer(1431, 0, 0, 0);
	}
	else
	{
		PlaySound_StandardTimer(23, 0, 0, 0);
	}
}

void DolphinSoundFix(int a1, EntityData1 *a2, int a3, int a4, int a5, EntityData1 *a6)
{
	if (FramerateSetting >= 2) PlaySound_3D_Timer_Priority(a1, a2, a3, a4, a5, a6);
	else PlaySound_3D_Timer_Priority(a1, a2, a3, a4, a5 * 2, a6);
}

void EggWalkerMissileFix(int sound_id, EntityData1 *a2, int a3, int a4, int a5, EntityData1 *a6)
{
	PlaySound_3D_Timer_Priority(sound_id, a2, a3, a4, a5, EntityData1Ptrs[0]);
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
	SoundQueue[v4].PlayTime = 40;
	SoundQueue[v4].Priority = -1;
	SoundQueue[v4].Flags = (SoundFlags)0x111;
	SoundQueue[v4].SoundID = ID;
	SoundQueue[v4].Panning = 0;
	SoundQueue[v4].CurrentVolume = -50;
	SoundQueue[v4].MaxVolume = -20;
	SoundQueue[v4].PitchShift = 0;
	SoundQueue[v4].pos.x = x;
	SoundQueue[v4].pos.y = y;
	SoundQueue[v4].pos.z = z;
	return 1;
}

int CustomSound(int ID, EntityData1 *entity, int index, int volume, int maxvolume, int length, int flags, float x, float y, float z)
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
	SoundQueue[v4].PlayTime = length;
	SoundQueue[v4].Priority = -1;
	SoundQueue[v4].Flags = flags;
	SoundQueue[v4].SoundID = ID;
	SoundQueue[v4].Panning = 0;
	SoundQueue[v4].CurrentVolume = volume;
	SoundQueue[v4].MaxVolume = maxvolume;
	SoundQueue[v4].PitchShift = 0;
	SoundQueue[v4].pos.x = x;
	SoundQueue[v4].pos.y = y;
	SoundQueue[v4].pos.z = z;
	SoundQueueOriginEntities[v4] = entity;
	return 1;
}

int QueueBullet(int sound_id, EntityData1 *entity, int min_index, int volume, float x, float y, float z)
{
	Sint32 v4; // eax
	Sint32 v6; // eax
	int v7; // ecx
	v4 = SoundQueue_GetFreeIndex(min_index);
	if (v4 < 0)
	{
		return -1;
	}
	SoundQueue[v4].SourceEntity = entity;
	SoundQueue[v4].PlayTime = 120;
	SoundQueue[v4].Priority = -1;
	SoundQueue[v4].Flags = (SoundFlags)0x111;
	SoundQueue[v4].SoundID = sound_id;
	SoundQueue[v4].Panning = 0;
	SoundQueue[v4].CurrentVolume = volume;
	SoundQueue[v4].MaxVolume = volume;
	SoundQueue[v4].PitchShift = 0;
	SoundQueue[v4].pos.x = x;
	SoundQueue[v4].pos.y = y;
	SoundQueue[v4].pos.z = z;
	return 1;
}

void DelaySound_Febjg(int sound_id, EntityData1* a2, int min_index, int volume, int PlayTime, EntityData1* a6)
{
	for (int i = 0; i < LengthOfArray(DelayedSounds); i++)
	{
		if (DelayedSounds[i].sound_id == -1)
		{
			DelayedSounds[i].sound_id = sound_id;
			DelayedSounds[i].entity1 = a2;
			DelayedSounds[i].min_index = min_index;
			DelayedSounds[i].volume = volume;
			DelayedSounds[i].PlayTime = PlayTime;
			DelayedSounds[i].is3d = true;
			DelayedSounds[i].maxvolume = (int)a6;
			DelayedSoundCount++;
			return;
		}
	}
	PlaySound_3D_Timer_Priority(sound_id, a2, min_index, volume, PlayTime, a6);
}


static void __cdecl ORraf_DrawDustEffect_r(ObjectMaster* a1);
static Trampoline ORraf_DrawDustEffect_t(0x5EBF20, 0x5EBF25, ORraf_DrawDustEffect_r);
static void __cdecl ORraf_DrawDustEffect_r(ObjectMaster* a1)
{
	auto original = reinterpret_cast<decltype(ORraf_DrawDustEffect_r)*>(ORraf_DrawDustEffect_t.Target());
	if (a1->Data1->Scale.y >= 1.0f && a1->Data1->Scale.y < 1.05f)
	{
		//PrintDebug("X: %f, Y:%f, Z:%f\n", a1->Data1->Position.x, a1->Data1->Position.y, a1->Data1->Position.z);
		if (DelayedSoundsEnabled) DelaySound_Febjg(SE_LW_POLE, a1->Data1, -1, 0, 120, a1->Data1);
		else PlaySound_3D_Timer(SE_LW_POLE, a1->Data1, -1, 0, 120, a1->Data1);
	}
	original(a1);
}

/*
void DelaySound_Ring(int ID, EntityData1* a2, int a3, int a4)
{
	for (int i = 0; i < LengthOfArray(DelayedSounds); i++)
	{
		if (DelayedSounds[i].sound_id == -1)
		{
			DelayedSounds[i].sound_id = ID;
			DelayedSounds[i].entity1 = a2;
			DelayedSounds[i].min_index = a3;
			DelayedSounds[i].volume = a4;
			DelayedSounds[i].is3d = false;
			DelayedSoundCount++;
			return;
		}
		else PlaySound_StandardTimer(ID, a2, a3, a4);
	}
}
*/

int CalculateVolume_SADXStyle(int percent, int mode)
{
	//0 for music, 1 for voices
	if (mode == 1) return 100 * (97 * percent / 100 - 100);
	else  return 100 * (89 * percent / 100 - 100);
}

void OrcaFix(SoundIDs sound_id, EntityData1* entity, int min_index, int volume, int playlength, EntityData1* a6)
{
	PlaySound_Positional_StandardTimer(sound_id, entity, 1, 120, a6->Position.x, a6->Position.y, a6->Position.z);
}

void ZeroNameSoundFix(SoundIDs ID, void* entity, int pri, int volume)
{
	if (CurrentLevel == LevelIDs_Zero) PlaySound_StandardTimer(SE_AZ_TELOP, entity, pri, volume);
	else PlaySound_StandardTimer(ID, entity, pri, volume);
}

extern "C"
{
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions &helperFunctions)
	{
		//Volume range fix/improvement
		WriteData<1>((char*)0x423C26, 0x80u); //Volume can go as low as -128
		//Enable 44100hz sounds
		WriteData((int*)0x423CD0, 44100);
		WriteData((int*)0x410561, 44100);
		//Load config stuff
		const IniFile *config = new IniFile(std::string(path) + "\\config.ini");
		BoaBoaFix = config->getBool("General", "BoaBoaFix", true);
		ClassicRingPan = config->getBool("General", "ClassicRingPan", true);
		FixSoundVolume = config->getBool("General", "FixSoundVolume", true);
		SpindashFade = config->getBool("General", "SpindashFade", true);
		DelayedSoundsEnabled = config->getBool("General", "DelayedSounds", true);
		AdvancedVolumeControl = config->getBool("Volume", "AdvancedVolumeControl", true);
		if (AdvancedVolumeControl)
		{
			MusicVolumeBoost = config->getInt("Volume", "MusicVolumeBoost", 5100);
			VoiceVolumeBoost = config->getInt("Volume", "VoiceVolumeBoost", 0);
			MovieVolumeSO = config->getInt("Volume", "MovieVolumeSO", 100);
			MusicVolumeConv = CalculateVolume_SADXStyle(GetPrivateProfileIntA("sonicDX", "bgmv", 89, ".\\sonicDX.ini"), 0) + MusicVolumeBoost;
			VoiceVolumeConv = CalculateVolume_SADXStyle(GetPrivateProfileIntA("sonicDX", "voicev", 100, ".\\sonicDX.ini"), 1) + VoiceVolumeBoost;
			MovieVolume_Real = ConvertLinearToDirectX(MovieVolumeSO, 100);
			WriteData((int**)0x005140DF, &MovieVolume_Real);
		}
		//Delayed sound effects
		if (DelayedSoundsEnabled)
		{
			WriteCall((void*)0x7A3B22, DelaySound_Febjg);
			/*WriteCall((void*)0x44FE95, DelaySound_Ring);
			WriteCall((void*)0x4501F7, DelaySound_Ring);
			WriteCall((void*)0x4504DA, DelaySound_Ring);
			WriteCall((void*)0x45051F, DelaySound_Ring);
			WriteCall((void*)0x450557, DelaySound_Ring);
			WriteCall((void*)0x614DE1, DelaySound_Ring);
			WriteCall((void*)0x61F598, DelaySound_Ring);*/
		}
		//Apply fixes
		if (BoaBoaFix) WriteCall((void*)0x79FCE4, BoaFix); //Recreate a "bug" from the DC version to make it play multiple times
		if (ClassicRingPan) WriteData((int*)0x910290, 255); //Classic 100% stereo panning for ring collect sound
		WriteData<1>((char*)0x42508D, 0x11u); //Fix for sounds playing multiple times over
		WriteCall((void*)0x57B00C, EggWalkerMissileFix); //Missing entity fix
		//Missing sound fixes
		WriteCall((void*)0x4507FA, PlayCharacterHurtVoice); //Makes Sonic and Gamma play hurt sounds
		WriteCall((void*)0x6CE25C, WhoahSomethingBuggingYou); //Load player soundbanks to play the "whoah!" voice when Knuckles attacks Sonic/Tails
		//Various sound cutoff fixes
		WriteCall((void*)0x496F33, PlaySpindash); //Spindash (fades out on DC)
		WriteCall((void*)0x5ECB4F, PlaySound_Loop); //Descending into the clouds and Go up! Full speed ahead!
		WriteData<2>((void*)0x53881F, 0x90u); //Enable ambient sound in MR Final Egg base
		WriteData<1>((char*)0x571AAF, 0x08); //Fix Egg Hornet sound loop
		WriteData<1>((char*)0x6AF86B, 0i8); //I forgot to put in the landing gear!
		WriteData<1>((char*)0x6CE07B, 0i8); //There's no landing gear in this mode!
		WriteData<1>((char*)0x6CA530, 0x34); //Goin' down! Aaaah! Look out below!
		WriteData<1>((char*)0x6E8E56, 0i8); //Tails, what am I gonna do with you?;
		WriteData<1>((char*)0x005EAE93, 0x50); //HebiGate sound fix
		WriteData<5>((char*)0x5EC440, 0x90u); //SE_LW_POLE
		WriteCall((void*)0x4FADCF, DolphinSoundFix);
		//Fixes for missing/wrong soundbanks
		SoundList_HotShelter[3].Filename = "FINAL_EGG_BANK04";
		//Fixes for wrong soundlists being loaded
		WriteData<1>((char*)0x66DC76, 111); //Gamma steals Froggy
		WriteData<1>((char*)0x6A40C8, 108); //Amy talking to Gamma (Amy's story)
		WriteData<1>((char*)0x677F8B, 108); //Amy talking to Gamma (Gamma's story)
		//Chaos 0 cutscene fix
		WriteData<1>((char*)0x006CCC1B, 0x78u); //uuuuuuoooooohhh!
		WriteCall((void*)0x6CC6E1, QueueBullet);
		WriteCall((void*)0x6CC782, QueueBullet);
		WriteCall((void*)0x6CC802, QueueBullet);
		WriteCall((void*)0x6CC885, QueueBullet);
		WriteCall((void*)0x6CC8A9, QueueBullet);
		WriteCall((void*)0x6CC8D0, QueueBullet);
		WriteCall((void*)0x6CC8F4, QueueBullet);
		WriteCall((void*)0x6CC91B, QueueBullet);
		WriteCall((void*)0x6CC93F, QueueBullet);
		WriteCall((void*)0x6CC966, QueueBullet);
		WriteCall((void*)0x6CC98A, QueueBullet);
		WriteCall((void*)0x6CC9B1, QueueBullet);
		WriteCall((void*)0x6CC9D5, QueueBullet);
		WriteCall((void*)0x6CC9FC, QueueBullet);
		WriteCall((void*)0x6CCA20, QueueBullet);
		WriteCall((void*)0x6CCA47, QueueBullet);
		//Make the orca sound 2D because it's barely audible in 3D
		WriteCall((void*)0x502D5C, OrcaFix);
		WriteCall((void*)0x502E06, OrcaFix);
		//Boss sound fixes
		WriteCall((void*)0x4B34E4, ZeroNameSoundFix);
		WriteData((short*)0x00566CC9, (short)SE_ER_ITE);
		WriteData((short*)0x00567BA3, (short)SE_ER_ELEC);
		WriteData((short*)0x005674FC, (short)SE_ER_HOVER);
		WriteData((short*)0x00566E49, (short)SE_ER_FIRE);
		WriteData((short*)0x00568744, (short)SE_ER_MOVE);
		WriteData((short*)0x005681CA, (short)SE_ER_HIT);
		WriteData((short*)0x0056816B, (short)SE_ER_HIT);
	}

		__declspec(dllexport) void __cdecl OnFrame()
	{
		auto entity = EntityData1Ptrs[0];
		bool DelayedSoundPlayed = false;
		//PrintDebug("Delayed sounds: %d\n", DelayedSoundCount);
		//Play delayed sounds one per frame
		if (DelayedSoundsEnabled && DelayedSoundCount)
		{
			for (int i = 0; i < LengthOfArray(DelayedSounds); i++)
			{
				if (!DelayedSoundPlayed && DelayedSounds[i].sound_id != -1)
				{
					if (DelayedSounds[i].is3d) PlaySound_3D_Timer_Priority(DelayedSounds[i].sound_id, DelayedSounds[i].entity1, DelayedSounds[i].min_index, DelayedSounds[i].volume, DelayedSounds[i].PlayTime, (EntityData1*)DelayedSounds[i].maxvolume);
					else PlaySound_StandardTimer(DelayedSounds[i].sound_id, DelayedSounds[i].entity1, DelayedSounds[i].min_index, DelayedSounds[i].volume);
					DelayedSoundCount--;
					DelayedSounds[i].sound_id = -1;
					DelayedSoundPlayed = true;
				}
			}
		}
		//Sound queue framerate fix
		if (FramerateSetting >= 2 && TimerValue_PlaySound_Positional_StandardTimer != 120)
		{
			WriteData((int*)0x4250AE, 120); //Fixes the PlaySound_Positional_StandardTimer function to work properly at 30 FPS
		}
		if (FramerateSetting < 2 && TimerValue_PlaySound_Positional_StandardTimer == 120)
		{
			WriteData((int*)0x4250AE, 240); //Fixes the PlaySound_Positional_StandardTimer function to work properly at 60 FPS
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
		//Sound queue fadeout
		for (int i = 0; i < 36; i++)
		{
			if (SoundQueue[i].Flags & 0x4 && SoundQueue[i].PlayTime < 110)
			{
				SoundQueue[i].CurrentVolume -= 4;
				SoundQueue[i].MaxVolume -= 4;
			}
		}
		if (!VolumeFixesApplied)
		{
			MusicVolume = MusicVolumeConv;
			VoiceVolume = VoiceVolumeConv;
			VolumeFixesApplied = true;
		}
		//PrintDebug("MusicVolume: %d \n", MusicVolume);
		//PrintDebug("MovieVolume: %d \n", MovieVolume_Real);
	}

/*	__declspec(dllexport) void __cdecl OnInput()
	{
	}
*/
	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}