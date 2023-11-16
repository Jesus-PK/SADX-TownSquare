#include "pch.h"

//  Stage Names:

void STAGENAMES_TownSquare()
{
    if (HD_GUI)
    {
        ReplaceTEX("AVA_STNAM", "TX_ST13", "StageNames", "HD_StageName_TownSquare-JP", 365043, 128, 16);
        ReplaceTEX("AVA_STNAM_E", "TX_ST13_e", "StageNames", "HD_StageName_TownSquare-EN", 10000421, 128, 16);
    }
    
    else
    {
        ReplaceTEX("AVA_STNAM", "TX_ST13", "StageNames", "SD_StageName_TownSquare-JP", 365043, 128, 16);
        ReplaceTEX("AVA_STNAM_E", "TX_ST13_e", "StageNames", "SD_StageName_TownSquare-EN", 10000421, 128, 16);
    }
}


//  TitleCards:

void TITLECARDS_TownSquare()
{
    std::string index = ModPath;

    if (HD_GUI)
    {
        index += "\\textures\\TitleCards_HD\\index.txt";
        const char* HD_Index = index.c_str();

        ReplacePVR("S_STAGE09", HD_Index);
        ReplacePVR("K_STAGE04", HD_Index);
        
        ReplacePVR("S_STAGE09_E", HD_Index);
        ReplacePVR("K_STAGE04_E", HD_Index);
    }

    else
    {
        index += "\\textures\\TitleCards_SD\\index.txt";
        const char* SD_Index = index.c_str();

        ReplacePVR("S_STAGE09", SD_Index);
        ReplacePVR("K_STAGE04", SD_Index);
        
        ReplacePVR("S_STAGE09_E", SD_Index);        
        ReplacePVR("K_STAGE04_E", SD_Index);

        ReplacePVR("S_STAGE09_DC", SD_Index);
        ReplacePVR("K_STAGE04_DC", SD_Index);
        
        ReplacePVR("S_STAGE09_E_DC", SD_Index);        
        ReplacePVR("K_STAGE04_E_DC", SD_Index);
    }
}


//  Multiplayer Thumbnails:

void MULTITHUMBNAILS_TownSquare()
{
	ReplaceTEX("AVA_MULTI", "multistg0700", "MultiThumbnails", "Multi_TownSquare-S", 54926008, 128, 72);
	ReplaceTEX("AVA_MULTI", "multistg0701", "MultiThumbnails", "Multi_TownSquare-K", 71757014, 128, 72);
}


//  Stage Credits:

void STAGECREDITS_TownSquare()
{
    if (HD_GUI)
    {
        ReplaceTEX("ENDBG_SONIC_2", "s_ev023", "StageCredits", "HD_StageCredits_TownSquare-S00", 366022, 256, 256);
        ReplaceTEX("ENDBG_SUPERSONIC_0", "ss_ev008", "StageCredits", "HD_StageCredits_TownSquare-S01", 366156, 256, 256);
        ReplaceTEX("ENDBG_KNUCKLES_1", "k_ev016", "StageCredits", "HD_StageCredits_TownSquare-K00", 366065, 256, 256);
        ReplaceTEX("ENDBG_KNUCKLES_1", "k_ev017", "StageCredits", "HD_StageCredits_TownSquare-K01", 366066, 256, 256);
    }

    else if (DC_Conversion)
    {
        ReplaceTEX("ENDBG_SONIC_2", "s_ev023", "StageCredits", "DC_StageCredits_TownSquare-S00", 366022, 256, 256);
        ReplaceTEX("ENDBG_SUPERSONIC_0", "ss_ev008", "StageCredits", "DC_StageCredits_TownSquare-S01", 366156, 256, 256);
        ReplaceTEX("ENDBG_KNUCKLES_1", "k_ev016", "StageCredits", "DC_StageCredits_TownSquare-K00", 366065, 256, 256);
        ReplaceTEX("ENDBG_KNUCKLES_1", "k_ev017", "StageCredits", "DC_StageCredits_TownSquare-K01", 366066, 256, 256);
    }

    else
    {
        ReplaceTEX("ENDBG_SONIC_2", "sonic_24", "StageCredits", "DX_StageCredits_TownSquare-S00", 366023, 512, 512);
        ReplaceTEX("ENDBG_KNUCKLES_1", "knuckles_19", "StageCredits", "DX_StageCredits_TownSquare-K00", 366068, 512, 512);
        ReplaceTEX("ENDBG_KNUCKLES_2", "knuckles_20", "StageCredits", "DX_StageCredits_TownSquare-K00", 366069, 512, 512);
    }
}


//	Sound Test Entries:

SoundTestEntry SoundTestEntry_TownSquare = { "Town Square:  Spyro the Dragon", 63 };


//  Init Graphics:

void INIT_Graphics()
{
    STAGENAMES_TownSquare();
    TITLECARDS_TownSquare();
    MULTITHUMBNAILS_TownSquare();
    STAGECREDITS_TownSquare();

    Soundtest_ActionStage[9] = SoundTestEntry_TownSquare;
}