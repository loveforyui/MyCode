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
    , OBJ_PLAYER
    , OBJ_MONSTER
    , OBJ_THINGS
    , OBJ_P_BULLET
    , OBJ_M_BULLET
    , OBJ_MOUSE
    , OBJ_UI
    , OBJ_END
};

enum eOBJSTATE
{
  OBJ_A_IDLE = 0x0000
, OBJ_A_STND = 0x0001
, OBJ_A_MOVE = 0x0002
, OBJ_A_JUMP = 0x0004
, OBJ_A_ATTK = 0x0008
, OBJ_A_SITD = 0x0010
};