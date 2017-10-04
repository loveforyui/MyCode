#ifndef __gravity_h__
#define __gravity_h__

class Object;
class Gravity
{
public:
    Gravity();
    ~Gravity();

public:
    void addObject(Object* obj);
    void Update();

private:
    const FLOAT m_GRAVITY = 9.8f;
    
    vector<Object*> m_vObjlst;
};

#endif // !__gravity_h__