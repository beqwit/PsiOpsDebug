#pragma once
#include "PCore.h"
#include "Character.h"
#include "Inventory.h"

class CScreenManager;
class CGameOptions;
class CPlayer;

static bool* FreezeAI = (bool*)(0xA81CF8);

class CGameScriptInterface
{
public:
    // Options
    static void SetMainCharacter(CGameOptions* gameOptions, const char* characterName, bool a3, bool a4, bool a5, bool a6);
    static std::string* GetMainCharacter(CGameOptions* gameOptions);
    static std::string* CurrentSegment(CGameOptions* gameOptions);
    static std::string* CurrentLevel(CGameOptions* gameOptions);
    static void DisplayMetrics(CGameOptions* gameOptions);
    
    // Player
    static void AcquirePsiPower(CPlayer* player, char* powerName);
    static float GetPsi(CPlayer* player);
    static float GetHitPoints(CPlayer* player);
    static float GetMaxPsi(CPlayer* player);
    static float GetMaxHitPoints(CPlayer* player);
    static bool SetHitPoints(CPlayer* player, float hitpoints);
    static bool SetPsi(CPlayer* player, float psi);
    static bool AdjustPsi(CPlayer* player, float psi);
    static bool AdjustHitPoints(CPlayer* player, float hitpoints);
    static int GetAmmo(CPlayer* player);
    static int GetAmmoStore(CPlayer* player);
    static bool AdjustAmmo(CPlayer* player, int ammo);
    static void SetInvisible(CPlayer* player, bool invisible);
    static bool SetIncinerate(CCharacter* character);

    // Inventory
    static CInventory* GetInventory(CPlayer* player);

    // Screen
    static bool IsNodeExists(CScreenManager* screen, int nodeId, char* nodeName);
    static CBase* FindUIObject(CScreenManager* screen, int nodeId, char* nodeName);
    static CString* FindTextString(CScreenManager* screen, CBase* object, char* nodeName);
    static void ShowQuickTip(CScreenManager* screen, const char* message, const char* type, bool isStatic);
    static CBase* GetShowingScreen(char* screenName);

    // Others
    static float FrandomInRange(float num1, float num2);
    static bool IsSegmentLoaded(std::string* segment);
    static void GivePlayerAllPowers();
};