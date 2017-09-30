#ifndef __cobj_h__
#define __cobj_h__

#include "StateContext.h"

class StateManager;
class CObj
{
public:
	CObj();
	virtual ~CObj();

public:
	void                SetPos          (float fX, float fY) { m_tInfo.fX = fX, m_tInfo.fY = fY; }
    const INFO&         GetPos          () { return m_tInfo; }

    void                SetState        (StateManager* state);

public:
	virtual void        Initialize      ()              = 0;
    virtual void        Initialize      (INFO, FLOAT)   = 0;
	virtual int         Update          ();
	virtual void        Render          (HDC)           = 0;
	virtual void        Release         ()              = 0;

public:
    BOOL operator&&(CObj& src);

protected:
	INFO	            m_tInfo;
	RECT	            m_tRect;
	FLOAT	            m_fSpeed;
    StateContext        m_tState;
};

#endif // !__cobj_h__
