#include "ExtraContent.h"
#include "../framework.h"

void CExtraContent::SelectCharacter(int id)
{
    CallMethod<0x5049E0, CExtraContent*, int>(this, id);
}