#include "GameOptions.h"
#include "../framework.h"

CGameOptions* CGameOptions::Get()
{
    return CallAndReturn<CGameOptions*, 0x509A60>();
}

CExtraContent* CGameOptions::GetExtraContent()
{
    return CallMethodAndReturn<CExtraContent*, 0x4CCAE0, CGameOptions*>(this);
}

void CGameOptions::GotoLevel(const char* levelName, const char* segmentName, int savePlayer, bool a4, bool fadeOut)
{
    CallMethod<0x509E00, CGameOptions*, const char*, const char*, int, bool, bool>(this, levelName, segmentName, savePlayer, a4, fadeOut);
}

void CGameOptions::ShowEventQuickTip(const char* message, const char* type, bool isStatic)
{
    CallMethod<0x50BC70, CGameOptions*, const char*, const char*, bool>(this, message, type, isStatic);
}

CString* CGameOptions::GetCurrentLevel()
{
    return CallMethodAndReturn<CString*, 0x51FD60, CGameOptions*>(this);
}