#include "stdafx.h"
#include "NPC.h"


NPC::NPC()
{
}


NPC::~NPC()
{
}

void NPC::Initialize()
{
}

void NPC::AddItem(ITEM & item)
{
    _info.inven.push_back(item);
}
