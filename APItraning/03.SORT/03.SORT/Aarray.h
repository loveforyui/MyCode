#ifndef __AARRAY__
#define __AARRAY__

class Aarray
{
#pragma region variable
private:
    Area**   _arry;
    UINT    _aCnt;
#pragma endregion

#pragma region Construct & Destroy
public:
    Aarray();
    ~Aarray();
#pragma endregion

#pragma region Getter & Setter
public:
    BOOL            push_back       (Area& ref);
    BOOL            push_back       (Area* ptr);
    BOOL            del_back        ();
    CONST UINT      getCount        ();
    CONST Area*     getAry          (UINT index);
#pragma endregion

#pragma region Reder
public:

#pragma endregion
};

#endif // !__AARRAY__