#pragma once
class CScrollMgr
{
	DECLARE_SINGLETON(CScrollMgr)
private:
	CScrollMgr();
	~CScrollMgr();

public:
	float   GetScrollX  () { return m_fScrollX; }
    float   GetScrollY  () { return m_fScrollY; }
    bool    GetHold     () { return isHold; }
    float   GetOffset   () { return m_fOffSet; }

public:
    void    SetScrollX  (float x) { m_fScrollX = x; }
    void    SetScrollY  (float y) { m_fScrollY = y; }
    void    SetHold     (bool b) { isHold = b; }

public:
	void    Update      ();
    void    Render      (HDC hdc);

private:
	float   m_fScrollX  = 0.f;
    float   m_fScrollY  = 0.f;
    float   m_fOffSet   = 150.f;
    bool    isHold      = false;

    vector<ObjImg*>*    m_image;
};

