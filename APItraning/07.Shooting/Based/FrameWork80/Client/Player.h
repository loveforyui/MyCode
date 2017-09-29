#ifndef __player_h__
#define __player_h__

#include "CObj.h"

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

private:
	OBJLIST*            m_pBulletList;

};

#endif // !__player_h__
