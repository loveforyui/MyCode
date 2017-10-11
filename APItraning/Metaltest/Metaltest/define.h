#ifndef __define_h__
#define __define_h__

#define WINCX 800
#define WINCY 300

//PHYSICS
const FLOAT m_GRAVITY = 6.8f;

//IMAGE
const INT IMGCX = 35;
const INT IMGCY = 35;

// PLAYER BODY STATE
#define PS_BODY_IDLE        0x00000000
#define PS_BODY_STANDING    0x00000001
#define PS_BODY_ST_JMP      0x00000002
#define PS_BODY_WRK         0x00000004

// PLAYER LEG STATE
#define PS_LEG_STANDING     0x0F000001
#define PS_LEG_ST_JMP       0x0F000002
#define PS_LEG_WRK          0x0F000004

// OBJECT DIRECTION
#define OBJ_D_NONE          0x0000
#define OBJ_D_UP            0x0001
#define OBJ_D_DOWN          0x0002
#define OBJ_D_LEFT          0x0004
#define OBJ_D_RIGHT         0x0008

// Player Action STATE
#define OBJ_A_STAY          0x0000
#define OBJ_A_MOVE          0x0001
#define OBJ_A_ATK           0x0002
#define OBJ_A_JMP           0x0004

// PLAYER NAME
#define MARCO               0x0001
#define ERI                 0x0002
#define TARMA               0x0004
#define FIO                 0x0008

#endif // !__define_h__