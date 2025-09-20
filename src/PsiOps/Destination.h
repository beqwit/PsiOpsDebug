#pragma once
#include "PCore.h"

class CActorDestination;

class CDestination
{
public:
	CActorDestination* GetActorDestination();
};

class CActorDestination
{
	void AddActorToFlock(CBase* actor);
	CBase* GetActorFlock();
};