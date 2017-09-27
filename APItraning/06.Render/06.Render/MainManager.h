#ifndef __mmager_h__
#define __mmager_h__

class MainManager
{
#pragma region var
private:
    static MainManager* inst;

    CPhysics            world_physics;
    vector<Object*>     world_obj;
#pragma endregion

#pragma region construct
private:
    MainManager()
    {
        if (inst == NULL)
        {
            inst = new MainManager;
        }
    }
    ~MainManager() { delete inst; }
#pragma endregion

#pragma region GetSet
public:
    static MainManager* getInstance() { return inst; }

    GetSet(vector<Object*>, world_obj);
    CPhysics& get_world_physics();
#pragma endregion


};
#endif // !__mmager_h__
