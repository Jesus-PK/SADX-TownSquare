#include "pch.h"

//  Model:

ModelInfo* MDL_TownSquare_Skybox = nullptr;


//  Skybox - Main:

void DISPLAY_TownSquare_Skybox(task* tp)
{
    auto twp = tp->twp;

    njSetTexture(&TEXLIST_TownSquare_Objects);

    Direct3D_SetNearFarPlanes(SkyboxDrawDistance.Minimum, SkyboxDrawDistance.Maximum);

    DisableFog();
    njPushMatrix(0);

    njTranslate(0, 0.0f, 0.0f, 0.0f);
    njScale(0, 20.0f, 20.0f, 20.0f);

    DrawModel(MDL_TownSquare_Skybox->getmodel()->basicdxmodel);

    njPopMatrix(1u);
    ToggleStageFog();

    Direct3D_SetNearFarPlanes(LevelDrawDistance.Minimum, LevelDrawDistance.Maximum);
}

void EXEC_TownSquare_Skybox(task* tp)
{
    auto twp = tp->twp;

    if (!twp->mode)
    {  
        SetGlobalPoint2Col_Colors(0x331544, 0x331544, 0x331544);
        
        twp->mode++;
    }

    tp->disp(tp);
}

void BG_TownSquare(task* tp)
{
    tp->exec = EXEC_TownSquare_Skybox;
    tp->disp = DISPLAY_TownSquare_Skybox;
}


//  Skybox - Load Assets:

void LOAD_TownSquare_Skybox()
{
    MDL_TownSquare_Skybox = LoadBasicModel("TownSquare_Skybox");
}