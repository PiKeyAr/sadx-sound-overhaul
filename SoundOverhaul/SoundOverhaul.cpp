#include "stdafx.h"

SoundFileInfo ChaoSoundbanks[] = {
	{0, "COMMON_BANK00" },
	{1, "CHAO_EFX_BANK01" },
	{2, "CHECK_SHEET_BANK02" },
	{4, "CHAOVOICE_BANK04" },
	{5, "CHAOVOICE_BANK05" },
	{7, "ALIFE_BANK07" },
};

SoundFileInfo ChaoSoundbanks2[] = {
	{0, "COMMON_BANK00" },
	{2, "CHECK_SHEET_BANK02" },
	{4, "CHAOVOICE_BANK04" },
	{5, "CHAOVOICE_BANK05" },
	{7, "ALIFE_BANK07" },
};

SEFadeoutData FadeoutTable[] = {
	{ SE_SPINCHARGE, 110, 3 },
	{ SE_WV_WIND, 30, 4 },
	{ SE_FE_FAN, 30, 4 },
	//{ SE_PC_SS_ONWATER, 30, 3},
	//{ SE_PC_SS_ONWATER2, 30, 3},
	//{ SE_PCB_SONICUP, 80, 4 },
};

SEDistanceOverride DistanceOverrideTable[] = {
	{ SE_SHT_FLY_ENEMY, 1000.0f, 2000.0f, 0 },
	{ SE_SD_CANB_FIRE, 50.0f, 500.0f, 0 },
	{ SE_M2_B_SHOT, 20.0f, 500.0f, 0 },
	{ SE_M2_JUMP, 20.0f, 500.0f, 0 },
	{ SE_M1_JET, 20.0f, 500.0f, 0 },
	{ SE_M2_B_BOMB, 20.0f, 500.0f, 0 },
	{ SE_CS_SWIM, 20.0f, 500.0f, 0 },
	{ SE_CS_INWATER, 50.0f, 500.0f, 0 },
	{ SE_SD_CANH_FIRE, 100.0f, 1000.0f, 96 },
	{ SE_SD_CANH_FIRE, 100.0f, 1000.0f, 75 },
	{ SE_SD_CANH_ROT, 100.0f, 1000.0f, 0 },
	{ SE_M3_ENERGYSHOT, 50.0f, 500.0f, 0 },
	{ SE_M3_NEEDLEROT, 50.0f, 500.0f, 0 },
};

ChaoSoundIDOverride ChaoSoundReplacements[] = {
	{ 0x755474, SE_AL_21 }, //race cursor
	{ 0x727B49, SE_AL_KOKE },
	{ 0x727E19, SE_AL_PON },
	{ 0x728257, SE_AL_PON },
	{ 0x72829E, SE_AL_KOKE },
	{ 0x72866A, SE_AL_PON },
	{ 0x7286A4, SE_AL_KOKE },
	{ 0x72C63B, SE_AL_HIRAMEKI },
	{ 0x72C923, SE_AL_KOKE },
	{ 0x72C94E, SE_AL_HIRAMEKI },
	{ 0x72E2CE, SE_AL_START },
	{ 0x72FF94, SE_AL_CAPTURE_KYUPIN },
	{ 0x7398F5, SE_AL_CAPTURE_KYUKYU },
	{ 0x73995C, SE_AL_CAPTURE_KYUPIN },
	{ 0x73A858, SE_AL_PICK },
	{ 0x73A9AC, SE_AL_FOOTSTEP_L },
	{ 0x744095, SE_AL_SWIM },
	{ 0x74424F, SE_AL_UMARERU },
	{ 0x744381, SE_AL_PEN },
	{ 0x744365, SE_AL_PEN },
	{ 0x7443A0, SE_AL_KUJAKU },
	{ 0x7443BF, SE_AL_TUBAME },
	{ 0x7443DE, SE_AL_OUMU },
	{ 0x7443FD, SE_AL_BANBI },
	{ 0x744443, SE_AL_GORILLA },
	{ 0x74443C, SE_AL_GORILLA },
	{ 0x744486, SE_AL_LION },
	{ 0x74447F, SE_AL_LION },
	{ 0x7444A2, SE_AL_ZOU },
	{ 0x74454D, SE_AL_DOPUN },
	{ 0x745EC5, SE_AL_PON },
	{ 0x745F11, SE_AL_KOKE },
	{ 0x745EED, SE_AL_KOKE },
	{ 0x746522, SE_AL_KOKE },
	{ 0x7464F7, SE_AL_PON },
	{ 0x748FE4, SE_AL_KOKE },
	{ 0x748F9F, SE_AL_PON },
	{ 0x748FB6, SE_AL_KOKE },
	{ 0x748F6C, SE_AL_PON },
	{ 0x7484AE, SE_AL_HIRAMEKI },
	{ 0x74852D, SE_AL_KOKE },
	{ 0x74BB35, SE_AL_PON },
	{ 0x74BB97, SE_AL_KOKE },
	{ 0x74C85F, SE_AL_KOKE },
	{ 0x74C89A, SE_AL_HIRAMEKI },
	{ 0x74D8A4, SE_AL_KOKE },
	{ 0x74D8D7, SE_AL_HIRAMEKI },
	{ 0x754CD1, SE_AL_FLY },
	{ 0x754CCA, SE_AL_SWIM },
	{ 0x754CC3, SE_AL_EAT },
	{ 0x7558DF, SE_AL_PICK },
	{ 0x755961, SE_AL_RAPPA2 },
	{ 0x7559A1, SE_AL_RAPPA2 },
	{ 0x755C37, SE_AL_KOKE },
	{ 0x756432, SE_AL_UMARERU },
	{ 0x756B33, SE_AL_DOPUN }, //Wrong??
	{ 0x75AAC3, SE_AL_EAT },
	{ 0x7612F9, SE_AL_AGOGOBELL },
	{ 0x76151D, SE_AL_TAIKO },
	{ 0x761631, SE_AL_FUE },
	{ 0x7617DD, SE_AL_BONGO }, //Should've been castanets though
	{ 0x7617FB, SE_AL_BONGO }, //Should've been castanets though
	{ 0x761926, SE_AL_RAPPA2 },
	{ 0x761AB8, SE_AL_THINBAL },
	{ 0x761C36, SE_AL_TAMBOURINE },
	{ 0x7621B7, SE_AL_49 }, //Goo
	{ 0x76422C, SE_AL_PHOO },
	{ 0x76432E, SE_AL_47 }, //Fire
	{ 0x76EA5E, SE_AL_RAKUGAKI },
	{ 0x76EA5E, SE_AL_RAKUGAKI },
	//{ 0x739EA3, SE_CH_V29 },
	//{ 0x739FFF, SE_CH_V56 }, //eating normal
	//{ 0x73A031, SE_CH_V56 }, //eating hungry
	//{ 0x73A0BC, SE_CH_V56 }, //eating hungry
	//{ 0x73A08D, SE_CH_V56 }, //eating normal
};

