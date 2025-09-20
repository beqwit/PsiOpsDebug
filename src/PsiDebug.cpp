#include "PsiDebug.h"

bool PsiDebug::m_bIsDebugRun;
bool PsiDebug::m_bInvisibleCheat;

void PsiDebug::ParseLevelList(CStringVector* levelList)
{
    STDCall<0x4F63E0, CStringVector*>(levelList);
}

void PsiDebug::ParseLevelSegments(CString* levelId, CStringVector* levelSegments)
{
    STDCall<0x4F64E0, CString*, CStringVector*>(levelId, levelSegments);
}

std::vector<std::string> PsiDebug::GetCharacterNames()
{
    // Getting character names array from game
    CharacterEntry* characterArray = (CharacterEntry*)(0xA468C0);
    int endCharacterArray = (int)(0xA469E0);

    std::vector<std::string> names;

    // Calculate size of array
    const int characterCount = (endCharacterArray - (int)characterArray) / sizeof(CharacterEntry);

    for (int i = 0; i < characterCount; i++)
    {
        const char* characterName = characterArray[i].name;

        if (characterName != nullptr)
        {
            names.push_back(characterName);
        }
    }

    return names;
}

int PsiDebug::ParseCheatCode(char* cheatCode)
{
    const std::string& cheatStr = cheatCode;
    std::string result;

    for (char c : cheatStr)
    {
        if (c != ' ')
        {
            result.push_back(c);
        }
    }

    return std::stoi(result);
}

void PsiDebug::SetRandomCharacter()
{
    std::vector<std::string> characterList = GetCharacterNames();
    std::string randomCharacter = characterList[rand() % characterList.size()];

    CGameOptions* gameOptions = CGameOptions::Get();
    CGameScriptInterface::SetMainCharacter(gameOptions, randomCharacter.c_str(), 0, 0, 0, 0);
}

// Idk why, but I have to use one string game vector in this function, otherwise undefined behavior
void PsiDebug::GotoRandomLevel()
{
    printf("[FUNC] GotoRandomLevel()\n");

    CStringVector* levelData = new CStringVector();

    ParseLevelList(levelData);

    int levelCount = levelData->Size();
    int level = rand() % levelCount;

    // If this a menu level, randomize next
    if (strcmp(levelData->GetElement(level)->GetData()->c_str(), "97") == 0)
    {
        level -= rand() % (levelCount - 2);
    }

    ParseLevelSegments(levelData->GetElement(level), levelData);

    const char* levelName = levelData->GetElement(level)->GetData()->c_str();
    const char* segmentName;

    // If this a non-active level with prefix 'V', randomize next
    do
    {
        int segment = rand() % (levelData->Size() - levelCount);
        segmentName = levelData->GetElement(levelCount + segment)->GetData()->c_str();
    } while (segmentName[0] == 'V');

    CGameOptions* gameOptions = CGameOptions::Get();

    SetRandomCharacter();
    gameOptions->GotoLevel(levelName, segmentName, 0, 0, 0);

    // Destroy string game vector
    delete levelData;
}

int PsiDebug::ActivateCustomCheatCode(CustomCheatCode cheatCode)
{
    switch (cheatCode)
    {
        case RANDOM_LEVEL:
        {
            CScreenManager* screen = CScreenManager::Get();
            CScreenObject* screenObj = screen->GetShowingScreen("Shell/EnterCode");

            // Closing enter code HUD otherwise there will be a crash
            screen->GetHUD()->CloseHUD(screenObj);

            GotoRandomLevel();
            break;
        }
        case UNLOCK_ALL_EXTRA:
        {
            // Interface game option always return true
            Patch(0x50D19D, { 0xB0, 0x01, 0x90, 0x90, 0x90, 0x90 });
            break;
        }
        default:
        {
            return 0;
        }
        case INVISIBLE_MODE:
        {
            m_bInvisibleCheat = true;
            break;
        }

    }

    return 1;
}
