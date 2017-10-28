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
    tagInfo()
    {

    }
    tagInfo(float _fx, float _fy, float _fcx, float _fcy)
        : fX(_fx), fY(_fy), fCX(_fcx), fCY(_fcy)
    {}

    tagInfo& operator=(tagInfo& ref)
    {

        image = ref.image;
        rect = ref.rect;
        
        
        fX = ref.fX;
        fY = ref.fY;
        fCX = ref.fCX;
        fCY = ref.fCY;
        
        
        fSpeed = ref.fSpeed;
        fAcc = ref.fAcc;
        fJumpPow = ref.fJumpPow;
        fJumpAcc = ref.fJumpAcc;
        
        
        fAngle = ref.fAngle;
        fCannonD = ref.fCannonD;
        fCannonX = ref.fCannonX;
        fCannonY = ref.fCannonY;
        
        
        iHP = ref.iHP;
        iMaxHp = ref.iMaxHp;
        iAtt = ref.iAtt;
        
        isDead = ref.isDead;
        
        preState = ref.preState;
        curState = ref.curState;
        
        
        direction = ref.direction;
        
        m_eKind = ref.m_eKind;
        return *this;
    }

    vector<ObjImg*>* image;
    RECT            rect;

    //float
    float           fX;
    float           fY;
    float           fCX;
    float           fCY;

    // physics
    float           fSpeed;
    float           fAcc;
    float           fJumpPow;
    float           fJumpAcc;
    
    //Cannon
    float           fAngle;
    float           fCannonD;
    float           fCannonX;
    float           fCannonY;

    //int
    int             iHP;
    int             iMaxHp;
    int             iAtt;

    bool            isDead;
    //state
    UINT            preState;
    UINT            curState;

    //
    UINT            direction;

    eKMOB           m_eKind;
}INFO;

typedef struct tagLinePoint
{
	tagLinePoint()
	{
		memset(this, 0, sizeof(tagLinePoint));
	}
	tagLinePoint(float _fX, float _fY)
		: fX(_fX), fY(_fY) {}

	float fX;
	float fY;
}LINEPOINT;

typedef struct tagLineInfo
{
	tagLineInfo()
	{
		memset(this, 0, sizeof(tagLineInfo));
	}
	tagLineInfo(LINEPOINT _tLPoint, LINEPOINT _tRPoint)
		: tLPoint(_tLPoint), tRPoint(_tRPoint) {}

	LINEPOINT tLPoint;
	LINEPOINT tRPoint;
}LINEINFO;