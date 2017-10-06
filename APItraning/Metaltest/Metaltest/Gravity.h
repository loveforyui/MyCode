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

public:
    void SetLine(vector<INT>*);

private:
    vector<Object*> m_vObjlst;
    vector<INT>* m_pLine;
};

#endif // !__gravity_h__