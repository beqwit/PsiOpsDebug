#pragma once
#include "Weapon.h"

class CPlayer
{
public:
	char _pad[0x7C9];
	bool m_bPsiSale;
	bool m_bHealthSale;
	bool m_bBulletProof;
	bool m_bInvisible;
	bool m_bReverseControls;

	CWeapon* GetCurrentWeapon();

	bool SetHealth(float health);
	void UnlockPsiPower(char* powerName);
	bool IsChasing();
	bool IsPsiPowerActive();
};
