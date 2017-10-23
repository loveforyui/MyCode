#pragma once

class CScene;
class CSceneMgr
{
	DECLARE_SINGLETON(CSceneMgr)
public:
	enum SceneID { LOGO, MENU, EDIT, STAGE, ENDING, END };

private:
	CSceneMgr();
	~CSceneMgr();

public:
	void SceneChange(SceneID eScene);
	void Update();
	void Render(HDC hDC);
	void Release();

private:
	CScene*	m_pScene;
	SceneID m_eCurScene;

};

