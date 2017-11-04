#pragma once

enum eGameState
{
    GS_START
    , GS_LOAD
    , GS_SELECT
    , GS_RUN
    , GS_END
};

enum OBJID
{
    OBJ_BACKGROUD
    , OBJ_COLLISION
    , OBJ_THINGS
    , OBJ_SUBMON
    , OBJ_MONSTER
    , OBJ_PLAYER
    , OBJ_EFFECT
    , OBJ_P_BULLET
    , OBJ_P_BOMB
    , OBJ_M_BULLET
    , OBJ_MOUSE
    , OBJ_UI
    , OBJ_END
};

enum eOBJSTATE
{
    OBJ_A_IDLE   = 0x0000
    , OBJ_A_STND = 0x0001
    , OBJ_A_MOVE = 0x0002
    , OBJ_A_JUMP = 0x0004
    , OBJ_A_ATTK = 0x0008
    , OBJ_A_SITD = 0x0010
    , OBJ_A_DIE  = 0x0020
    , OBJ_A_BOMB = 0x0040
};

enum eKMOB
{
    MOB_K_BABA          = RGB(255, 0, 0)
    , MOB_K_BAKING      = RGB(50, 50, 50)
    , MOB_K_TRUCK       = RGB(128, 128, 128)
    , MOB_K_BASAKA      = RGB(34, 34, 34)
    , MOB_K_S_BODY      = RGB(77, 77, 77)
    , MOB_K_S_LEFT      = RGB(88, 88, 88)
    , MOB_K_S_RIGHT     = RGB(99, 99, 99)
    , MOB_K_S_CENT      = RGB(100, 100, 100)
    , MOB_K_S_SOLD      = RGB(111, 111, 111)
    , MOB_K_S_DOOR      = RGB(222, 222, 222)
    , MOB_K_S_BDOOR     = RGB(222, 111, 111)
    , MOB_K_HELL        = RGB(222, 222, 111)
    , MOB_K_BOSSBODY    = RGB(250, 250, 250)
    , MOB_K_BOSSLEFT    = RGB(250, 0, 0)
    , MOB_K_BOSSRIGHT   = RGB(250, 0, 30)
    , MOB_K_BOSSTOP     = RGB(250, 0, 60)    
};