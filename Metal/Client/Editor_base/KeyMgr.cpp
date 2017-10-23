#include "stdafx.h"
#include "KeyMgr.h"

IMPLEMENT_SINGLETON(CKeyMgr)

CKeyMgr::CKeyMgr()
{
	// ��� Ű ���¸� false �ʱ�ȭ.
	memset(m_bKey, 0, sizeof(m_bKey));
}

CKeyMgr::~CKeyMgr()
{

}

bool CKeyMgr::GetKeyPressing(int iKey)
{
	if (GetAsyncKeyState(iKey) & 0x8000)
		return true;

	return false;
}

bool CKeyMgr::GetKeyDown(int iKey)
{
	// ���� ������ ���� �� �������� ������ ��
	if (!m_bKey[iKey] && GetAsyncKeyState(iKey) & 0x8000)
	{
		m_bKey[iKey] = !m_bKey[iKey];
		return true;
	}

	return false;
}

bool CKeyMgr::GetKeyUp(int iKey)
{
	// ���� ���� ���� �ְ� �� �������� ������ �ʾ��� ��
	if (m_bKey[iKey] && !(GetAsyncKeyState(iKey) & 0x8000))
	{
		m_bKey[iKey] = !m_bKey[iKey];
		return true;
	}

	return false;
}

// Update�Լ��� GetKeyPressing, GetKeyDown, GetKeyUp ���� ȣ���� �Ŀ� ȣ�����ִ� �Լ�.
void CKeyMgr::Update()
{
	for (int i = 0; i < MAX_VIRTUAL_KEY; ++i)
	{
		if (m_bKey[i] && !(GetAsyncKeyState(i) & 0x8000))
			m_bKey[i] = !m_bKey[i];

		if (!m_bKey[i] && GetAsyncKeyState(i) & 0x8000)
			m_bKey[i] = !m_bKey[i];
	}
}