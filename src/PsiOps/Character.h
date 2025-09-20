#pragma once
#include "PCore.h"
#include "Object.h"

class CCharacter
{
public:
	char pad[0x4DC];
	bool m_bRip;
	void Hide(bool hide);
	bool IsDead();
	bool IsFallingDown();
	bool IsOnFire();
	void CatchFire();
	void Die();
	bool Energize(bool energize);
	bool SetIncinerate();

	CObject* GetRootAtom();
	CVector3* GetXZFacingVector(CVector3* result);
	CVector3* GetPos();
};