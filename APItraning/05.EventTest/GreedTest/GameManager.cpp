#include "stdafx.h"
#include "GameManager.h"

GameManager* GameManager::inst = NULL;

void GameManager::createPlayer(INFO info)
{
    pObj = new Player(info);
    pObj->Initialize();
}

bool GameManager::BattleObjtoObj(UnitObj * player, UnitObj * monster)
{
    // monster hp progress
    monster->ProgHp(-(player->GetInfo().iAtt));
    // monster dead check
    if (monster->GetInfo().iHp <= 0)
    {
        // increase
        //player->GetInfo().iExp
        //player->GetInfo().iGold
        player->ProgExp(monster->GetInfo().iExp);
        player->ProgGold(monster->GetInfo().iGold);
        delete monster;
        return true;
    }
    else
    {
        // reduce player
        // player->GetInfo().iHp
        // 
        player->ProgHp(-monster->GetInfo().iAtt);
        if (player->GetInfo().iHp <= 0)
        {
            // player dead progress
        }
        return false;
    }
}
