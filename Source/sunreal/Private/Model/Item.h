#pragma once

#include "Item.generated.h"

/**
 * FItem is the definition of an item.
 * An item can be used as an ingredient or interacted with within the game.
 */
USTRUCT(BlueprintType)
struct FItem
{
	GENERATED_BODY()

	/* Unique ID of the item. */
	UPROPERTY()
	int32 Id;

	/* Display name of the item. */
	UPROPERTY()
	FString Name;
	
	/* The max stackable quantity for this item. */
	UPROPERTY()
	int32 MaxQuantityPerSlot;

	FItem(int32, FString, int32);
};