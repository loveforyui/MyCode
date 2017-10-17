#pragma once

typedef struct tagObjImg
{
    TCHAR* fileName;
    TCHAR* filePath;
    Image* image;

    tagObjImg& operator=(tagObjImg& ref)
    {
        fileName = new TCHAR[lstrlen(ref.fileName) + 1];
        lstrcpy(fileName, ref.fileName);
        filePath = new TCHAR[lstrlen(ref.filePath) + 1];
        lstrcpy(filePath, ref.filePath);
        image = ref.image;

        return *this;
    }

    void Release()
    {
        delete image;
        delete fileName;
        delete filePath;
    }
}ObjImg;

typedef struct tagInfo
{
    Image* GetImage(const TCHAR* fileName)
    {
        for (vector<ObjImg*>::iterator iter = image->begin()
            ; iter != image->end(); ++iter)
        {
            if (!lstrcmp((*iter)->fileName, fileName))
            {
                return (*iter)->image;
            }
        }
        return nullptr;
    }

    RECT    rect;
    vector<ObjImg*>* image;

    //float
    float   fX;
    float   fY;
    float   fCX;
    float   fCY;
    
    float   fSpeed;
    float   fAngle;

    float   fCannonD;
    float   fCannonX;
    float   fCannonY;

    //int
    int     iHP;
    int     iMaxHp;
    int     iAtt;
}INFO;