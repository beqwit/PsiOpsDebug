#include "PlayerManager.h"
#include "../framework.h"

CGameManager* CGameManager::Get()
{
    return *(CGameManager**)0xA83A40;
}

CDestination* CGameManager::GetDefaultDestination()
{
    return CallMethodAndReturn<CDestination*, 0x43A4B0, CGameManager*>(this);
}

CPlayer* CGameManager::GetPlayer()
{
    return CallMethodAndReturn<CPlayer*, 0x4032A0, CGameManager*>(this);
}

bool CGameManager::IsGamePaused()
{
    return CallMethodAndReturn<bool, 0x477930, CGameManager*>(this);
}