#include "Player.h"
#include "../framework.h"

bool CPlayer::SetHealth(float health)
{
	return CallMethodAndReturn<bool, 0x530F60, CPlayer*, float, float>(this, health, 1);
}

void CPlayer::UnlockPsiPower(char* powerName)
{
	CallMethod<0x545690, CPlayer*, char*>(this, powerName);
}

CWeapon* CPlayer::GetCurrentWeapon()
{
	return CallMethodAndReturn<CWeapon*, 0x425440, CPlayer*>(this);
}

bool CPlayer::IsChasing()
{
	return CallMethodAndReturn<bool, 0x6C3070, CPlayer*>(this);
}

bool CPlayer::IsPsiPowerActive()
{
	return CallMethodAndReturn<bool, 0x52F3B0, CPlayer*>(this);
}