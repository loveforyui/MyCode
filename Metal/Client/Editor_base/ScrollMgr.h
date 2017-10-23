#pragma once
class CScrollMgr
{
	DECLARE_SINGLETON(CScrollMgr)
private:
	CScrollMgr();
	~CScrollMgr();

public:
	float GetScrollX() { return m_fScrollX; }

public:
	void Update();

private:
	float m_fScrollX = 0.f;
};

