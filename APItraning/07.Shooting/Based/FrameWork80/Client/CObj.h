#ifndef __cobj_h__
#define __cobj_h__

class CObj
{
public:
	CObj();
	virtual ~CObj();

public:
	void                SetPos(float fX, float fY) { m_tInfo.fX = fX, m_tInfo.fY = fY; }

public:
	virtual void        Initialize  ()              = 0;
    virtual void        Initialize  (INFO, FLOAT)   = 0;
	virtual int         Update      ();
	virtual void        Render      (HDC)           = 0;
	virtual void        Release     ()              = 0;

protected:
	INFO	            m_tInfo;
	RECT	            m_tRect;
	FLOAT	            m_fSpeed;
};

#endif // !__cobj_h__
