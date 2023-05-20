#include "pch.h"

//	Custom LevelOBJ - Replacement code for Lost World levelOBJ function (0x5E18B0):

void OBJ_TownSquare(task* obj)
{
	auto data = obj->twp;

	switch (data->mode)
	{
		case 0:

			ADXTaskInit();
			PlayMusic(MusicIDs_lstwrld1);

			data->mode++;

			break;


		case 1:

			SETVIEWDATA_TownSquare();

			break;
	}
}


void ANIMATEDWATER_TownSquare()
{
	if (CurrentLevel != LevelIDs_LostWorld || GameState != 4 && GameState != 15)
		return;

	RUIN01_TEXLIST.textures[0].texaddr = TEXLIST_TSWater.textures[(FrameCounter / 2) % (LengthOfArray(TEX_TSWater))].texaddr; // Water Animation
	RUIN01_TEXLIST.textures[1].texaddr = TEXLIST_TSFountain.textures[(FrameCounter / 3) % (LengthOfArray(TEX_TSFountain))].texaddr; // Fountain Animation
}