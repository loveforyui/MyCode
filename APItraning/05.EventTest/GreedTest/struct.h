#ifndef __STRUCT_H__
#define __STRUCT_H__

typedef struct tagPos
{
    LONG X;
    LONG Y;

    tagPos& operator=(tagPos& ref)
    {
        X = ref.X;
        Y = ref.Y;
        return *this;
    }

    void setPos(LONG xPos, LONG yPos)
    {
        X = xPos;
        Y = yPos;
    }
}POS;
typedef struct tagItem
{
    tagItem() {}
    tagItem(TCHAR* iName, int _iAtt, int _iGold, PARTS pa)
        : iAtt(_iAtt), iGold(_iGold), parts(pa)
    {
        _tcscpy_s(szName, sizeof(szName)/sizeof(TCHAR), iName);
    }
    ~tagItem() {}
    TCHAR   szName[32];
    int     iAtt;
    int     iGold;
    PARTS   parts;
}ITEM;
typedef struct tagInfo
{
	tagInfo()
		: iAtt(0), iHp(0), iMaxHp(0), iExp(0), iMaxExp(0), iLev(0), iGold(0)
	{
		//strcpy_s(szName, 16, "");
        _tcscpy_s(szName, sizeof(szName), L"");
        objState = BLOCK;

        equip.insert(pair<PARTS, BOOL>(RIGHTHAND, false));
        equip.insert(pair<PARTS, BOOL>(CHEST, false));
	}

	tagInfo(TCHAR* pName, int _iAtt, int _iMaxHP
		, int _iExp = 0,int _iMaxExp = 100, int _iLev = 1, int _iGold = 0)
		: iAtt(_iAtt), iHp(_iMaxHP), iMaxHp(_iMaxHP)
		, iExp(_iExp), iMaxExp(_iMaxExp), iLev(_iLev), iGold(_iGold)
	{
		_tcscpy_s(szName, sizeof(szName)/sizeof(TCHAR), pName);
        objState = BLOCK;

        equip.insert(pair<PARTS, BOOL>(RIGHTHAND, false));
        equip.insert(pair<PARTS, BOOL>(CHEST, false));
	}

	TCHAR	            szName[32];
	int		            iAtt;
	int		            iHp;
	int		            iMaxHp;
	int		            iExp;
	int		            iMaxExp;
	int		            iLev;
	int		            iGold;
    OBJSTATE            objState;
    map<PARTS, BOOL>    equip;
    vector<ITEM>        inven;
}INFO;



#endif 