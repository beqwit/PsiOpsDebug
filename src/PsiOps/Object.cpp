#include "Object.h"

CRenderObject* CObject::GetRenderObject()
{
	return CallMethodAndReturn<CRenderObject*, 0x6DED70, CObject*>(this);
}

CDrawingObject* CObject::GetDrawingObject()
{
	return CallMethodAndReturn<CDrawingObject*, 0x402F60, CObject*>(this);
}

CBase* CObject::GetPhysicsObject()
{
	return CallMethodAndReturn<CBase*, 0x484740, CObject*>(this);
}

CVector3* CObject::GetWorldPosition(CVector3* result)
{
	return CallMethodAndReturn<CVector3*, 0x401310, CObject*, CVector3*>(this, result);
}

void CObject::SetWorldPosition(CVector3* result)
{
	return CallMethod<0x6DEA50, CObject*, CVector3*>(this, result);
}

bool CRenderObject::Visible()
{
	return CallMethodAndReturn<bool, 0x4403B0, CRenderObject*>(this);
}

bool CRenderObject::IsInSimulation()
{
	return CallMethodAndReturn<bool, 0x4017F0, CRenderObject*>(this);
}

void CRenderObject::SetActive(bool on)
{
	CallMethod<0x7447D0, CRenderObject*>(this);
}

CDrawState* CDrawingObject::GetDrawState()
{
	return CallMethodAndReturn<CDrawState*, 0x75A4C0, CDrawingObject*>(this);
}

void CDrawState::SetAlphaMode(int type)
{
	CallMethod<0x424950, CDrawState*, int, int>(this, type, 0);
}

void CDrawState::SetLightingMode(int type)
{
	CallMethod<0x42D510, CDrawState*, int, int>(this, type, 0);
}

void CDrawState::SetZBufferMode(int type)
{
	CallMethod<0x424980, CDrawState*, int, int>(this, type, 0);
}