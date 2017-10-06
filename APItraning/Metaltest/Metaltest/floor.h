#ifndef __floor_h__
#define __floor_h__

class Object;
class Floor :
    public Object
{
public:
    Floor();
    ~Floor();

    // Object��(��) ���� ��ӵ�
public:
    virtual void Initialize() override;
    virtual void Initialize(OBJINFO &) override;
    virtual void Render(HDC) override;
    virtual void Release() override;
    virtual int  Updatee();
};

#endif // !__floor_h__