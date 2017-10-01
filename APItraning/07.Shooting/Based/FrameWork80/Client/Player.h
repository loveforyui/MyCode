#ifndef __player_h__
#define __player_h__

#include "CObj.h"

class StateContext;
class CPlayer :
	public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	void                SetBulletList       (OBJLIST* pBulletList) { m_pBulletList = pBulletList; }


public:
	virtual void        Initialize          ();
    virtual void        Initialize          (INFO, FLOAT);
	virtual int         Update              ();
	virtual void        Render              (HDC hDC);
	virtual void        Release             ();

private:
	CObj*               CreateBullet        ();
    CObj*               CreateBullet        (DIRECTION);

private:
	OBJLIST*            m_pBulletList;

    BOOL                keyInput;
    DWORD               keyTime;
};

#endif // !__player_h__
