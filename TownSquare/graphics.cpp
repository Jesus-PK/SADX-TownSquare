#include "pch.h"

//	TitleCards:

#define	ReplaceTitleCard(a) do { \
		_snprintf_s(pathbuf, LengthOfArray(pathbuf), "%s\\textures\\TitleCards\\index.txt", path); \
		helperFunctions.ReplaceFile("system\\" a ".PVR", pathbuf); \
} while (0)

void TITLECARDS_TownSquare(const char* path, const HelperFunctions & helperFunctions)
{
	char pathbuf[MAX_PATH];

	ReplaceTitleCard("S_STAGE09");
	ReplaceTitleCard("S_STAGE09_E");
	ReplaceTitleCard("K_STAGE04");
	ReplaceTitleCard("K_STAGE04_E");
}


//	Mission Cards:

NJS_TEXNAME TEX_TSMission[4] = { 0 };

DataPointer(NJS_TEXANIM, MissionSpriteAnim, 0x917784);

FunctionHook<void> MissionCard_Result_t(0x457BB0);
FunctionHook<void> LoadMissionImage_t(0x457450);


void MISSIONTYPE_Check()
{
    if (Language == ENGLISH)
    {
        MissionSpriteAnim.texid = CurrentCharacter != Characters_Knuckles ? 0 : 1;
    }

    else if (Language == JAPANESE)
    {
        MissionSpriteAnim.texid = CurrentCharacter != Characters_Knuckles ? 2 : 3;
    }
}

void MissionCard_Result_r()
{
    if (CurrentLevel != LevelIDs_LostWorld)
    {
        MissionSpriteAnim.texid = 0;
        
        return MissionCard_Result_t.Original();
    }

    StageMissionTexlist.textures = TEX_TSMission;
    StageMissionTexlist.nbTexture = 1;
    
    LoadPVM("TownSquare_MissionCards", &StageMissionTexlist);
    MISSIONTYPE_Check();

    task* tp = CreateElementalTask(LoadObj_Data1, 6, (TaskFuncPtr)0x457B60);
    
    tp->twp->mode = 0;
    tp->twp->counter.b[1] = GetPlayerNumber();
    tp->twp->wtimer = (MissedFrames_B * 72.0f);
    tp->twp->pos.x = 320.0f;
    tp->twp->pos.y = 240.0f;
    
    tp->dest = (TaskFuncPtr)FreeStageMissionImage;
}

void LoadMissionImage_r()
{
    if (CurrentLevel != LevelIDs_LostWorld)
    {
        MissionSpriteAnim.texid = 0;
        
        return LoadMissionImage_t.Original();
    }

    StageMissionTexlist.textures = TEX_TSMission;
    StageMissionTexlist.nbTexture = 1;
    
    LoadPVM("TownSquare_MissionCards", &StageMissionTexlist);
    MISSIONTYPE_Check();

    task* task = CreateElementalTask(LoadObj_Data1, 6, (TaskFuncPtr)0x457B60);
    
    task->twp->mode = 0;
    task->twp->counter.b[1] = GetPlayerNumber();
    task->twp->wtimer = 120;
    task->twp->pos.x = 320.0f;
    task->twp->pos.y = 360.0f;
    
    task->dest = (TaskFuncPtr)FreeStageMissionImage;
}

void MISSIONCARDS_TownSquare()
{
    MissionCard_Result_t.Hook(MissionCard_Result_r);
    LoadMissionImage_t.Hook(LoadMissionImage_r);
}


//  Lantern Engine error message:

static int LanternErrorMessageTimer = 500;

void CHECK_LanternEngine()
{
    HMODULE DLL_LanternEngine = GetModuleHandle(L"sadx-dc-lighting");

    if (CurrentLevel == LevelIDs_LostWorld && DLL_LanternEngine == nullptr && LanternErrorMessageTimer)
    {
        SetDebugFontSize(Uint16(10.0f * (float)VerticalResolution / 480.0f));
        SetDebugFontColor(0xFFBFBFBF);
        
        DisplayDebugString(NJM_LOCATION(2, 1), "Failed to detect Lantern Engine mod.");
        DisplayDebugString(NJM_LOCATION(2, 2), "The objects in this level will have no lighting.");
        DisplayDebugString(NJM_LOCATION(2, 3), "Please install and enable Lantern Engine for correct visuals.");
        
        LanternErrorMessageTimer--;
    }
}