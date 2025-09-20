#pragma once
#include "PCore.h"

class CHUD;
class CScreenObject;

class CScreenManager
{
public:
    static CScreenManager* Get();
    CHUD* GetHUD();

    CScreenObject* GetShowingScreen(const char* screenName);
    void ShowUserPrompt(const char* prompt, bool inQueue, bool isKey);
};

class CHUD 
{
public:
    CScreenObject* GetShowingScreen(char* screenName, CScreenObject* result);
    void ShowHUD(char* hudName);
    void CloseHUD(CScreenObject* screenObj);
};