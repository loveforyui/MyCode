#include "stdafx.h"
#include "SceneMgr.h"
#include "Logo.h"
#include "Select.h"
#include "Stage_01.h"

//#include "Stage.h"
//#include "MyMenu.h"
//#include "MyEdit.h"

IMPLEMENT_SINGLETON(CSceneMgr)

CSceneMgr::CSceneMgr()
	: m_pScene(nullptr)
	, m_eCurScene(END)
{
}


CSceneMgr::~CSceneMgr()
{
	Release();
}

// State 패턴(상태 패턴)
// FSM(유한 상태 머신)을 베이스로 하는 패턴
// 클래스를 도입하여 상속, 다형성 등을 접목시켜서 더욱더 유연하게 패턴을 구성.

// FSM(유한 상태 머신): 기계 혹은 장치는 오로지 한가지 동작만 갖고 있는다.

void CSceneMgr::SceneChange(SceneID eScene)
{
	if (m_eCurScene != eScene)
	{
		SafeDelete<CScene*>(m_pScene);

		switch (eScene)
		{
		case LOGO:
			m_pScene = new CLogo;
			break;
        case SELEC:
            m_pScene = new CSelect;
            break;
        case STAGE:
            m_pScene = new CStage_01;
            break;
		}

		if (nullptr == m_pScene)
			return;

		m_pScene->Initialize();
		m_eCurScene = eScene;
	}
}

void CSceneMgr::Update()
{
	if (nullptr == m_pScene)
		return;

	m_pScene->Update();
}

void CSceneMgr::Render(HDC hDC)
{
	if (nullptr == m_pScene)
		return;

	m_pScene->Render(hDC);
}

void CSceneMgr::Release()
{
	SafeDelete<CScene*>(m_pScene);
}
