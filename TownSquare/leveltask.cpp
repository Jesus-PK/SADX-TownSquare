#include "pch.h"
#include "o_skybox.h"
#include "texanims.h"

//	Animated Textures and Level Task:

void RD_TownSquare(task* tp)
{
	auto twp = tp->twp;

	if (!twp->mode)
	{		
		ADXTaskInit();
		PlayMusic(MusicIDs_lstwrld1);

		SETVIEWDATA_TownSquare();

		twp->mode++;
	}
	
	TS_ANIM_Water();
}


//	Level Destructor Trampoline:

static Trampoline* TS_RunLevelDestructor_t = nullptr;

void __cdecl RunLevelDestructor_r(int heap)
{
	if (heap == 0 && CurrentLevel == LevelIDs_LostWorld)
	{
		DragonCount = 0;
		HasKey = 0;
	}

	FunctionPointer(void, origin, (int heap), TS_RunLevelDestructor_t->Target());
	origin(heap);
}


//	Init LevelTask:

void INIT_LevelTask()
{
	RoundMasterList[LevelIDs_LostWorld] = RD_TownSquare; // Level Task.
	ScrollMasterList[LevelIDs_LostWorld] = BG_TownSquare; // Skybox Task.

	TS_RunLevelDestructor_t = new Trampoline((intptr_t)RunLevelDestructor, (intptr_t)RunLevelDestructor + 0x6, RunLevelDestructor_r); // Init Level Destructor Trampoline.
	
	WriteData<10>((void*)0x434A19, 0x90); // Remove "No Free-Cam" boxes in Lost World Act 2.
}