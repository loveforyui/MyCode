#ifndef __maingame_h__
#define __maingame_h__

class CObj;
class StateContext;
class CMainGame
{
private:
    CMainGame();

public:
	~CMainGame();

public:
    static CMainGame*   getInst             ();
	void                Initialize          ();
	void                Update              ();
	void                Render              ();
	void                Release             ();
private:
    BOOL                isEllipsed          (CObj*, CObj*);

private:
    static CMainGame*   inst;

	HDC	                m_hDC;
    RECT                m_wndRect;

	CObj*		        m_pPlayer;
	OBJLIST		        m_BulletList;
    StateContext*       m_pState;

    CObj*               m_midObj;
};

#endif // !__maingame_h__



