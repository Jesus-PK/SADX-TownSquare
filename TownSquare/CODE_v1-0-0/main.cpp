#include "pch.h"
#include "animation.h"
#include "camera.h"
#include "macros.h"
#include "startpos.h"
#include "tailsfix.h"
#include "trialmenu.h"

	extern "C"
	{
		__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
			{
				// Act 1 Start Positions:
				
				helperFunctions.RegisterStartPosition(Characters_Sonic, SpeedHighway0);
				helperFunctions.RegisterStartPosition(Characters_Tails, SpeedHighway0);
				helperFunctions.RegisterStartPosition(Characters_Amy, SpeedHighway0);
				helperFunctions.RegisterStartPosition(Characters_Big, SpeedHighway0);
				helperFunctions.RegisterStartPosition(Characters_Gamma, SpeedHighway0);


				// Act 2 Start Positions:

				helperFunctions.RegisterStartPosition(Characters_Sonic, SpeedHighway1);
				helperFunctions.RegisterStartPosition(Characters_Tails, SpeedHighway1);
				helperFunctions.RegisterStartPosition(Characters_Amy, SpeedHighway1);
				helperFunctions.RegisterStartPosition(Characters_Big, SpeedHighway1);
				helperFunctions.RegisterStartPosition(Characters_Gamma, SpeedHighway1);


				// Act 3 Start Positions:

				helperFunctions.RegisterStartPosition(Characters_Sonic, SpeedHighway2);
				helperFunctions.RegisterStartPosition(Characters_Tails, SpeedHighway2);
				helperFunctions.RegisterStartPosition(Characters_Knuckles, SpeedHighway2);
				helperFunctions.RegisterStartPosition(Characters_Amy, SpeedHighway2);
				helperFunctions.RegisterStartPosition(Characters_Big, SpeedHighway2);
				helperFunctions.RegisterStartPosition(Characters_Gamma, SpeedHighway2);


				// SET, CAM & PL Files Replacement:

				ReplaceBIN("SET0402S", "SET_TownSquareS");
				ReplaceBIN("SET0402K", "SET_TownSquareK");
				ReplaceBIN("CAM0402S", "CAM_TownSquareS");
				ReplaceBIN("CAM0402K", "CAM_TownSquareK");
				ReplaceBIN("PL_42B", "PL_TownSquare");


				// OST Replacement:

				helperFunctions.ReplaceFile("system\\sounddata\\bgm\\wma\\highway3.wma", "system\\OST_TownSquare.flac");


				// Title Cards Replacement:

				char pathbuf[MAX_PATH];
					ReplaceTitleCard("S_STAGE06_E");
					ReplaceTitleCard("M_STAGE05_E");
					ReplaceTitleCard("K_STAGE01_E");


				// Trial Menu Entries:

				*(TrialLevelList*)0x7EF5EC = SonicActionStages;
				*(TrialLevelList*)0x7EF61C = MetalSonicActionStages;
				*(TrialLevelList*)0x7EF5F4 = TailsActionStages;


				// Force Free Camera on Speed Highway Act3:

				RoundMasterList[LevelIDs_SpeedHighway] = ForceFreeCameraSH;
				
				
				// Enable Speed Highway Act2 Transition Trigger For Everyone - Code by Sora:

				WriteData<6>((int*)0x61006a, 0x90);

				
				// Disable Speed Highway Act3 Cars - Code by Sora:

				WriteData<1>((int*)0x612240, 0xC3);


				// Disable Speed Highway Act3 CheckFreeCam Boxes - Code by Kell:

				WriteData<10>((void*)0x4349D3, 0x90);
			}

		
		__declspec(dllexport) void __cdecl OnFrame()
			{
				// Animated Textures:

				AnimatedTextures();
				TailsFix();
			}

		
		__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
	}