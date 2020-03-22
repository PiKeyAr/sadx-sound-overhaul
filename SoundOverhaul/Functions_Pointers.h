#pragma once

extern int DelayedSoundCount;
extern MiniSoundQueue DelayedSounds[];

DataPointer(int, FramerateSetting_Config, 0x0089295C);
DataPointer(int, FramerateSetting, 0x0389D7DC);
DataPointer(int, TimerValue_PlaySound_Positional_StandardTimer, 0x004250AE);
DataPointer(int, VoiceVolumeBK, 0x3ABDF90);
DataArray(SoundEntry, SoundQueue, 0x3B292F8, 36);
FunctionPointer(ObjectMaster*, Cutscene_PlaySoundWithPitch, (int a1, int a2, int a3), 0x64FD00);
FunctionPointer(int, StopSound, (int id), 0x424210);
FunctionPointer(int, EnableEntityVolumeControl, (EntityData1* a1, int a2), 0x424270);
FunctionPointer(void, Cutscene_WaitForInput, (int a1), 0x4314D0);
FunctionPointer(void, Cutscene_Voice, (int a1), 0x431930);
FunctionPointer(int, Cutscene_SetSoundPitch, (int queue_id, int pitch, int length), 0x64FDE0);
FunctionPointer(void, Critical_SetSoundVolume, (int id, int volume), 0x4101A0);
FunctionPointer(bool, Set3DMinMaxPCM, (int a1, float a2, float a3), 0x4103B0);
DataArray(SoundFileInfo, SoundList_HotShelter, 0x90F8F0, 5);

//PlaySound-like functions
//Standard
FunctionPointer(int, PlaySound_StandardTimer, (int ID, void* entity, int pri, int volume), 0x423D70);
FunctionPointer(int, PlaySound_Loop, (int ID, void* entity, int pri, int volume), 0x423E20);
FunctionPointer(Sint32, PlaySound_Timer, (int ID, void* entity, int pri, int volume, int playlength), 0x423F50);
//Positional
FunctionPointer(void, PlaySound_Positional_Timer, (int ID, EntityData1* entity, int pri, int volume, int length, float x, float y, float z), 0x424000);
FunctionPointer(void, PlaySound_Positional_StandardTimer, (int ID, EntityData1* entity, int pri, int volume, float x, float y, float z), 0x424FC0);
//3D
FunctionPointer(void, PlaySound_3D_Timer_pri, (int ID, EntityData1* entity, int pri, int volume, int playlength, EntityData1* entity_origin), 0x424880);
FunctionPointer(void, PlaySound_3D_Timer, (int ID, EntityData1* entity, int pri, int volume, int playlength, EntityData1* entity_origin), 0x424920);
FunctionPointer(void, PlaySound_Pseudo3D, (int ID, EntityData1* entity, int index, int volume, int length, float x, float y, float z), 0x424100);
FunctionPointer(void, PlaySound_3D_WithCamera_Timer, (int ID, EntityData1* entity, int pri, int volume, int playlength, float unused_multiplier, EntityData1* origin_entity), 0x4249E0);

void SoundTest3D_Delete(ObjectMaster* a1);
void SoundTest3D_Display(ObjectMaster* a1);
void SoundTest3D_Main(ObjectMaster* a1);
void Load3DSoundTest(ObjectMaster* a1);
void AlarmFix(SoundIDs sound_id, EntityData1* entity, int pri, int volume, float x, float y, float z);
int PlaySound_XYZ_IgnoreDuplicates(int ID, EntityData1* entity, int index, int volume, float x, float y, float z);
int PlaySound_FadeOut(int ID, EntityData1* entity, int index, int volume, int timer);
int QueueBullet(int sound_id, EntityData1* entity, int min_index, int volume, float x, float y, float z);
int StopSound_Fade(int num);
void PlaySound_Delayed(int sound_id, EntityData1* a2, int min_index, int volume, int timer, EntityData1* a6);
int PlaySound_StandardTimer_Delay(SoundIDs ID, void* entity, int pri, int volume);
Sint32 FreezerFix(SoundIDs sound_id, EntityData1* entity, int pri, int volume, int playlength, float x, float y, float z);