//Config stuff
bool BoaBoaFix = true;
bool ClassicRingPan = true;
bool FadeOutEnabled = true;
bool DelayedSoundsEnabled = true;
bool ReplaceChaoSounds = true;
bool EnableChaoBGSounds = false;
int MovieVolumeSO = 100;
int MovieVolume_Real = 0;
int MusicVolumeBoost = 5100;
int VoiceVolumeBoost = 5100;

//Other stuff
bool SnowSoundFixed = false;
int MusicVolumeConv = 0;
int VoiceVolumeConv = 0;
int VolumeFixesApplied = false;
float explosiondelay = 0.2f;

int ConvertLinearToDirectX(int value, int max)
//Solution by JohnBolton, taken from https://www.gamedev.net/forums/topic/337397-sound-volume-question-directsound/?tab=comments#comment-3197281
{
	if (value <= 0)
	{
		return -10000;
	}
	else
	{
		return (int)floorf(2000.0f * log10f((float)(value) / (float)max));
	}
}

void PlaySpindash(int id, EntityData1 *Data1, int a3, EntityData1 *a4, int a5)
{
	if (CharObj2Ptrs[0])
	{
		if (!FadeOutEnabled) PlaySound_Timer(767, Data1, 1, 0, 160);
		else if (CharObj2Ptrs[0]->Upgrades & Upgrades_LightShoes) PlaySound_FadeOut(767, Data1, 1, 0, 120);
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
		PlaySound_StandardTimer(SE_EV_DAMAGE, 0, 0, 0);
	}
	else if (GetCurrentCharacterID() == Characters_Sonic)
	{
		PlaySound_StandardTimer(SE_DAMAGE2, 0, 0, 0);
	}
	else if (GetCurrentCharacterID() == Characters_Tails)
	{
		PlaySound_StandardTimer(SE_MV_DAMAGE, 0, 0, 0);
	}
	else if (GetCurrentCharacterID() == Characters_Knuckles)
	{
		PlaySound_StandardTimer(SE_KV_DAMAGE, 0, 0, 0);
	}
	else if (GetCurrentCharacterID() == Characters_Amy)
	{
		PlaySound_StandardTimer(SE_AV_DAMAGE, 0, 0, 0);
	}
	else if (GetCurrentCharacterID() == Characters_Big)
	{
		PlaySound_StandardTimer(SE_BV_DAMAGE, 0, 0, 0);
	}
	else if (GetCurrentCharacterID() == Characters_MetalSonic)
	{
		PlaySound_StandardTimer(SE_DAMAGE2, 0, 0, 0);
	}
	return;
}

void DolphinSoundFix(int a1, EntityData1 *a2, int a3, int a4, int a5, EntityData1 *a6)
{
	if (FramerateSetting >= 2) PlaySound_3D_Timer_pri(a1, a2, a3, a4, a5, a6);
	else PlaySound_3D_Timer_pri(a1, a2, a3, a4, a5 * 2, a6);
}

void EggWalkerMissileFix(int sound_id, EntityData1 *a2, int a3, int a4, int a5, EntityData1 *a6)
{
	PlaySound_3D_Timer_pri(sound_id, a2, a3, a4, a5, EntityData1Ptrs[0]);
}

static void __cdecl ORrafCylinderThing_r(ObjectMaster* a1);
static Trampoline ORrafCylinderThing_t(0x5EC280, 0x5EC286, ORrafCylinderThing_r);
static void __cdecl ORrafCylinderThing_r(ObjectMaster* a1)
{
	//PrintDebug("Status: %f\n", a1->Data1->Scale.y);
	auto original = reinterpret_cast<decltype(ORrafCylinderThing_r)*>(ORrafCylinderThing_t.Target());
	if (a1->Data1->Scale.y >= 0.35f && a1->Data1->Scale.y < 0.36f)
	{
		if (DelayedSoundsEnabled) PlaySound_Delayed(SE_LW_POLE, a1->Data1, -1, 0, 120, a1->Data1);
		else PlaySound_3D_Timer(SE_LW_POLE, a1->Data1, -1, 0, 120, a1->Data1);
	}
	original(a1);
}

