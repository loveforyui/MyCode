#ifndef __PLAYER_H__
#define __PLAYER_H__

class Player : public UnitObj
{
public:
    Player();
    Player(INFO rInfo)
        : UnitObj(rInfo)
    {
    }
    virtual ~Player();
public:
    virtual void        Initialize();
};

#endif // !__PLAYER_H__
