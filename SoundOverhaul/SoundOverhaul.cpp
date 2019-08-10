#include <SADXModLoader.h>

FunctionPointer(Sint32, sub_424FC0, (int a1, EntityData1 *a2, int a3, int a4, float x, float y, float z), 0x424FC0);
FunctionPointer(ObjectMaster*, sub_4F5E50, (int a1), 0x4F5E50);
FunctionPointer(void, sub_4EC2E0, (ObjectMaster *), 0x4EC2E0);
FunctionPointer(void, sub_4EC310, (int a2), 0x4EC310);
FunctionPointer(ObjectMaster*, sub_64FD00, (int a1, int a2, int a3), 0x64FD00);
FunctionPointer(void, sub_42FE00, (ObjectMaster *a1, NJS_ACTION *a2, NJS_TEXLIST *a3, float a4, char a5, char a6), 0x42FE00);
FunctionPointer(void, sub_4314D0, (int a1), 0x4314D0);
FunctionPointer(void, OErupt_PlaySound, (int a1, int a2, int a3, int a4, int a5, EntityData1 *a6), 0x424880);

DataPointer(CollisionData, stru_E94844, 0xE94844);
DataPointer(int, FramerateSetting_Config, 0x0089295C);
DataPointer(int, FramerateSetting, 0x0389D7DC);
DataPointer(int, SoundQueueThing, 0x004250AE);
static bool SnowSoundFixed = false;

void __cdecl sub_4EC370(ObjectMaster *a1) //Ice Cap bomber
{
	EntityData1 *v1; // esi@1

	v1 = a1->Data1;
	if (v1->Position.y <= (double)*(float *)&v1->CharIndex)
	{
		PlaySound(233, 0, 0, 0);
		sub_4F5E50((int)&v1->Position);
		RumbleA(0, 0);
		*(short*)&v1->Object = 40;
		Collision_Init(a1, &stru_E94844, 1, 4u);
		a1->MainSub = sub_4EC2E0;
		a1->DisplaySub = 0;
	}
	sub_4EC310((int)a1);
	v1->Position.y = v1->Position.y - 10.0;
}

void PlayBomb()
{
	PlaySound(232, 0, 0, 0);
}

void PlaySpindash(int id, EntityData1 *Data1, int a3, EntityData1 *a4, int a5)
{
	QueueSound_DualEntity(767, Data1, 1, 0, 160);
}

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

void TailsWhatAmIGonnaDoWithYou()
{
	sub_64FD00(0, 1335, 1800);
}

SoundList FinalEggSoundList = { arraylengthandptr(FinalEggSoundList_list) };
SoundList E101mkIISoundList = { arraylengthandptr(E101mkIISoundList_list) };

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

void DolphinSoundFix(int a1, int a2, int a3, int a4, int a5, EntityData1 *a6)
{
	if (FramerateSetting >= 2) OErupt_PlaySound(a1, a2, a3, a4, a5, a6);
	else OErupt_PlaySound(a1, a2, a3, a4, a5 * 2, a6);
}

extern "C"
{
	__declspec(dllexport) void __cdecl Init()
	{
		//Missing sound fixes
		WriteCall((void*)0x004507FA, PlayCharacterHurtVoice); //Makes Sonic and Gamma play hurt sounds
		WriteCall((void*)0x006CE25C, WhoahSomethingBuggingYou); //Load the player soundbanks to play the "whoah!" voice when Knuckles attacks Sonic/Tails
		//Various sound cutoff fixes
		WriteCall((void*)0x00496F33, PlaySpindash); //Prevent the cutoff of the spindash (supposed to fade out but it's broken in SADX)
		WriteJump((void*)0x004EC370, sub_4EC370); //Ice Cap bomber 1
		WriteCall((void*)0x004EC573, PlayBomb); //Ice Cap bomber 2
		WriteCall((void*)0x005ECB4F, PlaySound2); //Go up! Full speed ahead!
		WriteData<2>((void*)0x0053881F, 0x90u); //Enable ambient sound in MR Final Egg base
		WriteData<1>((char*)0x00571AAF, 0x08); //Fix Egg Hornet sound loop
		WriteData<1>((char*)0x006AF86B, 0i8); //I forgot to put in the landing gear!
		WriteData<1>((char*)0x006CE07B, 0i8); //There's no landing gear in this mode!
		WriteData<1>((char*)0x006CA530, 0x34); //Goin' down! Aaaah! Look out below!
		WriteCall((void*)0x006E96B9, TailsWhatAmIGonnaDoWithYou);
		WriteCall((void*)0x004FADCF, DolphinSoundFix);
		//Missing soundbank sounds fixes
		SoundLists[35] = E101mkIISoundList;
		SoundLists[37] = FinalEggSoundList; //Final Egg
		//Cutscene soundbank fixes
		WriteData<1>((char*)0x0066DC76, 111); //Gamma steals Froggy
		WriteData<1>((char*)0x006A40C8, 108); //Amy talking to Gamma (Amy's story)
		WriteData<1>((char*)0x00677F8B, 108); //Amy talking to Gamma (Gamma's story)
	}

	__declspec(dllexport) void __cdecl OnFrame()
	{
		auto entity = EntityData1Ptrs[0];
		//Sound queue framerate fix
		if (FramerateSetting >= 2 && SoundQueueThing != 120)
		{
			WriteData((int*)0x004250AE, 120); //Fixes the QueueSoundAtPosition function to work properly at 60 FPS
		}
		if (FramerateSetting < 2 && SoundQueueThing == 120)
		{
			WriteData((int*)0x004250AE, 240); //Fixes the QueueSoundAtPosition function to work properly at 60 FPS
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