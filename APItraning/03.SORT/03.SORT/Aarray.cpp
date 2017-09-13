#include "stdafx.h"
#include "Aarray.h"


#pragma region Construct & Destroy
Aarray::                    Aarray  ()
{
    //_arry = new Area[1];
    //_arry   = (Area*)malloc(sizeof(Area));
    _arry   = NULL;
    _aCnt   = 0;
}

Aarray::                    ~Aarray ()
{
    DOUBLEPTRFREE(_arry, _aCnt, 1);
}
#pragma endregion

#pragma region Setter & Getter
BOOL Aarray::               push_back               (Area & ref)
{
    if (_arry == NULL)
    {
        DUBLEMALLOCSET(_arry, Area, 1, 1);
        _arry[0] = &ref;
        ++_aCnt;
    }
    else
    {
        ++_aCnt;

        //Area* temp = new Area[_aCnt];
        Area** temp = NULL;

        DUBLEMALLOCSET(temp, Area, _aCnt, 1);

        for (UINT i = 0; i < _aCnt - 1; ++i)
        {
            temp[i] = _arry[i];
        }

        temp[_aCnt - 1] = &ref;

        _arry = NULL;
        _arry = temp;

        for (UINT i = 0; i < _aCnt; ++i)
        {
            _arry[i] = temp[i];
        }
    }
    if (_arry != NULL)
        return true;
    else
        return false;
}

BOOL Aarray::               push_back               (Area * ptr)
{
    if (_arry == NULL)
    {
        DUBLEMALLOCSET(_arry, Area, 1, 1);
        _arry[0] = ptr;
        ++_aCnt;
    }
    else
    {
        ++_aCnt;

        //Area* temp = new Area[_aCnt];
        Area** temp = NULL;

        DUBLEMALLOCSET(temp, Area, _aCnt, 1);

        for (UINT i = 0; i < _aCnt - 1; ++i)
        {
            temp[i] = _arry[i];
        }

        temp[_aCnt - 1] = ptr;
        
        _arry = NULL;

        DUBLEMALLOCSET(_arry, Area, _aCnt, 1);

        for (UINT i = 0; i < _aCnt; ++i)
        {
            _arry[i] = temp[i];
        }
    }
    if (_arry != NULL)
        return true;
    else
        return false;
}

BOOL Aarray::               del_back                ()
{
    free(_arry[_aCnt - 1]);
    _arry[_aCnt - 1] = NULL;

    if (0 < _aCnt)
    {
        --_aCnt;
        // realloc
        Area** temp = NULL;
        DUBLEMALLOCSET(temp, Area, _aCnt, 1);

        for (UINT i = 0; i < _aCnt; ++i)
        {
            temp[i] = _arry[i];
        }

        _arry = NULL;

        DUBLEMALLOCSET(_arry, Area, _aCnt, 1);

        for (UINT i = 0; i < _aCnt; ++i)
        {
            _arry[i] = temp[i];
        }
    }

    if (_arry != NULL)
        return true;
    else
        return false;
}

CONST UINT Aarray::         getCount                ()
{
    return _aCnt;
}

CONST Area* Aarray::        getAry                  (UINT index)
{
    return _arry[index];
}
#pragma endregion