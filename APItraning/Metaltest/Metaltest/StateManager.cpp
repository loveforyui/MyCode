#include "stdafx.h"
#include "StateManager.h"


StateManager::StateManager()
{
    isDone = false;
}


StateManager::~StateManager()
{
    ReleaseDC(g_hWnd, m_hdc);
    for (vector<Image*>::iterator i = m_vImage.begin();
        i != m_vImage.end();)
    {
        delete (*i);
        i = m_vImage.erase(i);
    }
}
