#include "pch.h"

//  Models, Animations and Collisions:

ModelInfo* MDL_Spyro = nullptr;
ModelInfo* MDL_Nils = nullptr;
ModelInfo* MDL_Devlin = nullptr;
ModelInfo* MDL_Alvar = nullptr;
ModelInfo* MDL_Thor = nullptr;

AnimationFile* ANIM_Spyro = nullptr;
AnimationFile* ANIM_Nils = nullptr;
AnimationFile* ANIM_Devlin = nullptr;
AnimationFile* ANIM_Alvar = nullptr;
AnimationFile* ANIM_Thor = nullptr;

CCL_INFO COL_Spyro = { 0, CollisionShape_Capsule, 0x77, 0, 0, { 0.0f, 6.0f, 0.0f }, 6.0f, 3.0f, 0.0f, 0.0f, 0, 0, 0 };
CCL_INFO COL_Nils = { 0, CollisionShape_Capsule, 0x77, 0, 0, { 0.0f, 15.0f, 0.0f }, 7.5f, 12.5f, 0.0f, 0.0f, 0, 0, 0 };
CCL_INFO COL_Devlin = { 0, CollisionShape_Capsule, 0x77, 0, 0, { 0.0f, 12.5f, 0.0f }, 7.5f, 10.0f, 0.0f, 0.0f, 0, 0, 0 };
CCL_INFO COL_Alvar = { 0, CollisionShape_Capsule, 0x77, 0, 0, { 0.0f, 12.5f, 0.0f }, 7.5f, 10.0f, 0.0f, 0.0f, 0, 0, 0 };
CCL_INFO COL_Thor = { 0, CollisionShape_Capsule, 0x77, 0, 0, { 0.0f, 10.0f, 0.0f }, 7.5f, 15.0f, 0.0f, 0.0f, 0x4000, 0, 0 };


//  Values:

#define SPEED_Dragon twp->scl.x

NJS_POINT3 SCALE_Dragon = { -0.04f, 0.04f, 0.04f };

NJS_POINT3 POS_NilsSmoke = { 0, 0, 0 };
NJS_POINT3 POS_DevlinSmoke = { 0, 0, 0 };
NJS_POINT3 POS_AlvarSmoke = { 0, 0, 0 };
NJS_POINT3 POS_ThorSmoke = { 0, 0, 0 };

NJS_POINT3 VELO_DragonSmoke = { 0, 0, 0 };


//  Spyro - Main:

void DISPLAY_Spyro(task* tp)
{
    if (MissedFrames)
        return;

    auto twp = tp->twp;
    
    NJS_ACTION ACTION_Spyro = { MDL_Spyro->getmodel(), ANIM_Spyro->getmotion() };

    njSetTexture(&TEXLIST_TownSquare_Dragons);
    
    njPushMatrix(0);
    
    njTranslate(0, twp->pos.x, twp->pos.y + 7.0f, twp->pos.z);
    njRotateXYZ(0, twp->ang.x, twp->ang.y, twp->ang.z);
    njScale(0, -0.02f, 0.02f, 0.02f);
    
    SetupChunkModelRender();
    njCnkAction(&ACTION_Spyro, SPEED_Dragon);
    ResetChunkModelRender();
    
    njPopMatrix(1u);
}

void EXEC_Spyro(task* tp)
{
    if (CheckRangeOut(tp))
        return;
    
    auto twp = tp->twp;

    switch (twp->mode)
    {
        case 0:

            tp->disp = DISPLAY_Spyro;
            CCL_Init(tp, &COL_Spyro, 1, 4u);

            twp->mode++;

            break;

        case 1:

            SPEED_Dragon += 0.33f;

            break;
    }

    EntryColliList(twp);

    tp->disp(tp);
}


//  Dragons - Display Functions:

