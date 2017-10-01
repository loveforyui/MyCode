#ifndef __enum_h__
#define __enum_h__

enum OBJSTATES {
    IDLE            = 0x0000
    , MOVE          = 0x0001
    , ATTACK        = 0x0002
};
enum DIRECTION {
    D_NONE        = 0x0000
    , D_UP        = 0x0001
    , D_DOWN      = 0x0002
    , D_LEFT      = 0x0004
    , D_RIGHT     = 0x0008
    , D_UL        = D_UP | D_LEFT
    , D_UR        = D_UP | D_RIGHT
    , D_DL        = D_DOWN | D_LEFT
    , D_DR        = D_DOWN | D_RIGHT
};

#endif // !__enum_h__
