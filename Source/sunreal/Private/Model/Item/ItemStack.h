#pragma once

#include "ItemStack.generated.h"

/**
 * ItemStack is a stack of items, which can be placed in a slot.
 */
USTRUCT(BlueprintType)
struct FItemStack
{
	GENERATED_BODY()

	UPROPERTY()
	int32 ItemId;

	UPROPERTY()
	int32 Quantity;

	FItemStack();
	
	FItemStack(int ItemId, int Quantity);

	void GetItemDefinition();
};
