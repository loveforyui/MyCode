#ifndef __NPC_H__
#define __NPC_H__

class NPC : public UnitObj
{
public:
    NPC();
    NPC(INFO rInfo)
    : UnitObj(rInfo){}
    virtual ~NPC();
    virtual void        Initialize  ();
    virtual void        AddItem     (ITEM& item);
};


#endif // !__NPC_H__
