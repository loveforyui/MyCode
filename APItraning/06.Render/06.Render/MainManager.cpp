#include "stdafx.h"
#include "MainManager.h"

MainManager* MainManager::inst = NULL;

MainManager::MainManager()
{
}


MainManager::~MainManager()
{
}

CPhysics & MainManager::get_world_physics()
{
    // TODO: ���⿡ ��ȯ ������ �����մϴ�.
    return world_physics;
}
