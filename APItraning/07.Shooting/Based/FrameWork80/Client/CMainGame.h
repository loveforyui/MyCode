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
    StateContext*       m_pState;
	OBJLIST		        m_BulletList;

    CObj*               m_midObj;
    CObj*               m_ptrObj;
};

#endif // !__maingame_h__