int CalculateVolume_SADXStyle(int percent, int mode)
{
	//0 for music, 1 for voices
	if (mode == 1) return 100 * (97 * percent / 100 - 100);
	else return 100 * (89 * percent / 100 - 100);
}

void ZeroNameSoundFix(SoundIDs ID, void* entity, int pri, int volume)
{
	if (CurrentLevel == LevelIDs_Zero) PlaySound_StandardTimer(SE_AZ_TELOP, entity, pri, volume);
	else PlaySound_StandardTimer(ID, entity, pri, volume);
}

void SpaceshipFix(SoundIDs a1, EntityData1* entity, int pri, int volume, int playlength, EntityData1* entity_origin)
{
	PlaySound_Positional_Timer(a1, entity, pri, 100, 120, entity->Position.x, entity->Position.y, entity->Position.z);
}

void DescendingIntoTheClouds(SoundIDs ID, void* entity, int pri, int volume)
{
	if (!VoiceLanguage) PlaySound_Timer(ID - 2, entity, 2, volume, 240);
	else PlaySound_Timer(ID, entity, -1, volume, 240);
}

int KnuxGlide(SoundIDs ID, void* entity, int pri, int volume)
{
	return PlaySound_Timer(ID, entity, pri, volume, 120);
}

int PirateShipFix(SoundIDs id, EntityData1* entity, int pri, int volume, int playlength, float x, float y, float z)
{
	PlaySound_Positional_Timer(id, entity, pri, volume, playlength, entity->Position.x, entity->Position.y + 350.0f, entity->Position.z);
	return 1;
}

void CannonFix(SoundIDs a1, EntityData1* entity, int pri, int volume, int playlength, EntityData1* entity_origin)
{
	//PlaySound_3D_Timer(a1, EntityData1Ptrs[0], pri, volume, playlength, entity_origin);
	PlaySound_Positional_Timer(a1, entity_origin, pri, 105, playlength, entity_origin->Position.x, entity_origin->Position.y, entity_origin->Position.z);
}

void WormFix(SoundIDs id, EntityData1* entity, int index, int volume, int length, float multiplier, EntityData1* origin_entity)
{
	PlaySound_Positional_Timer(id, entity, index, volume, length, origin_entity->Position.x, origin_entity->Position.y, origin_entity->Position.z);
}

int PerfectChaosRoar(SoundIDs ID, void* entity, int pri, int volume)
{
	return PlaySound_Timer(ID, NULL, 0, volume, 200);
}

void GrassFix(SoundIDs sound_id, EntityData1* entity, int pri, int volume, float x, float y, float z)
{
	PlaySound_Positional_Timer(sound_id, entity, pri, volume, 120, x, y, z);
}

// char __usercall@<al>(int a1@<ecx>, int id, float x, float y, float z)
static const void* const Set3DSoundVolumePtr = (void*)0x4102C0;

static inline char Set3DSoundVolume_3(int a1, int id, float x, float y, float z)
{
	char result;
	__asm
	{
		push[z]
		push[y]
		push[x]
		push[id]
		mov ecx, [a1]
		call Set3DSoundVolumePtr
		add esp, 16
		mov result, al
	}
	return result;
}

char __cdecl Set3DSoundVolume_2(int a1, int id, float x, float y, float z)
{
	//PrintDebug("ID SND X Y Z: %d, %d, %f, %f, %f \n", id, SoundQueue[id].id, x, y, z);
	return Set3DSoundVolume_3(z, id, x, y, z);
}

static void __declspec(naked) Set3DPositionPCM_Hook()
{
	__asm
	{
		push[esp + 10h] // z
		push[esp + 10h] // y
		push[esp + 10h] // x
		push[esp + 10h] // id
		push ecx // a1

		// Call your __cdecl function here:
		call Set3DSoundVolume_2

		pop ecx // a1
		add esp, 4 // id
		add esp, 4 // x
		add esp, 4 // y
		add esp, 4 // z
		retn
	}
}

void __cdecl lsndVolume(int volume, int queue_id)
{
	int flags; // ecx
	int volume_conv; // esi
	flags = SoundQueue[queue_id].flags;
	if (volume > -100)
	{
		if (SoundQueue[queue_id].pri == 8) volume_conv = ConvertLinearToDirectX(200, 227);
		else volume_conv = ConvertLinearToDirectX(min(volume, 127) + 100, 227);//2 * (5 * volume - 640); //
	}
	else
	{
		volume_conv = -10000;
		if (flags & SoundFlags_3D)
		{
			Set3DSoundVolume_2(flags, queue_id, 0.0f, 5000.0f, 0.0f);
			Critical_SetSoundVolume(queue_id, -10000);
			return;
		}
		if (flags & SoundFlags_Fadeout)
		{
			SoundQueue[queue_id].flags &= ~SoundFlags_Fadeout;
			SoundQueue[queue_id].timer = 1;
		}
		//PrintDebug("lsndVolume: id %d, muted\n", queue_id);
	}
	//PrintDebug("lsndVolume: id %d, volume %d, dsound: %d\n", queue_id, volume, volume_conv);
	Critical_SetSoundVolume(queue_id, volume_conv);
}

