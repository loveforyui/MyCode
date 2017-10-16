#ifndef __keymanager_h__
#define __keymanager_h__

#define MAX_VIRTUAL_KEY 0xFF

class CKeyManager
{
private:
    CKeyManager();
    ~CKeyManager();

public:
    static CKeyManager* GetInst()
    {
        if(nullptr == inst)
    }
private:
    static CKeyManager* inst;
};

#endif // !__keymanager_h__
