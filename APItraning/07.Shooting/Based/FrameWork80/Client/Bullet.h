#ifndef __bullet_h__
#define __bullet_h__

#include "CObj.h"

class CBullet :
	public CObj
{
public:
	CBullet();
	virtual ~CBullet();

	virtual void Initialize();
    virtual void Initialize(INFO, FLOAT);
	virtual int Update();
	virtual void Render(HDC hDC);
	virtual void Release();
 
};

#endif // !__bullet_h__