void UnpauseSound_Fixed(int queue_id, int volume_unconv)
{
	int flags;
	int conv_volume;
	int volume_conv;
	//Unconvert SADX volume
	if (volume_unconv == -10000) conv_volume = -100; else conv_volume = ((volume_unconv / 2) + 640) / 5;
	flags = SoundQueue[queue_id].flags;
	if (conv_volume > -100)
	{
		if (SoundQueue[queue_id].pri == 8) volume_conv = ConvertLinearToDirectX(200, 227);
		else volume_conv = ConvertLinearToDirectX(min(conv_volume, 127) + 100, 227);//2 * (5 * volume - 640); //
	}
	else
	{
		volume_conv = -10000;
		if (flags & SoundFlags_3D)
		{
			Set3DSoundVolume_2(flags, queue_id, 0.0f, 5000.0f, 0.0f);
			Critical_SetSoundVolume(queue_id, -10000);
			//PrintDebug("Unpausing sound: id %d, muted\n", queue_id);
			return;
		}
		if (flags & SoundFlags_Fadeout)
		{
			SoundQueue[queue_id].flags &= ~SoundFlags_Fadeout;
			SoundQueue[queue_id].timer = 1;
		}
	}
	//PrintDebug("Unpausing sound: id %d, volume %d, dsound: %d\n", queue_id, conv_volume, volume_conv);
	Critical_SetSoundVolume(queue_id, volume_conv);
}

bool Set3DMinMaxPCM_Hook(int id, float dist_min, float dist_max)
{
	float volume_scale = 1.0f;
	int volume_dist = 0; 
	for (int i = 0; i < LengthOfArray(DistanceOverrideTable); i++)
	{
		
		if (DistanceOverrideTable[i].ID == SoundQueue[id].id && (!DistanceOverrideTable[i].volume || DistanceOverrideTable[i].volume == SoundQueue[id].volume))
		{
			dist_min = DistanceOverrideTable[i].dist_min;
			dist_max = DistanceOverrideTable[i].dist_max;
			//PrintDebug("Distance override: ID %d, min %f, max %f\n", id, dist_min, dist_max);
			return Set3DMinMaxPCM(id, dist_min, dist_max);
		}
	}
	//PrintDebug("Distance: %d, %f, %f\n", id, dist_min, dist_max);
	return Set3DMinMaxPCM(id, dist_min, dist_max);
}

void SoundFade_Apply(int queue_id)
{
	for (int i = 0; i < LengthOfArray(FadeoutTable); i++)
	{
		if (FadeoutTable[i].ID == SoundQueue[queue_id].id)
		{
			if (FadeoutTable[i].start >= SoundQueue[queue_id].timer)
			{
				SoundQueue[queue_id].volume -= FadeoutTable[i].speed;
			}
			if (SoundQueue[queue_id].volume <= -127) StopSound(queue_id);
			return;
		}
	}
	SoundQueue[queue_id].volume -= 4;
	if (SoundQueue[queue_id].volume <= -127) StopSound(queue_id);
	//PrintDebug("Def");
}

void SoundFade()
{
	bool sounddone = false;
	for (int q = 0; q < 36; q++)
	{
		if (!EV_MainThread_ptr && SoundQueue[q].volume)
		{
			if (!(SoundQueue[q].flags & SoundFlags_VolumeManual) && !(SoundQueue[q].flags & SoundFlags_VolumeDist))
			{
				SoundQueue[q].flags |= SoundFlags_VolumeManual;
			}
		}
		if (SoundQueue[q].flags & SoundFlags_Fadeout)
		{
			SoundFade_Apply(q);
		}
	}
}

void PlaySound_Delayed_Rock(int sound_id, EntityData1* a2, int min_index, int volume, int timer, EntityData1* a6)
{
	PlaySound_Delayed(sound_id, a2, min_index, volume, timer + 120, a6);
}

void TailsWhatAmIGonnaDoWithYou()
{
	Cutscene_PlaySoundWithPitch(0, 1335, 1800);
}

void UhhhhaaaAughh(int a1)
{
	if (VoiceLanguage) Cutscene_Voice(472);
	Cutscene_WaitForInput(a1);
}

void UhhhhaaaAughh2(int a1)
{
	if (!VoiceLanguage) Cutscene_Voice(472);
}

int Pitch1(int queue_id, int pitch, int length)
{
	return Cutscene_SetSoundPitch(queue_id, 30000, length);
}

int Pitch2(int queue_id, int pitch, int length)
{
	return Cutscene_SetSoundPitch(queue_id, -25000, length);
}

void SwingingSpikeBallFix(SoundIDs a1, EntityData1* entity, int pri, int volume, int playlength, EntityData1* entity_origin)
{
	int v6 = SoundQueue_GetOtherThing(a1, entity);
	if (v6 == -1) PlaySound_Delayed(a1, entity, pri, volume, 130, entity_origin);
}

signed int PerfectChaosFix(SoundIDs sound_id, EntityData1* entity, int pri, int volume)
{
	return PlaySound_Timer(sound_id, entity, pri, volume, 600);
}

static void __cdecl MRGarden_Main_r(ObjectMaster* a1);
static Trampoline MRGarden_Main_t(0x718C30, 0x718C35, MRGarden_Main_r);
static void __cdecl MRGarden_Main_r(ObjectMaster* a1)
{
	auto original = reinterpret_cast<decltype(MRGarden_Main_r)*>(MRGarden_Main_t.Target());
	if (EnableChaoBGSounds)
	{
		PlaySound_Timer(SE_CH_BEACH, a1->Data1, 8, 100, 100); //Mushi
		a1->Data1->Position = { 31.5f, 18.0f, -101.25f };
		PlaySound_Positional_Timer(SE_CH_SPRING, a1->Data1, 0, 0, 100, 31.5f, 18.0f, -101.25f);
	}
	original(a1);
}

