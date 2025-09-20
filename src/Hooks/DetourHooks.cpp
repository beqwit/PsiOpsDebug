#include "DetourHooks.h"
#include "../framework.h"
#include "../PsiDebug.h"

#include "../Utils/detours.h"
#pragma comment(lib, "Utils/Detours.lib")

typedef int(__stdcall* ActivateCheatCodeT)(char* cheatCode);
ActivateCheatCodeT ActivateCheatCodeCall = (ActivateCheatCodeT)0x505BC0;

typedef int(__fastcall* PlayerUpdateT)(CPlayer* This, void* edx, int a2);
PlayerUpdateT PlayerUpdateCall = (PlayerUpdateT)0x5283C0;

typedef void(__fastcall* CreateParticleT)(CBase* This, void* edx,
    void* a2,
    int a3,
    char* Str,
    int a5,
    int a6,
    char a7,
    char a8,
    char a9,
    char a10,
    int a11,
    int a12,
    int a13,
    int a14);
CreateParticleT SpawnParticlesCall = (CreateParticleT)0x744190;

HRESULT WINAPI D3D9__CreateDevice_Hook(IDirect3D9* This,
    UINT Adapter,
    D3DDEVTYPE DeviceType,
    HWND hFocusWindow,
    DWORD BehaviorFlags,
    D3DPRESENT_PARAMETERS* pPresentationParameters,
    IDirect3DDevice9** ppReturnedDeviceInterface)
{
    
    pPresentationParameters->Windowed = 1;

    HRESULT result = This->CreateDevice(Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters, ppReturnedDeviceInterface);

    if (SUCCEEDED(result))
    {
        LONG style = GetWindowLong(hFocusWindow, GWL_STYLE);
        SetWindowLong(hFocusWindow, GWL_STYLE, style | WS_OVERLAPPEDWINDOW);
        SetWindowPos(hFocusWindow, NULL, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_FRAMECHANGED);
    }

    return 0;
}

static void __fastcall SpawnParticles_Hook(CBase* This, void* edx,
    void* a2,
    int a3,
    char* Str,
    int a5,
    int a6,
    char a7,
    char a8,
    char a9,
    char isStopped,
    int a11,
    int a12,
    int a13,
    int a14)
{
    // KDD_FX_duststep01 - walk particle, you can play with this
    if (PsiDebug::m_bIsDebug && strcmp(Str, "KDD_FX_duststep01") == 0)
    {
        char newParticleName[] = "JCP_FX_bulletHitSparks";
        Str = newParticleName;
    }

    printf("[HOOK] Spawn particles: %s\n", Str);
    SpawnParticlesCall(This, edx, a2, a3, Str, a5, a6, a7, a8, a9, isStopped, a11, a12, a13, a14);
}

static int __stdcall ActivateCheatCode_Hook(char* cheatStr)
{
    int cheatCode = PsiDebug::ParseCheatCode(cheatStr);

    printf("[HOOK] Activate cheat code \"%d\"\n", cheatCode);

    if (PsiDebug::ActivateCustomCheatCode((CustomCheatCode)cheatCode))
    {
        return 1;
    }

    return ActivateCheatCodeCall(cheatStr);
}

static void __fastcall CPlayer__Update_Hook(CPlayer* This, void* edx, int a2)
{
    CCharacter* characterPlayer = ((CCharacter*)This);

    if (!characterPlayer->IsDead())
    {
        if (PsiDebug::m_bInvisibleCheat)
        {
            if (!This->m_bInvisible)
            {   
                // Set player ghost effect
                CDrawState* drawState = characterPlayer->GetRootAtom()->GetDrawingObject()->GetDrawState();

                drawState->SetAlphaMode(2);
                drawState->SetLightingMode(1);

                // Set invisible for enemies
                CGameScriptInterface::SetInvisible(This, 1);
            }
        }
    }

    PlayerUpdateCall(This, edx, a2);
}

void DetourHooks::InitHooks()
{
    // Replace with NOP for CreateDevice cause im not using trampoline
    if (PsiDebug::m_bIsDebug)
    {
        Nop(0x778C2B, 3);
        InjectHook(0x778C28, D3D9__CreateDevice_Hook, PATCH_CALL);
    }

    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());

    DetourAttach(&(PVOID&)PlayerUpdateCall, CPlayer__Update_Hook);
    DetourAttach(&(PVOID&)SpawnParticlesCall, SpawnParticles_Hook);
    DetourAttach(&(PVOID&)ActivateCheatCodeCall, ActivateCheatCode_Hook);

    DetourTransactionCommit();
}
