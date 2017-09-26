#ifndef __GAMEMANAGER_H__
#define __GAMEMANAGER_H__

class GameManager
{
#pragma region getter
public:
    static GameManager* getInst()
    {
        if (inst == NULL)
        {
            inst = new GameManager;
        }
        return inst;
    }

    UnitObj* getPobj() { return pObj; }
    map<TCHAR*,UnitObj*> getMobObj() { return mobObj; }
#pragma endregion



#pragma region construct
private:
    GameManager() : pObj(NULL) {}    
    static GameManager* inst;

public:
    ~GameManager() {}

#pragma endregion

#pragma region Functions
public:
    void createPlayer(INFO info);
    bool BattleObjtoObj(UnitObj* player, UnitObj* monster);
#pragma endregion


#pragma region var
private:
    UnitObj* pObj;
public:
    map<TCHAR*, UnitObj*> mobObj;
public:
    map<TCHAR*, UnitObj*> npcObj;
#pragma endregion

};


#endif // !__GAMEMANAGER_H__

