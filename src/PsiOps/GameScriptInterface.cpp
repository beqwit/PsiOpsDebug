#include "GameScriptInterface.h"

void CGameScriptInterface::ShowQuickTip(CScreenManager* screen, const char* message, const char* type, bool isStatic)
{
    CallMethod<0x4F77E0, CScreenManager*, const char*, const char*, bool>(screen, message, type, isStatic);
}

float CGameScriptInterface::FrandomInRange(float num1, float num2)
{
    return STDCallAndReturn<float, 0x4CD6F0, float, float>(num1, num2);
}

bool CGameScriptInterface::IsNodeExists(CScreenManager* screen, int nodeId, char* nodeName)
{
    return CallMethodAndReturn<bool, 0x404F60, CScreenManager*, int, char*>(screen, nodeId, nodeName);
}

CBase* CGameScriptInterface::FindUIObject(CScreenManager* screen, int nodeId, char* nodeName)
{
    return CallMethodAndReturn<CBase*, 0x404F40, CScreenManager*, int, char*>(screen, nodeId, nodeName);
}

CString* CGameScriptInterface::FindTextString(CScreenManager* screen, CBase* object, char* textName)
{
    return CallMethodAndReturn<CString*, 0x479FC0, CScreenManager*, CBase*, char*>(screen, object, textName);
}

void CGameScriptInterface::SetMainCharacter(CGameOptions* gameOptions, const char* characterName, bool a3, bool a4, bool a5, bool a6)
{
    CallMethod<0x50BF60, CGameOptions*, const char*, bool, bool, bool, bool>(gameOptions, characterName, a3, a4, a5, a6);
}

void CGameScriptInterface::AcquirePsiPower(CPlayer* player, char* powerName)
{
    CallMethod<0x52C310, CPlayer*, char*>(player, powerName);
}

float CGameScriptInterface::GetPsi(CPlayer* player)
{
    return CallMethodAndReturn<float, 0x4CD350, CPlayer*>(player);
}

bool CGameScriptInterface::SetPsi(CPlayer* player, float psi)
{
    return CallMethodAndReturn<bool, 0x4CD3B0, CPlayer*, float, float>(player, psi, 1);
}

float CGameScriptInterface::GetHitPoints(CPlayer* player)
{
    return CallMethodAndReturn<float, 0x4E55B0, CPlayer*>(player);
}

float CGameScriptInterface::GetMaxPsi(CPlayer* player)
{
    return CallMethodAndReturn<float, 0x4CD390, CPlayer*>(player);
}

float CGameScriptInterface::GetMaxHitPoints(CPlayer* player)
{
    return CallMethodAndReturn<float, 0x4E55D0, CPlayer*>(player);
}

bool CGameScriptInterface::SetHitPoints(CPlayer* player, float hitpoints)
{
    return CallMethodAndReturn<bool, 0x4E55E0, CPlayer*, float>(player, hitpoints);
}

bool CGameScriptInterface::AdjustPsi(CPlayer* player, float psi)
{
    return CallMethodAndReturn<bool, 0x530B50, CPlayer*, float>(player, psi);
}

bool CGameScriptInterface::AdjustHitPoints(CPlayer* player, float hitpoints)
{
    return CallMethodAndReturn<bool, 0x4CD330, CPlayer*, float>(player, hitpoints);
}

int CGameScriptInterface::GetAmmo(CPlayer* player)
{
    return CallMethodAndReturn<int, 0x4CD3D0, CPlayer*>(player);
}

int CGameScriptInterface::GetAmmoStore(CPlayer* player)
{
    return CallMethodAndReturn<int, 0x4CD400, CPlayer*>(player);
}

bool CGameScriptInterface::AdjustAmmo(CPlayer* player, int ammo)
{
    return CallMethodAndReturn<bool, 0x521EF0, CPlayer*, int>(player, ammo);
}

std::string* CGameScriptInterface::CurrentSegment(CGameOptions* gameOptions)
{
    return CallMethodAndReturn<std::string*, 0x4BA6A0, CGameOptions*>(gameOptions);
}

std::string* CGameScriptInterface::CurrentLevel(CGameOptions* gameOptions)
{
    return CallMethodAndReturn<std::string*, 0x4BA680, CGameOptions*>(gameOptions);
}

bool CGameScriptInterface::IsSegmentLoaded(std::string* segment)
{
    return STDCallAndReturn<bool, 0x50AF00, std::string*>(segment);
}

std::string* CGameScriptInterface::GetMainCharacter(CGameOptions* gameOptions)
{
    return CallMethodAndReturn<std::string*, 0x4BA370, CGameOptions*>(gameOptions);
}

void CGameScriptInterface::DisplayMetrics(CGameOptions* gameOptions)
{
    /*
        Console output template:
        level, segment, objectCount, particleSystemCount, characterCount
    */
    CallMethod<0x50C4E0, CGameOptions*>(gameOptions);
}

void CGameScriptInterface::GivePlayerAllPowers()
{
    Call<0x504C70>();
}

void CGameScriptInterface::SetInvisible(CPlayer* player, bool invisible)
{
    CallMethod<0x4CD590, CPlayer*, bool>(player, invisible);
}

bool CGameScriptInterface::SetIncinerate(CCharacter* character)
{
    return CallMethodAndReturn<bool, 0x724FB0, CCharacter*>(character);
}

CInventory* CGameScriptInterface::GetInventory(CPlayer* player)
{
    return CallMethodAndReturn<CInventory*, 0x4CD550, CPlayer*>(player);
}