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
    void SetScrollX(float x) { m_fScrollX = x; }
    void SetHold(bool b) { isHold = b; }

public:
	void Update();

private:
	float m_fScrollX = 0.f;
	float m_fOffSet = WINCX / 2.f;
    bool isHold = false;
};

