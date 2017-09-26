#include "stdafx.h"
#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}

void Player::Initialize()
{
    initPos((LONG)0, (LONG)0);
    makeRect();
}