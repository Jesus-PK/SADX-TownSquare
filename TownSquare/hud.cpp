#include "pch.h"

//  HD GUI check for sprites:

int ArrayID;
float SpriteHeight_Icon;
float SpriteHeight_Counter;

void SetSpriteSettings()
{ 
    //  Set Array ID:
    
    HD_GUI ? ArrayID = 1 : ArrayID = 0;


    //  Set sprite Height and Width values:
    
    if (HUD_Plus)
    {
        SpriteHeight_Icon = 416.0f;
        SpriteHeight_Counter = 424.0f;
    }

    else if (DC_Conversion)
    {
        SpriteHeight_Icon = (DC_HudTweaks) ? 400.0f : 416.0f;
        SpriteHeight_Counter = (DC_HudTweaks) ? 416.0f : 424.0f;
    }

    else
    {
        SpriteHeight_Icon = 416.0f;
        SpriteHeight_Counter = 424.0f;
    }
}


//  Dragon HUD:

static NJS_TEXANIM TEXANIM_DragonIcon[] = {
    { 0x20, 0x20, 0, 0, 0, 0, 0x100, 0x100, 21, 0x20 }, // ID 0 - TexID 28
    { 0x20, 0x20, 0, 0, 0, 0, 0x100, 0x100, 22, 0x20 }, // ID 1 - TexID 29
};

static NJS_SPRITE SPRITE_DragonIcon = { { 0.0f, 0.0f, 0.0f }, 1.0f, 1.0f, 0, &TEXLIST_TownSquare_Objects, TEXANIM_DragonIcon };


static NJS_TEXANIM TEXANIM_DragonCounter[] = {
    { 0x10, 0x10, 0, 0, 0, 0, 0x100, 0x100, 0, 0x20 }, // ID 0 - TexID 0
    { 0x10, 0x10, 0, 0, 0, 0, 0x100, 0x100, 1, 0x20 }, // ID 1 - TexID 1
    { 0x10, 0x10, 0, 0, 0, 0, 0x100, 0x100, 2, 0x20 }, // ID 2 - TexID 2
    { 0x10, 0x10, 0, 0, 0, 0, 0x100, 0x100, 3, 0x20 }, // ID 3 - TexID 3
    { 0x10, 0x10, 0, 0, 0, 0, 0x100, 0x100, 4, 0x20 }, // ID 4 - TexID 4
    { 0x10, 0x10, 0, 0, 0, 0, 0x100, 0x100, 73, 0x20 }, // ID 5 - TexID 73
};

static NJS_SPRITE SPRITE_DragonCounter = { { 0.0f, 0.0f, 0.0f }, 1.0f, 1.0f, 0, &CON_REGULAR_TEXLIST, TEXANIM_DragonCounter };

void DrawDragonCountHUD()
{   
    SetSpriteSettings();
    
    SPRITE_DragonIcon.p.x = 592.0f;
    SPRITE_DragonIcon.p.y = SpriteHeight_Icon;
    late_DrawSprite2D(&SPRITE_DragonIcon, ArrayID, 22046.496f, NJD_SPRITE_ALPHA, LATE_LIG);

    if (DragonCount >= 4)
        SetMaterial(1.0f, 0.0f, 1.0f, 0.0f);
    
    SPRITE_DragonCounter.p.x = 576.0f;
    SPRITE_DragonCounter.p.y = SpriteHeight_Counter;
    late_DrawSprite2D(&SPRITE_DragonCounter, 4, 22046.496f, NJD_SPRITE_ALPHA, LATE_LIG);
    
    SPRITE_DragonCounter.p.x -= 16.0f;
    late_DrawSprite2D(&SPRITE_DragonCounter, 5, 22046.496f, NJD_SPRITE_ALPHA, LATE_LIG);

    SPRITE_DragonCounter.p.x -= 16.0f;
    late_DrawSprite2D(&SPRITE_DragonCounter, DragonCount, 22046.496f, NJD_SPRITE_ALPHA | NJD_SPRITE_COLOR, LATE_LIG);
}

void DrawDragonHUD()
{
    ScaleUI(uiscale::Align_Automatic);
    SetSpriteParam();

    DrawDragonCountHUD();

    ResetSpriteParam();
    ResetScaleUI();
}