static void __cdecl ECGarden_Main_r(ObjectMaster* a1);
static Trampoline ECGarden_Main_t(0x718FD0, 0x718FD5, ECGarden_Main_r);
static void __cdecl ECGarden_Main_r(ObjectMaster* a1)
{
	auto original = reinterpret_cast<decltype(ECGarden_Main_r)*>(ECGarden_Main_t.Target());
	if (EnableChaoBGSounds)
	{
		PlaySound_Timer(SE_CH_HOGE7, a1->Data1, 8, 100, 100); //Beach
		a1->Data1->Position = { -33.75f, 59.625f, 7.875f };
		PlaySound_Positional_Timer(SE_CH_HOGE6, a1->Data1, 0, 0, 100, -33.75f, 59.625f, 7.875f); //Radar
	}
	original(a1);
}

void PlayChaoRaceCheer(MusicIDs id)
{
	if (CurrentSong != id)
	{
		if (Music_Enabled)
		{
			CurrentSong = id;
			LastSong2 = id;
			LastSong = id;
		}
	}
	PlaySound_Timer(SE_CH_HOGE5, NULL, 8, 100, 1000);
}

void GammaTargetPositional(SoundIDs ID, EntityData1* entity, int pri, int volume)
{
	PlaySound_Positional_StandardTimer(ID, entity, pri, -50, EntityData1Ptrs[0]->Position.x, EntityData1Ptrs[0]->Position.y, EntityData1Ptrs[0]->Position.z);
}

