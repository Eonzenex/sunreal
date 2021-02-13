#pragma once

/**
 * ItemStack is a stack of items, which can be placed in a slot.
 */
USTRUCT()
struct FItemStack
{
	GENERATED_BODY()

	UPROPERTY()
	int32 ItemId;

	UPROPERTY()
	int32 Quantity;

	FItemStack(int32, int32);

	void GetItemDefinition();
};
