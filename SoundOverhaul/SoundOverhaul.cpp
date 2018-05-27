#include <SADXModLoader.h>

FunctionPointer(Sint32, sub_424FC0, (int a1, EntityData1 *a2, int a3, int a4, float x, float y, float z), 0x424FC0);
FunctionPointer(ObjectMaster*, sub_4F5E50, (int a1), 0x4F5E50);
FunctionPointer(void, sub_4EC2E0, (ObjectMaster *), 0x4EC2E0);
FunctionPointer(void, sub_4EC310, (int a2), 0x4EC310);
FunctionPointer(ObjectMaster*, sub_64FD00, (int a1, int a2, int a3), 0x64FD00);
FunctionPointer(void, sub_42FE00, (ObjectMaster *a1, NJS_ACTION *a2, NJS_TEXLIST *a3, float a4, char a5, char a6), 0x42FE00);
FunctionPointer(void, sub_4314D0, (int a1), 0x4314D0);
DataPointer(CollisionData, stru_E94844, 0xE94844);

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

SoundFileInfo soundlist97_list[] = {
	{ 6, "E_00BF" }
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
SoundList soundlist97 = { arraylengthandptr(soundlist97_list) };

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

extern "C"
{
	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
	__declspec(dllexport) void __cdecl Init()
	{
		WriteCall((void*)0x006CE25C, WhoahSomethingBuggingYou);
		WriteCall((void*)0x00496F33, PlaySpindash);
		WriteJump((void*)0x004EC370, sub_4EC370); //Ice Cap bomber 1
		WriteCall((void*)0x004EC573, PlayBomb); //Ice Cap bomber 2
		WriteCall((void*)0x005ECB4F, PlaySound2); //Go up! Full speed ahead!
		WriteData<2>((void*)0x0053881F, 0x90u); // Enable ambient sound in MR Final Egg base
		WriteData<1>((char*)0x00571AAF, 0x08); // Fix Egg Hornet sound loop
		WriteData<1>((char*)0x006AF86B, 0i8); // I forgot to put in the landing gear!
		WriteData<1>((char*)0x006CE07B, 0i8); // There's no landing gear in this mode!
		WriteData<1>((char*)0x006CA530, 0x34); //Goin' down! Aaaah! Look out below!
		WriteCall((void*)0x006E96B9, TailsWhatAmIGonnaDoWithYou);
		*(SoundList*)0x90FDD0 = E101mkIISoundList;
		*(SoundList*)0x90FFB8 = soundlist97;
		*(SoundList*)0x90FDE0 = FinalEggSoundList;
	}
	__declspec(dllexport) void __cdecl OnFrame()
	{
		auto entity = EntityData1Ptrs[0];
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
}