void DISPLAY_Nils(task* tp)
{
    if (MissedFrames)
        return;

    auto twp = tp->twp;

    NJS_ACTION ACTION_Nils = { MDL_Nils->getmodel(), ANIM_Nils->getmotion() };

    njSetTexture(&TEXLIST_TownSquare_Dragons);
    
    njPushMatrix(0);
    
    njTranslate(0,
        twp->pos.x + njSin(twp->ang.y) * 5.0f,
        twp->pos.y + 2.0f,
        twp->pos.z + njCos(twp->ang.y) * 5.0f
    );
    njRotateXYZ(0, twp->ang.x, twp->ang.y, twp->ang.z);
    njScaleV(0, &SCALE_Dragon);

    SetupChunkModelRender();
    njCnkAction(&ACTION_Nils, SPEED_Dragon);
    ResetChunkModelRender();

    njPopMatrix(1u);
}

void DISPLAY_Devlin(task* tp)
{
    if (MissedFrames)
        return;

    auto twp = tp->twp;

    NJS_ACTION ACTION_Devlin = { MDL_Devlin->getmodel(), ANIM_Devlin->getmotion() };

    njSetTexture(&TEXLIST_TownSquare_Dragons);
    
    njPushMatrix(0);
    
    njTranslate(0,
        twp->pos.x + njSin(twp->ang.y) * 4.0f,
        twp->pos.y + 2.0f,
        twp->pos.z + njCos(twp->ang.y) * 4.0f
    );
    njRotateXYZ(0, twp->ang.x, twp->ang.y, twp->ang.z);
    njScaleV(0, &SCALE_Dragon);

    SetupChunkModelRender();
    njCnkAction(&ACTION_Devlin, SPEED_Dragon);
    ResetChunkModelRender();

    njPopMatrix(1u);
}

void DISPLAY_Alvar(task* tp)
{
    if (MissedFrames)
        return;

    auto twp = tp->twp;

    NJS_ACTION ACTION_Alvar = { MDL_Alvar->getmodel(), ANIM_Alvar->getmotion() };

    njSetTexture(&TEXLIST_TownSquare_Dragons);
    
    njPushMatrix(0);
    
    njTranslate(0,
        twp->pos.x + njSin(twp->ang.y) * 4.0f,
        twp->pos.y + 2.0f,
        twp->pos.z + njCos(twp->ang.y) * 4.0f
    );
    njRotateXYZ(0, twp->ang.x, twp->ang.y, twp->ang.z);
    njScaleV(0, &SCALE_Dragon);

    SetupChunkModelRender();
    njCnkAction(&ACTION_Alvar, SPEED_Dragon);
    ResetChunkModelRender();

    njPopMatrix(1u);
}

void DISPLAY_Thor(task* tp)
{
    if (MissedFrames)
        return;

    auto twp = tp->twp;

    NJS_ACTION ACTION_Thor = { MDL_Thor->getmodel(), ANIM_Thor->getmotion() };

    njSetTexture(&TEXLIST_TownSquare_Dragons);
    
    njPushMatrix(0);
    
    njTranslate(0, twp->pos.x, twp->pos.y + 2.0f, twp->pos.z);
    njRotateXYZ(0, twp->ang.x, twp->ang.y, twp->ang.z);
    njScaleV(0, &SCALE_Dragon);

    SetupChunkModelRender();
    njCnkAction(&ACTION_Thor, SPEED_Dragon);
    ResetChunkModelRender();

    njPopMatrix(1u);
}


//  Dragons - Exec Functions:

void EXEC_Nils(task* tp)
{
    if (!CheckRangeOutWithR(tp, 250000.0f))
    {
        auto twp = tp->twp;

        switch (twp->mode)
        {
            case 0:

                tp->disp = DISPLAY_Nils;
                CCL_Init(tp, &COL_Nils, 1, 4u);

                POS_NilsSmoke.x = twp->pos.x;
                POS_NilsSmoke.y = twp->pos.y + 12.0f;
                POS_NilsSmoke.z = twp->pos.z;

                twp->mode++;

                break;

            case 1:

                SPEED_Dragon += 0.375f;

                if (++twp->wtimer > 710)
                {
                    CreateSmoke(&POS_NilsSmoke, &VELO_DragonSmoke, 5.0f);
                    FreeTask(tp);
                }

                break;
        }

        EntryColliList(twp);

        tp->disp(tp);
    }
}

