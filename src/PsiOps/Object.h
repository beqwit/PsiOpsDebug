#pragma once
#include "PCore.h"

class CRenderObject;
class CDrawingObject;
class CDrawState;

class CObject
{
public:
	CRenderObject* GetRenderObject();
	CDrawingObject* GetDrawingObject();

	CVector3* GetWorldPosition(CVector3* position);
	void SetWorldPosition(CVector3* position);

	CBase* GetPhysicsObject();
};

class CDrawingObject
{
public:
	CDrawState* GetDrawState();
};

class CDrawState
{
public:
	void SetAlphaMode(int type);
	void SetLightingMode(int type);
	void SetZBufferMode(int type);
};

class CRenderObject
{
public:
	bool Visible();
	bool IsInSimulation();
	void SetActive(bool on);
};