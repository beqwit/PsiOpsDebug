#include "Inventory.h"
#include "../framework.h"

void CInventory::SetHealth(float health)
{
	CallMethod<0x534260, CInventory*, float, float>(this, health, 1);
}

void CInventory::SetPsi(float psi)
{
	CallMethod<0x5342F0, CInventory*, float, float>(this, psi, 1);
}

void CInventory::AdjustHealth(float health)
{
	CallMethod<0x534230, CInventory*, float>(this, health);
}

void CInventory::AdjustPsi(float psi)
{
	CallMethod<0x534330, CInventory*, float>(this, psi);
}

float CInventory::GetPsi()
{
	return CallMethodAndReturn<float, 0x4CD370, CInventory*>(this);
}

float CInventory::GetMaxPsi()
{
	return CallMethodAndReturn<float, 0x50CE60, CInventory*>(this);
}

CWeapon* CInventory::GetWeapon()
{
	return CallMethodAndReturn<CWeapon*, 0x425390, CInventory*>(this);
}

void CInventory::AdjustAmmo(float ammo)
{
	CallMethod<0x5343A0, CInventory*, float>(this, ammo);
}