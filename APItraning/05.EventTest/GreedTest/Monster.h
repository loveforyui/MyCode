#ifndef __MONSTER_H__
#define __MONSTER_H__

class Monster : public UnitObj
{
public:
    Monster();
    Monster(INFO rInfo)
        : UnitObj(rInfo)
    {
    }
    virtual ~Monster();
public:
    virtual void        Initialize();
};

#endif