#include "Weapon.h"
#include "../framework.h"

int CWeapon::GetType()
{
	return CallMethodAndReturn<int, 0x405730, CWeapon*>(this);
}