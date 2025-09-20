#include "framework.h"
#include <vector>

#include <cstdlib> // For simple random in GotoRandomLevel and SetRandomCharacter
#include <ctime> 
#include "PsiDebug.h"
#include "Hooks/DetourHooks.h"

void AllocateConsole()
{
    if (AllocConsole())
    {
        freopen("conin$", "r", stdin);
        freopen("conout$", "w", stdout);
        freopen("conout$", "w", stderr);

        printf("Psi Ops console allocated.\n");
    }
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        srand(time(0));
#ifdef DEBUG:
        PsiDebug::m_bIsDebugRun = true;
        AllocateConsole();
#endif    
        DetourHooks::InitHooks();
        PsiDebug::UnlockDebug();
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
