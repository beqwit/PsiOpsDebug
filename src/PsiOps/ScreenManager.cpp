#include "ScreenManager.h"
#include "../framework.h"

CScreenManager* CScreenManager::Get()
{
    return CallAndReturn<CScreenManager*, 0x404F80>();
}

CHUD* CScreenManager::GetHUD()
{
    return (CHUD*)this + 0xB0;
}

void CScreenManager::ShowUserPrompt(const char* prompt, bool isStatic, bool isKey)
{
    CallMethod<0x4F73A0, CScreenManager*, const char*, bool, bool>(this, prompt, isStatic, isKey);
}

CScreenObject* CScreenManager::GetShowingScreen(const char* screenName)
{
    return CallMethodAndReturn<CScreenObject*, 0x566180, CScreenManager*, const char*>(this, screenName);
}

CScreenObject* CHUD::GetShowingScreen(char* screenName, CScreenObject* result)
{
    return CallMethodAndReturn<CScreenObject*, 0x668EC0, CHUD*, char*, CScreenObject*>(this, screenName, result);
}

void CHUD::ShowHUD(char* hudName)
{
    CallMethod<0x6689B0, CHUD*, char*, bool>(this, hudName, 1);
}

void CHUD::CloseHUD(CScreenObject* screenObj)
{
    CallMethod<0x669150, CHUD*, CScreenObject*>(this, screenObj);
}