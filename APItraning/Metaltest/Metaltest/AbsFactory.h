#ifndef __ABSRACTFACTORY_H__
#define __ABSRACTFACTORY_H__

class Object;
template <typename T>
class AbsFactory
{
public:
    static Object* CreateObj()
    {
        Object* pObj = new T;
        pObj
    }
};

#endif // !__ABSRACTFACTORY_H__
