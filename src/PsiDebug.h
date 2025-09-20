#pragma once
#include <vector>
#include "PsiOps.h"

enum CustomCheatCode
{
    ENABLE_DEBUG = 5034455,
    RANDOM_LEVEL = 8800555,
    INVISIBLE_MODE = 929292,
    UNLOCK_ALL_EXTRA = 735834
};

struct CharacterEntry
{
    const char* name;
    int unk;
};

class PsiDebug
{
public:
    static void UnlockDebug();
    static void ParseLevelList(CStringVector* levelList);
    static void ParseLevelSegments(CString* levelId, CStringVector* levelSegments);
    static std::vector<std::string> GetCharacterNames();
    static int ParseCheatCode(char* cheatCode);
    static void SetRandomCharacter();
    static void GotoRandomLevel();
    static int ActivateCustomCheatCode(CustomCheatCode cheatCode);

    static bool m_bInvisibleCheat;
    static bool m_bIsDebugRun;
};

enum CharacterId
{
    NICK = 226,
    MAS2 = 227,
    MAS = 228,
    NINJ = 229,
    SARA = 230,
    SRA2 = 231,
    TNYA = 232,
    SUSA = 233,
    PK = 234,
    PK2 = 235,
    PK3 = 236,
    PK4 = 237,
    GEN2 = 238,
    TK = 239,
    TKT1 = 240,
    TKT2 = 241,
    TKT3 = 242,
    TKT4 = 243,
    TKT5 = 244,
    TKT6 = 245,
    MC = 246,
    IL = 247,
    IL2 = 248,
    IL3 = 249,
    MP1 = 250,
    MP2 = 251,
    MP3 = 252,
    JACK = 253,
    UN = 254,
    SCOR = 258
};
