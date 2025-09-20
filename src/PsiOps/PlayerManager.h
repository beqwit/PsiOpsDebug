#pragma once
#include "Destination.h"
#include "Player.h"

class CGameManager
{
public:
    static CGameManager* Get();
    CDestination* GetDefaultDestination();
    CPlayer* GetPlayer();
    bool IsGamePaused();
};