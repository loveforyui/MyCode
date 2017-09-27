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
    // TODO: 여기에 반환 구문을 삽입합니다.
    return world_physics;
}
