#include "Destination.h"
#include "../framework.h"

CActorDestination* CDestination::GetActorDestination()
{
	return CallMethodAndReturn<CActorDestination*, 0x73D2B0, CDestination*>(this);
}

void CActorDestination::AddActorToFlock(CBase* actor)
{
	CallMethod<0x73CF60, CActorDestination*, CBase*>(this, actor);
}

CBase* CActorDestination::GetActorFlock()
{
	return CallMethodAndReturn<CBase*, 0x412DE0, CActorDestination*>(this);
}