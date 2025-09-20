#pragma once
#include "Weapon.h"

class CInventory
{
public:
	char pad[8];
	float m_fHealth;
	char _pad[2];
	float m_fPsi;

	void SetHealth(float health);
	void SetPsi(float psi);
	void AdjustHealth(float health);
	void AdjustPsi(float psi);
	float GetPsi();
	float GetMaxPsi();
	CWeapon* GetWeapon();
	void AdjustAmmo(float ammo);
};