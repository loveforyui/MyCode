#ifndef __maingame_h__
#define __maingame_h__

class CObj;
class CMainGame
{
public:
    CMainGame();
	~CMainGame();

public:
	void Initialize();
	void Update();
	void Render();
	void Release();

private:
	HDC	m_hDC;
    RECT m_wndRect;

	CObj*		m_pPlayer;
	OBJLIST		m_BulletList;
};

#endif // !__maingame_h__