void EXEC_Devlin(task* tp)
{
    if (!CheckRangeOutWithR(tp, 250000.0f))
    {
        auto twp = tp->twp;

        switch (twp->mode)
        {
            case 0:

                tp->disp = DISPLAY_Devlin;
                CCL_Init(tp, &COL_Devlin, 1, 4u);

                POS_DevlinSmoke.x = twp->pos.x;
                POS_DevlinSmoke.y = twp->pos.y + 12.0f;
                POS_DevlinSmoke.z = twp->pos.z;

                twp->mode++;

                break;

            case 1:

                SPEED_Dragon += 0.375f;

                if (++twp->wtimer > 650)
                {
                    CreateSmoke(&POS_DevlinSmoke, &VELO_DragonSmoke, 5.0f);
                    FreeTask(tp);
                }

                break;
        }

        EntryColliList(twp);

        tp->disp(tp);
    }
}

void EXEC_Alvar(task* tp)
{
    if (!CheckRangeOutWithR(tp, 250000.0f))
    {
        auto twp = tp->twp;

        switch (twp->mode)
        {
            case 0:

                tp->disp = DISPLAY_Alvar;
                CCL_Init(tp, &COL_Alvar, 1, 4u);

                POS_AlvarSmoke.x = twp->pos.x;
                POS_AlvarSmoke.y = twp->pos.y + 11.0f;
                POS_AlvarSmoke.z = twp->pos.z;

                twp->mode++;

                break;

            case 1:

                SPEED_Dragon += 0.35f;

                if (++twp->wtimer > 960)
                {
                    CreateSmoke(&POS_AlvarSmoke, &VELO_DragonSmoke, 5.0f);
                    FreeTask(tp);
                }

                break;
        }

        EntryColliList(twp);

        tp->disp(tp);
    }
}

void EXEC_Thor(task* tp)
{
    if (!CheckRangeOutWithR(tp, 250000.0f))
    {
        auto twp = tp->twp;

        switch (twp->mode)
        {
            case 0:

                tp->disp = DISPLAY_Thor;
                CCL_Init(tp, &COL_Thor, 1, 4u);

                POS_ThorSmoke.x = twp->pos.x;
                POS_ThorSmoke.y = twp->pos.y + 11.0f;
                POS_ThorSmoke.z = twp->pos.z;

                twp->mode++;

                break;

            case 1:

                SPEED_Dragon += 0.35f;

                if (++twp->wtimer > 250)
                {
                    CreateSmoke(&POS_ThorSmoke, &VELO_DragonSmoke, 5.0f);
                    FreeTask(tp);
                }

                break;
        }

        EntryColliList(twp);

        tp->disp(tp);
    }
}


//  Dragons - ChildTaskSet:

childtaskset CTS_Nils[] = {
    { EXEC_Nils, 2, 0, {0}, {0}, 0 },
    { 0 }
};

childtaskset CTS_Devlin[] = {
    { EXEC_Devlin, 2, 0, {0}, {0}, 0 },
    { 0 }
};

childtaskset CTS_Alvar[] = {
    { EXEC_Alvar, 2, 0, {0}, {0}, 0 },
    { 0 }
};

childtaskset CTS_Thor[] = {
    { EXEC_Thor, 2, 0, {0}, {0}, 0 },
    { 0 }
};


//  Dragons - Load Assets:

void LOAD_Dragons()
{
    MDL_Spyro = LoadChunkModel("TownSquare_SpyroLEDGE");
    MDL_Nils = LoadChunkModel("TownSquare_Nils");
    MDL_Devlin = LoadChunkModel("TownSquare_Devlin");
    MDL_Alvar = LoadChunkModel("TownSquare_Alvar");
    MDL_Thor = LoadChunkModel("TownSquare_Thor");

    ANIM_Spyro = LoadObjectAnim("TownSquare_SpyroLEDGE");
    ANIM_Nils = LoadObjectAnim("TownSquare_Nils");
    ANIM_Devlin = LoadObjectAnim("TownSquare_Devlin");
    ANIM_Alvar = LoadObjectAnim("TownSquare_Alvar");
    ANIM_Thor = LoadObjectAnim("TownSquare_Thor");
}