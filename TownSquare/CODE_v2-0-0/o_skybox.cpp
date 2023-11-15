#include "pch.h"

// Load Skybox Model:

ModelInfo* MDL_TSSkybox = nullptr;

void LOAD_TSSkybox()
{
    MDL_TSSkybox = LoadBasicModel("TownSquare_Skybox");
}


//  Replacement code for Lost World skybox display function (0x5E18F0):

void SKYBOX_TownSquare(task* obj)
{
    auto data = obj->twp;

    Direct3D_SetNearFarPlanes(SkyboxDrawDistance.Minimum, SkyboxDrawDistance.Maximum);

    DisableFog();
    njPushMatrix(0);

    NJS_VECTOR skyboxPos = { 0,0,0 };
    njTranslateV(0, &skyboxPos);
    njScale(0, 20.0f, 20.0f, 20.0f);

    DrawModel(MDL_TSSkybox->getmodel()->basicdxmodel);

    njPopMatrix(1u);
    ToggleStageFog();

    SetGlobalPoint2Col_Colors(0x331544, 0x331544, 0x331544);

    Direct3D_SetNearFarPlanes(LevelDrawDistance.Minimum, LevelDrawDistance.Maximum);
}