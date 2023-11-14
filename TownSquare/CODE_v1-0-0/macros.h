#pragma once

// Macro to replace .BIN files (SET, CAM & PL) - Use the instruction: ReplaceBIN("VALUEA", "VALUEB"); in the Init.
	#define ReplaceBIN(a, b) helperFunctions.ReplaceFile("system\\" a ".BIN", "system\\" b ".BIN");


// Macro to replace the base .PVR files (TitleCards) with your own .PNGs by opening an index.txt - Use the instruction: char pathbuf[MAX_PATH]; ReplaceTitleCard("VALUEA"); in the Init - Code by PkR.
	#define ReplaceTitleCard(a) do { \
		_snprintf_s(pathbuf, LengthOfArray(pathbuf), "%s\\textures\\TitleCards\\index.txt", path); \
		helperFunctions.ReplaceFile("system\\" a ".PVR", pathbuf); \
		} while (0)