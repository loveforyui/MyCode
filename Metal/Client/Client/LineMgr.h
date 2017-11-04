#pragma once

class CLine;
class MCLine;
class CLineMgr
{
	DECLARE_SINGLETON(CLineMgr)
private:
	CLineMgr();
	~CLineMgr();

public:
	// �÷��̾��� x�� ���� �� pOutY���ٰ� �÷��̾ Ÿ���� y�� ����Ѵ�.
	bool CollisionLine(float fX, float* pOutY);
    bool CollisionLineBomb(float fX, float * pOutY);
    float FollowLine(float* fx, float* fy, float * fspeed);
	void LoadData();

    list<CLine*>&   GetLineList     () { return m_LineList; }
    list<MCLine*>&  GetLineListM    () { return m_MlineList; }
	
public:
	void Initialize();
	void Render(HDC hDC);
	void Release();

private:
	list<CLine*>	m_LineList;
    list<MCLine*>   m_MlineList;
};

