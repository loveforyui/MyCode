#pragma once

class CMyEdit;
class CMaingame
{
public:
	CMaingame();
	~CMaingame();

public:
	void Initialize();
	void Update();
	void Render();
	void Release();

private:
	HDC	                    m_hdc;
    HBITMAP                 m_hBitmap;
    HBITMAP                 m_hOldmap;

    CMyEdit*	m_pEdit;
	
};