extern "C"
{
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions &helperFunctions)
	{
		if (GetModuleHandle(L"SoundOverhaul") != nullptr)
		{
			MessageBox(WindowHandle,
				L"Please enable only one version of Sound Overhaul at a time. The mod will not work.",
				L"Sound Overhaul error: Incompatible mods detected", MB_OK | MB_ICONERROR);
			return;
		}
		//Config stuff
		const IniFile* config = new IniFile(std::string(path) + "\\config.ini");
		BoaBoaFix = config->getBool("General", "BoaBoaFix", true);
		ClassicRingPan = config->getBool("General", "ClassicRingPan", true);
		FadeOutEnabled = config->getBool("General", "FadeOutEnabled", true);
		ReplaceChaoSounds = config->getBool("General", "ReplaceChaoSounds", true);
		EnableChaoBGSounds = config->getBool("General", "EnableChaoBGSounds", false);
		DelayedSoundsEnabled = config->getBool("General", "DelayedSounds", true);
		MusicVolumeBoost = config->getInt("Volume", "MusicVolumeBoost", 5100);
		VoiceVolumeBoost = config->getInt("Volume", "VoiceVolumeBoost", 5100);
		MovieVolumeSO = config->getInt("Volume", "MovieVolumeSO", 100);
		MusicVolumeConv = CalculateVolume_SADXStyle(GetPrivateProfileIntA("sonicDX", "bgmv", 89, ".\\sonicDX.ini"), 0) + MusicVolumeBoost;
		VoiceVolumeConv = CalculateVolume_SADXStyle(GetPrivateProfileIntA("sonicDX", "voicev", 100, ".\\sonicDX.ini"), 1) + VoiceVolumeBoost;
		MovieVolume_Real = ConvertLinearToDirectX(MovieVolumeSO, 100);
		WriteData((int**)0x005140DF, &MovieVolume_Real);
		//Chao stuff
		if (ReplaceChaoSounds)
		{
			ChaoSoundbanks[1].Filename = "ALIFE_BANK01";
			//ChaoSoundbanks[3].Filename = "ALIFE_BANK05"; //the first voice bank (bank 4 in DX) is replaced with background sounds (bank 5 on DC)
			//ChaoSoundbanks[4].Filename = "ALIFE_BANK04"; //the second voice bank (bank 5 in DX) is replaced with SA1 voices (bank 4 on DC)
			//ChaoSoundbanks2[2].Filename = "ALIFE_BANK05";
			//ChaoSoundbanks2[3].Filename = "ALIFE_BANK04";
			SoundLists[61].List = ChaoSoundbanks;
			SoundLists[61].Count = 6;
			SoundLists[2].List = ChaoSoundbanks2; //Might be unused
			SoundLists[2].Count = 5;
			for (int i = 0; i < LengthOfArray(ChaoSoundReplacements); i++)
			{
				WriteData((__int16*)(ChaoSoundReplacements[i].address+1), ChaoSoundReplacements[i].id);
			}
			WriteData((__int16*)0x72FDBA, (__int16)SE_AL_TAIKO);
			WriteData((__int16*)0x72FDC3, (__int16)SE_AL_RAPPA);
			WriteData((__int16*)0x72FDCC, (__int16)SE_AL_FUE);
			WriteData((__int16*)0x72FDD5, (__int16)SE_AL_THINBAL);
			WriteData((__int16*)0x72FDDE, (__int16)SE_AL_AGOGOBELL);
			WriteData((__int16*)0x72FDE7, (__int16)SE_AL_TAMBOURINE);
			WriteData((__int16*)0x72FDF0, (__int16)SE_AL_BONGO);
			WriteData((__int16*)0x72FDF9, (__int16)SE_AL_SUZU);
		}
		WriteCall((void*)0x72E618, PlayChaoRaceCheer);
		//General changes
		WriteData((void**)0x410AE8, (void*)0x88AC34); //Enable full HRTF mode
		WriteData((void**)0x410CBC, (void*)0x88AC34); //Enable full HRTF mode
		WriteData((int*)0x423CD0, 44100); //Enable 44100hz sounds
		WriteData((int*)0x410561, 44100); //Enable 44100hz sounds
		WriteData<1>((char*)0x42508D, 0x11u); //Fix for sounds playing multiple times over
		if (ClassicRingPan) WriteData((int*)0x910290, 255); //Classic 100% stereo pan for ring collect sound
		//Volume stuff
		WriteJump((void*)0x423C20, lsndVolume); //Calculate sound volume (logarithmic)
		WriteCall((void*)0x4243D7, UnpauseSound_Fixed); //Same as above
		WriteCall((void*)0x4251F8, Set3DMinMaxPCM_Hook); //Distance override for 3D sounds
		//WriteCall((void*)0x424BF2, Set3DPositionPCM_Hook); //Position override for 3D sounds
		//Delayed sound effects
		if (DelayedSoundsEnabled)
		{
			WriteCall((void*)0x604189, PlaySound_Delayed_Rock); //Red Mountain rocks
			WriteCall((void*)0x7A3B22, PlaySound_Delayed); //OFeBjg
			WriteCall((void*)0x47AE23, PlaySound_StandardTimer_Delay); //Knuckles' Maximum Heat release
			WriteCall((void*)0x4CAF88, PlaySound_StandardTimer_Delay); //Explosion in Sky Deck
			WriteCall((void*)0x5B57D8, PlaySound_Delayed); //Final Egg targets
			WriteCall((void*)0x7A3616, SwingingSpikeBallFix); //Swinging spike balls
			WriteCall((void*)0x62E821, PlaySound_StandardTimer_Delay); //Sky Chase final boss missiles
		}
		//Apply fixes
		if (BoaBoaFix)
		{
			WriteCall((void*)0x79FCE4, PlaySound_XYZ_IgnoreDuplicates); //Boa-Boa
			WriteData<1>((char*)0x0079FCDA, 0xE0); //Volume for Boa sound
			WriteCall((void*)0x5E7316, PlaySound_XYZ_IgnoreDuplicates); //Lost World fire traps
			WriteData<1>((char*)0x5E730C, 0xE2); //Volume for fire traps
			WriteCall((void*)0x4EC573, PlaySound_XYZ_IgnoreDuplicates); //Ice Cap bomb toss
			WriteCall((void*)0x4EC3A1, PlaySound_XYZ_IgnoreDuplicates); //Ice Cap bomb explosion
		}
		WriteCall((void*)0x496F33, PlaySpindash); //Spindash (fades out on DC)
		if (FadeOutEnabled)
		{
			WriteCall((void*)0x4788A5, StopSound_Fade); //Knuckles' glide sound
			WriteCall((void*)0x46952F, StopSound_Fade); //Lost World mirror room
			WriteCall((void*)0x5E2ACD, StopSound_Fade); //Lost World mirror room 2
			WriteCall((void*)0x561DEA, StopSound_Fade); //Perfect Chaos emerging
			WriteCall((void*)0x561F14, StopSound_Fade); //Perfect Chaos sinking
			WriteCall((void*)0x561E28, PerfectChaosFix); //Emerging
			WriteCall((void*)0x561F7D, PerfectChaosFix); //Sinking
			//WriteCall((void*)0x55EF45, StopSound_Fade); //Fade out Super Sonic's on water sound 1
			//WriteCall((void*)0x55EF8E, StopSound_Fade); //Fade out Super Sonic's on water sound 1
		}
		//Various looping/timing/cutoff fixes
		WriteData<1>((char*)0x621770, 2); // Prevent the Merry-Go-Round sound from being cut off by 3D sounds
		WriteCall((void*)0x4E26D9, PlaySound_StandardTimer_Delay); //Gamma destroying bridge in Windy Valley
		WriteCall((void*)0x561A36, PerfectChaosRoar);
		WriteCall((void*)0x561FE7, PerfectChaosRoar);
		WriteCall((void*)0x562067, PerfectChaosRoar);
		WriteData((float**)0x4E8B86, &explosiondelay); //Explosions after defeating E-series robots
		WriteCall((void*)0x538304, GrassFix); //Rustling grass
		WriteCall((void*)0x47F66D, PlaySound_Loop); //E102 jet sound loop
		WriteCall((void*)0x47F732, PlaySound_Loop); //E102 jet sound loop
		WriteCall((void*)0x47FCCA, PlaySound_Loop); //E102 jet sound loop (land)
		WriteData<1>((char*)0x47F665, 0x01u); //Jet sound priority
		WriteData<1>((char*)0x47F72A, 0x01u); //Jet sound priority
		WriteData<1>((char*)0x47FCC2, 0x01u); //Jet sound priority (land)
		WriteCall((void*)0x478AEB, KnuxGlide); //Knuckles' glide proper loop
		WriteData<1>((char*)0x4DF112, 0x79u); //Windy Valley wind path
		WriteData<1>((char*)0x61B790, 0x60u); //Speed Highway fountain jump
		WriteData<1>((char*)0x5FC50A, 0x4Bu); //Sky Deck big cannon fire delay
		WriteData<1>((char*)0x5F3DB7, 0x4Bu); //Sky Deck big cannon fire delay
		WriteCall((void*)0x5F5FAF, AlarmFix); //Alarm in Sky Deck 2
		WriteCall((void*)0x4C4E5B, GammaTargetPositional); //Make Gamma's target sound positional
		WriteCall((void*)0x55BEC7, FreezerFix); //Chaos 6 freezer
		WriteData<1>((char*)0x5B7518, 0x30u); //Final Egg 3 fan timer
		WriteCall((void*)0x5568B1, StopSound_Fade); //Chaos 4 attack
		WriteCall((void*)0x556845, PlaySound_StandardTimer); //Chaos 4 attack remove loop
		WriteCall((void*)0x5ECB4F, DescendingIntoTheClouds); //Descending into the clouds and Go up! Full speed ahead!
		WriteData<1>((char*)0x571AAF, 0x08); //Fix Egg Hornet sound loop
		WriteCall((void*)0x4FADCF, DolphinSoundFix); //Framerate
		//Volume fixes
		WriteData<1>((char*)0x62B657, 0x78u); //SE_SHT_EMCCHARGE
		WriteData<1>((char*)0x62B670, 0x78u); //SE_SHT_EMCFIRE
		WriteData<1>((char*)0x62B670, 0x78u); //SE_SHT_EMCOPEN 1
		WriteData<1>((char*)0x62B170, 0x78u); //SE_SHT_EMCOPEN 1
		WriteData<1>((char*)0x62B760, 0x78u); //SE_SHT_EMCOPEN 1
		WriteData<1>((char*)0x62AF71, 0x78u); //SE_SHT_EMCSTOP 1
		WriteData<1>((char*)0x62B195, 0x78u); //SE_SHT_EMCSTOP 2
		WriteData<1>((char*)0x62B7A2, 0x78u); //SE_SHT_EMCSTOP 3
		WriteCall((void*)0x57B00C, EggWalkerMissileFix); //Missing entity fix
		WriteCall((void*)0x79B8A0, SpaceshipFix); //Twinkle Park spaceship too quiet
		WriteCall((void*)0x5F0236, CannonFix); //Sky Deck Act 2 cannon background noise
		WriteCall((void*)0x620FA0, PirateShipFix); //Pirate ships in Twinkle Park
		WriteCall((void*)0x599A7B, WormFix); //Sand Hill worm
		//Missing sound fixes
		WriteCall((void*)0x4507FA, PlayCharacterHurtVoice); //Play hurt voices
		WriteData<2>((void*)0x53881F, 0x90u); //Enable ambient sound in MR Final Egg base
		WriteData<1>((char*)0x5EAE93, 0x50); //HebiGate sound fix
		WriteData<5>((char*)0x5EC440, 0x90u); //Remove SE_LW_POLE sound
		//Fixes for missing/wrong soundbanks
		SoundList_HotShelter[3].Filename = "FINAL_EGG_BANK04";
		WriteCall((void*)0x4B34E4, ZeroNameSoundFix);
		WriteData((short*)0x00566CC9, (short)SE_ER_ITE); //E101 boss
		WriteData((short*)0x00567BA3, (short)SE_ER_ELEC); //E101 boss
		WriteData((short*)0x005674FC, (short)SE_ER_HOVER); //E101 boss
		WriteData((short*)0x00566E49, (short)SE_ER_FIRE); //E101 boss
		WriteData((short*)0x00568744, (short)SE_ER_MOVE); //E101 boss
		WriteData((short*)0x005681CA, (short)SE_ER_HIT); //E101 boss
		WriteData((short*)0x0056816B, (short)SE_ER_HIT); //E101 boss
		//Cutscene-related fixes
		WriteCall((void*)0x6CE25C, WhoahSomethingBuggingYou); //Load player soundbanks to play the "whoah!" voice when Knuckles attacks Sonic/Tails
		WriteData<1>((char*)0x6AF86B, 0i8); //I forgot to put in the landing gear!
		WriteData<1>((char*)0x6CE07B, 0i8); //There's no landing gear in this mode!
		WriteData<1>((char*)0x6CA530, 0x34); //Goin' down! Aaaah! Look out below!
		WriteData<1>((char*)0x6CA54F, 0x78u); //Look out below timer
		WriteCall((void*)0x6E96B9, TailsWhatAmIGonnaDoWithYou); //Tails, what am I gonna do with you?
		WriteData<1>((char*)0x66DC76, 111); //Gamma steals Froggy soundlist
		WriteData<1>((char*)0x6A40C8, 108); //Amy talking to Gamma (Amy's story) soundlist
		WriteData<1>((char*)0x677F8B, 108); //Amy talking to Gamma (Gamma's story) soundlist
		WriteData<1>((char*)0x006CCC1B, 0x78u); //Chaos 0 uuuuuuoooooohhh!
		WriteCall((void*)0x6CC6E1, QueueBullet); //Chaos 0 
		WriteCall((void*)0x6CC782, QueueBullet); //Chaos 0 
		WriteCall((void*)0x6CC802, QueueBullet); //Chaos 0 
		WriteCall((void*)0x6CC885, QueueBullet); //Chaos 0 
		WriteCall((void*)0x6CC8A9, QueueBullet); //Chaos 0 
		WriteCall((void*)0x6CC8D0, QueueBullet); //Chaos 0 
		WriteCall((void*)0x6CC8F4, QueueBullet); //Chaos 0 
		WriteCall((void*)0x6CC91B, QueueBullet); //Chaos 0 
		WriteCall((void*)0x6CC93F, QueueBullet); //Chaos 0 
		WriteCall((void*)0x6CC966, QueueBullet); //Chaos 0 
		WriteCall((void*)0x6CC98A, QueueBullet); //Chaos 0 
		WriteCall((void*)0x6CC9B1, QueueBullet); //Chaos 0 
		WriteCall((void*)0x6CC9D5, QueueBullet); //Chaos 0 
		WriteCall((void*)0x6CC9FC, QueueBullet); //Chaos 0 
		WriteCall((void*)0x6CCA20, QueueBullet); //Chaos 0 
		WriteCall((void*)0x6CCA47, QueueBullet); //Chaos 0 
		//Pitch fixes
		WriteCall((void*)0x6DEC13, Pitch1); //Sonic after Sky Chase
		WriteCall((void*)0x6DEC39, Pitch2); //Sonic after Sky Chase
		WriteCall((void*)0x6DED88, Pitch1); //Sonic after Sky Chase
		WriteCall((void*)0x6DED9D, Pitch2); //Sonic after Sky Chase
		WriteCall((void*)0x69B3BD, Pitch1); //Amy Final Egg
		WriteCall((void*)0x69B3DD, Pitch2); //Amy Final Egg
		//Timing fixes for voices
		WriteCall((void*)0x6E17FD, UhhhhaaaAughh2); //Sonic bumps into Knuckles
		WriteCall((void*)0x6E10CD, UhhhhaaaAughh); //Sonic bumps into Knuckles
		//SkyboxObjects[0] = Load3DSoundTest; //3D sound test in Hedgehog Hammer

	}

	__declspec(dllexport) void __cdecl OnFrame()
	{
		auto entity = EntityData1Ptrs[0];
		bool DelayedSoundPlayed = false;
		if (entity && !EV_MainThread_ptr)
		{
			if (CurrentCharacter == Characters_Gamma && EntityData1Ptrs[0]->Action != 31) StopSound(SE_E_RDUSH);
		}
		//PrintDebug("Delayed sounds: %d\n", DelayedSoundCount);
		//Play delayed sounds one per frame
		if (DelayedSoundsEnabled && DelayedSoundCount)
		{
			for (int i = 0; i < 20; i++)
			{
				if (!DelayedSoundPlayed && DelayedSounds[i].sound_id != -1)
				{
					if (DelayedSounds[i].is3d)
					{
						if (DelayedSounds[i].sound_id == SE_C_IRONSPIN) PlaySound_3D_Timer(DelayedSounds[i].sound_id, DelayedSounds[i].entity1, DelayedSounds[i].min_index, DelayedSounds[i].volume, DelayedSounds[i].timer, (EntityData1*)DelayedSounds[i].volume_max);
						else PlaySound_3D_Timer_pri(DelayedSounds[i].sound_id, DelayedSounds[i].entity1, DelayedSounds[i].min_index, DelayedSounds[i].volume, DelayedSounds[i].timer, (EntityData1*)DelayedSounds[i].volume_max);
					}
					else PlaySound_StandardTimer(DelayedSounds[i].sound_id, DelayedSounds[i].entity1, DelayedSounds[i].min_index, DelayedSounds[i].volume);
					DelayedSoundCount--;
					DelayedSounds[i].sound_id = -1;
					DelayedSoundPlayed = true;
				}
			}
		}
		//Fadeout
		SoundFade();
		//Framerate fix for standard timer
		if (FramerateSetting >= 2 && TimerValue_PlaySound_Positional_StandardTimer != 120)
		{
			WriteData((int*)0x4250AE, 120);
		}
		if (FramerateSetting < 2 && TimerValue_PlaySound_Positional_StandardTimer == 120)
		{
			WriteData((int*)0x4250AE, 240);
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
		if (!VolumeFixesApplied)
		{
			MusicVolume = MusicVolumeConv;
			VoiceVolume = VoiceVolumeConv; 
			VoiceVolumeBK = VoiceVolumeConv;
			VolumeFixesApplied = true;
		}
		//PrintDebug("VoiceVolume: %d \n", VoiceVolume);
		//PrintDebug("MusicVolume: %d \n", MusicVolume);
		//PrintDebug("MovieVolume: %d \n", MovieVolume_Real);
	}
	/*
	__declspec(dllexport) void __cdecl OnInput()
	{
	}
	*/
	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}

/*
//Reimplementation of dsGetVolume
int dsGetVolume(int id)
{
	double xdist; // st7
	double ydist; // st6
	double zdist; // st5
	double dist; // st4
	int vol_add; // rax
	double dist_srqt; // st7
	int result; // eax

	if (Camera_Data1
		&& (xdist = SoundQueue[id].pos.x - Camera_Data1->Position.x,
			ydist = SoundQueue[id].pos.y - Camera_Data1->Position.y,
			zdist = SoundQueue[id].pos.z - Camera_Data1->Position.z,
			dist = zdist * zdist + ydist * ydist + xdist * xdist,
			dist >= 400.0))
	{
		dist_srqt = (squareroot(dist) - 20.0f) * 0.0017241379f;
		if (dist_srqt < 0.0f)
		{
			dist_srqt = 0.0f;
		}
		vol_add = int(dist_srqt * -127.0f);
	}
	else
	{
		vol_add = 0;
	}
	result = SoundQueue[id].volume + vol_add;
	if (result < -127)
	{
		result = -127;
	}
	if (result > SoundQueue[id].volume_max)
	{
		result = SoundQueue[id].volume_max;
	}
	//PrintDebug("dsGetVolume id %d, volume %d\n", id, result);
	return result;
}
*/