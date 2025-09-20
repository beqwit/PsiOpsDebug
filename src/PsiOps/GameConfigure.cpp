#include "GameConfigure.h"
#include "../framework.h"

CGameConfigure* CGameConfigure::Get()
{
    return CallAndReturn<CGameConfigure*, 0x7378D0>();
}

bool CGameConfigure::_Flag()
{
    return CallMethodAndReturn<bool, 0x412D70, CGameConfigure*>(this);
}