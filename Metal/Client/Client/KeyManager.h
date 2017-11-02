#pragma once

#define MAX_VRITUAL_KEY 0xFF

class CKeyManager
{
private:
    CKeyManager();
    ~CKeyManager();

public:
    bool                isKeyPressing   (int iKey);
    bool                isKeyDown       (int iKey);
    bool                isKeyUp         (int iKey);

public:
    void                Update          ();

public:
    void                Destroy         ()
    {
        if (inst)
        {
            delete inst;
            inst = nullptr;
        }
    }
    static CKeyManager* GetInst         ()
    {
        if (nullptr == inst)
            inst = new CKeyManager;

        return inst;
    }

private:
    static CKeyManager* inst;

    bool                m_bKey[MAX_VRITUAL_KEY];
};

#define KEY_DOWN(Key) CKeyManager::GetInst()->isKeyDown(Key)
#define KEY_UP(Key) CKeyManager::GetInst()->isKeyUp(Key)
#define KEY_PRESSING(Key) CKeyManager::GetInst()->isKeyPressing(Key)