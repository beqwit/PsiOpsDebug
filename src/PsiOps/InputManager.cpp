#include "InputManager.h"
#include "../framework.h"

CInputManager* CInputManager::Get()
{
    return CallAndReturn<CInputManager*, 0x75C6D0>();
}
