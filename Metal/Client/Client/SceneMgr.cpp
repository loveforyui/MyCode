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

// State ����(���� ����)
// FSM(���� ���� �ӽ�)�� ���̽��� �ϴ� ����
// Ŭ������ �����Ͽ� ���, ������ ���� ������Ѽ� ����� �����ϰ� ������ ����.

// FSM(���� ���� �ӽ�): ��� Ȥ�� ��ġ�� ������ �Ѱ��� ���۸� ���� �ִ´�.

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
