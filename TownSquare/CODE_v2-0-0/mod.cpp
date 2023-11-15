#include "pch.h"

HelperFunctions HelperFunctionsGlobal;

extern "C"
{
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		//	HelperFunctions pointer for external use:

		HelperFunctionsGlobal = helperFunctions;


		//	Disable DC Conversion Lost World:

		WriteData<5>((void*)0x422DEF, 0x90);
		
		
		//	Custom LevelOBJ:

		WriteJump((void*)0x5E18B0, OBJ_TownSquare);
		
		
		//	Custom Skybox:

		WriteJump((void*)0x5E18F0, SKYBOX_TownSquare);
		
		
		//	Remove "No Free-Cam" boxes in Lost World Act 2:
		
		WriteData<10>((void*)0x434A19, 0x90);
		

		//	Disable Hardcoded Lost World Stuff:
		//	NOTE: Since I registered a path spline and thus overwriting all splines in both acts, it isn't neccesary to remove these two splines individually anymore:

		// WriteData<1>((void*)0x5E45C0, 0xC3); // Disables the stone Snake (also gets rid of the rocky SFX in Act 1 start as this sound is caused by the snake)
		// WriteData<1>((int*)0x5E40D0, 0xC3); // Disables the Indiana Rock


		//	Load Level Stuff:

		LANDTABLE_TownSquare();
		DEATHZONES_TownSquare();
		STARTPOSITIONS_TownSquare(helperFunctions);
		PATHS_TownSquare(helperFunctions);
		FILES_TownSquare(helperFunctions);


		//	Load Object Assets:

		LOADOBJECTS_TownSquare();


		//	Load Object List and Texture List:

		INITOBJECTS_TownSquare();


		//	Load TitleCards and Mission Cards:

		TITLECARDS_TownSquare(path, helperFunctions);
		MISSIONCARDS_TownSquare();
	}


	__declspec(dllexport) void __cdecl OnFrame()
	{
		//	Animated Textures Function:

		ANIMATEDWATER_TownSquare();


		//	Lantern Engine .dll Check:

		CHECK_LanternEngine();
	}


	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}