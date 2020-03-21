#include "stdafx.h"

FunctionPointer(void, sub_408530, (NJS_OBJECT* a1), 0x408530);

SETObjData setdatax = {};

void SoundTest3D_Delete(ObjectMaster* a1)
{
	CheckThingButThenDeleteObject(a1);
}

void SoundTest3D_Display(ObjectMaster* a1)
{
	EntityData1* v1;
	v1 = a1->Data1;
	if (!MissedFrames)
	{
		njPushMatrix(0);
		njTranslateV(0, &v1->Position);
		njScale(0, 0.3f, 0.3f, 0.3f);
		njRotateXYZ(0, 0, 0, 0);
		SetMaterialAndSpriteColor_Float(0.5f, 1.0f, 0, 1.0f);
		sub_408530(&Sphere_Model);
		njPopMatrix(1u);
		ClampGlobalColorThing_Thing();
	}
}

void SoundTest3D_Main(ObjectMaster* a1)
{
	StopMusic();
	EntityData1* v1;
	v1 = a1->Data1;
	//v1->Rotation.x = EntityData1Ptrs[0]->Position.x;
	//v1->Rotation.y = EntityData1Ptrs[0]->Position.y;
	//v1->Rotation.z = EntityData1Ptrs[0]->Position.z;
	v1->Position.x = v1->Rotation.x + 20.0f * sin(NJM_ANG_DEG(v1->Scale.y));
	v1->Position.y = EntityData1Ptrs[0]->Position.y + 11;
	v1->Position.z = v1->Rotation.z + 20.0f * cos(NJM_ANG_DEG(v1->Scale.y));
	//a1->Data1->Scale.y += 8;
	SoundTest3D_Display(a1);
	//if (FrameCounter % 60 == 0) PlaySound_Pseudo3D(SE_SPI_HYUN, v1, 0, 0, 60, v1->Position.x, v1->Position.y, v1->Position.z);
	if (FrameCounter % 60 == 0) PlaySound_3D_Timer(SE_SPI_HYUN, v1, 0, -127, 60, v1);
	//if (FrameCounter % 60 == 0) PlaySound_3D_Timer_pri(SE_SPI_HYUN, v1, 0, 1000, 60, v1);
	//if (FrameCounter % 60 == 0) CustomSound(SE_SPI_HYUN, v1, 0, 1000, 1000, 120, 0x4211, 0, 0, 0);
	//if (FrameCounter % 60 == 0) PlaySound_Positional_Timer(SE_SPI_HYUN, v1, 0, 0, 60, v1->Position.x, v1->Position.y,v1->Position.z);
	//if (FrameCounter % 60 == 0) PlaySound_Timer(SE_SPI_HYUN, v1, 0, 0, 60);
	//if (FrameCounter % 60 == 0) PlaySound_3D_WithCamera_Timer(SE_SPI_HYUN, v1, 0, 0, 60, 500.0f, v1);
}

void SoundTest3D_Load(ObjectMaster* a1)
{
	a1->MainSub = (void(__cdecl*)(ObjectMaster*))SoundTest3D_Main;
	a1->DisplaySub = (void(__cdecl*)(ObjectMaster*))SoundTest3D_Display;
	a1->DeleteSub = (void(__cdecl*)(ObjectMaster*))SoundTest3D_Delete;
}

void __cdecl Load3DSoundTest(ObjectMaster* a1)
{
	a1->MainSub = SoundTest3D_Main;
	a1->DisplaySub = SoundTest3D_Display;
	a1->DeleteSub = SoundTest3D_Delete;
	/*ObjectMaster* obj;
	EntityData1* ent;
	ObjectFunc(OF0, SoundTest3D_Load);
	setdatax.Distance = 612800.0f;
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdatax;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 0;
		ent->Position.y = 0;
		ent->Position.z = 0;
		ent->Rotation.x = EntityData1Ptrs[0]->Position.x;
		ent->Rotation.y = EntityData1Ptrs[0]->Position.y;
		ent->Rotation.z = EntityData1Ptrs[0]->Position.z;
	}*/
}
/*
static void SkyBox_EmeraldCoast_Load_r(ObjectMaster* a1);
static Trampoline SkyBox_EmeraldCoast_Load_t(0x4F7230, 0x4F723B, SkyBox_EmeraldCoast_Load_r);
static void __cdecl SkyBox_EmeraldCoast_Load_r(ObjectMaster* a1)
{
	auto original = reinterpret_cast<decltype(SkyBox_EmeraldCoast_Load_r)*>(SkyBox_EmeraldCoast_Load_t.Target());
	original(a1);
	Load3DSoundTest(a1);
}
*/