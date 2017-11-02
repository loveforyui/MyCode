#include "stdafx.h"
#include "KeyManager.h"

CKeyManager* CKeyManager::inst = nullptr;

CKeyManager::CKeyManager()
{
    memset(m_bKey, 0, sizeof(m_bKey));
}

CKeyManager::~CKeyManager()
{
}

bool CKeyManager::      isKeyPressing   (int iKey)
{
    if (GetAsyncKeyState(iKey) & 0x8000)
		return true;

    return false;
}

bool CKeyManager::      isKeyDown       (int iKey)
{
    // 전에 누른적 없고 현 시점에서 눌렸을 때
	if (!m_bKey[iKey] && GetAsyncKeyState(iKey) & 0x8000)
	{
		m_bKey[iKey] = !m_bKey[iKey];
		return true;
	}

    return false;
}

bool CKeyManager::      isKeyUp         (int iKey)
{
    // 전에 누른 적이 있고 현 시점에서 눌리지 않았을 때
	if (m_bKey[iKey] && !(GetAsyncKeyState(iKey) & 0x8000))
	{
		m_bKey[iKey] = !m_bKey[iKey];
		return true;
	}

    return false;
}

void CKeyManager::      Update          ()
{
    for (int i = 0; i < MAX_VRITUAL_KEY; ++i)
	{
		if (m_bKey[i] && !(GetAsyncKeyState(i) & 0x8000))
			m_bKey[i] = !m_bKey[i];

		if (!m_bKey[i] && GetAsyncKeyState(i) & 0x8000)
			m_bKey[i] = !m_bKey[i];
	}
}
