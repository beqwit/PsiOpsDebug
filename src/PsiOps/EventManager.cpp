#include "EventManager.h"
#include "../framework.h"

CEventManager* CEventManager::Get()
{
    return CallAndReturn<CEventManager*, 0x5388C0>();
}