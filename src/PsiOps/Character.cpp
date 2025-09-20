#include "Character.h"
#include "../framework.h"

void CCharacter::Hide(bool hide)
{
	CallMethod<0x6E75A0, CCharacter*, bool>(this, hide);
}

bool CCharacter::IsDead()
{
	return CallMethodAndReturn<bool, 0x403240, CCharacter*>(this);
}

bool CCharacter::IsFallingDown()
{
	return CallMethodAndReturn<bool, 0x412420, CCharacter*>(this);
}

bool CCharacter::IsOnFire()
{
	return CallMethodAndReturn<bool, 0x6DCF40, CCharacter*>(this);
}

void CCharacter::Die()
{
	CallMethod<0x725010, CCharacter*>(this);
}

void CCharacter::CatchFire()
{
	return CallMethod<0x6EAFB0, CCharacter*>(this);
}

bool CCharacter::SetIncinerate()
{
	return CallMethodAndReturn<bool, 0x4030A0, CCharacter*>(this);
}

bool CCharacter::Energize(bool energize)
{
	return CallMethodAndReturn<bool, 0x6E7ED0, CCharacter*, bool>(this, energize);
}

CVector3* CCharacter::GetXZFacingVector(CVector3* result)
{
	return CallMethodAndReturn<CVector3*, 0x6E9920, CCharacter*, CVector3*>(this, result);
}

CObject* CCharacter::GetRootAtom()
{
	return CallMethodAndReturn<CObject*, 0x401810, CCharacter*>(this);
}

CVector3* CCharacter::GetPos()
{
	CObject* rootAtom = GetRootAtom();
	CVector3 result;

	rootAtom->GetWorldPosition(&result);

	return &result;
}


