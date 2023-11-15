#include "pch.h"
#include "FunctionHook.h"

// This is all the necessary code and functions to replace SH3 skybox and to make it render correctly - Code by Sora.

    DataPointer(NJS_OBJECT, SH_SkyBox, 0x26A5208);  // This declares the address of the skybox model, we need it to draw it.

    void TownSquare_Skybox(task* obj);
    FunctionHook <void, task*> SH_SkyBoxDisplay_t(0x610570, TownSquare_Skybox); // This init the hack of the skybox rendering function.

    void TownSquare_Skybox(task* obj)   // This is the function that contains the code to replace SH3 skybox.
        {
            auto data = obj->twp;

            if (!Camera_Data1 || data->mode != 7)   // If the camera isn't available, or if we aren't in SH3, let the original code render the skybox.
                {
                    return SH_SkyBoxDisplay_t.Original(obj);
                }

            if (Camera_Data1 && data->mode == 7)    // If the camera is available and if we are in SH3.
                { 
                    Direct3D_SetNearFarPlanes(SkyboxDrawDistance.Minimum, SkyboxDrawDistance.Maximum); // This is used to render skybox properly.

                    DisableFog();   // We disable the fog before rendering the skybox so it doesn't affect it.
                    njPushMatrix(0);    // SADX have to push a matrix before rendering stuff, it's directX related, each task that needs to display something use it.

                    NJS_VECTOR skyboxPos = { 0,0,0 };   // By setting skyboxPos value to { X,Y,Z }, we make the skybox static. You can move the position of the skybox by editing the values.
                    njTranslateV(0, &skyboxPos);    // This gives the instruction to the game of where the object should render.
                    njScale(0, 20.0f, 20.0f, 20.0f);    // You can edit the skybox size by editing the last three values (0, Xf, Yf, Zf).
                    DrawModel(SH_SkyBox.getbasicdxmodel()); // This draws the skybox in-game.

                    njPopMatrix(1u);    // Once the rendering is over, we need to pop the matrix so it doesn't affect other objects.
                    ToggleStageFog();   // This re-enables the fog.

                    SetGlobalPoint2Col_Colors(0x331544, 0x331544, 0x331544);    // You can change the color of the background by editing these values, the format is 0xHTMLColorCode. If you want a solid color you need to set the same values in all 3 slots.

                    Direct3D_SetNearFarPlanes(LevelDrawDistance.Minimum, LevelDrawDistance.Maximum);
                }
        }