#include "pch.h"
#include "FunctionHook.h"
#include "animation.h"

// This is all the necessary code and functions to hack the function that originally loads the texture obj of a level, create a custom textlist, load our own .PVMX and make an animated texture by changing the TexID on frame - Code by Sora.

    void LoadLevelObjTex_r();
    FunctionHook<void>LoadLevelObjTex_t(LoadLevelObjTextures, LoadLevelObjTex_r);

    
// We can create a custom texlists with NJS_TEXNAME and NJS_TEXLIST. After the custom name, we have to input in the array [X] the number of textures our .PVMX has.
    
    NJS_TEXNAME Water[14];
    NJS_TEXLIST WaterTextList = { arrayptrandlength(Water) };

    NJS_TEXNAME Fountain[16];
    NJS_TEXLIST FountainTextList = { arrayptrandlength(Fountain) };

    
// We need to call: void AnimatedTextures(); on animation.h and then use the instruction: AnimatedTextures(); in the OnFrame.
    void AnimatedTextures()
        {
            if (GameState != 15 || CurrentLevel != LevelIDs_SpeedHighway) return;   // This checks if we aren't in game.

            
        // This will assign the text ID [X] of the texlist we are replacing (In this case HIGHWAY03) to a new texlist. This new texlist will swap it's on TextID every frame. You can control the speed by editing the value in (FrameCounter / X).

            HIGHWAY03_TEXLIST.textures[2].texaddr = WaterTextList.textures[(FrameCounter / 2) % (LengthOfArray(Water))].texaddr;
            HIGHWAY03_TEXLIST.textures[3].texaddr = FountainTextList.textures[(FrameCounter / 3) % (LengthOfArray(Fountain))].texaddr;
        }


// This will load our .PVMX and custom texlist when we load into Speed Highway.
    void LoadLevelObjTex_r()
        {
            LoadLevelObjTex_t.Original();

            if (CurrentLevel == LevelIDs_SpeedHighway)
                {
                    LoadPVM("TSWater", &WaterTextList);
                    LoadPVM("TSFountain", &FountainTextList);
                }

        }