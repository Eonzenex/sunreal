#include "sunrealGameState.h"

ASunrealGameState::ASunrealGameState()
{
	ItemDefinitions[0] = FItem("Air", 0);
	ItemDefinitions[1] = FItem("Berry", 32);
}

FItem ASunrealGameState::GetItemById(int32 Id)
{
	if(ItemDefinitions.Contains(Id))
	{
		return ItemDefinitions[Id];
	}

	return FItem("Null", 0);
}