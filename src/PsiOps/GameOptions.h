#pragma once
#include "PCore.h"

class CExtraContent;

class CGameOptions {
public:
    static CGameOptions* Get();
    CExtraContent* GetExtraContent();
    CString* GetCurrentLevel();
    void GotoLevel(const char* levelName, const char* segmentName, int savePlayer, bool a4, bool fadeOut);
    void ShowEventQuickTip(const char* message, const char* type, bool isStatic);
};