// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/GameStateBase.h"
#include "Model/Item/Item.h"

/**
 * Global game state.
 */
class ASunrealGameState: AGameStateBase
{
private:
	TMap<int32, FItem> ItemDefinitions;
	
public:
	ASunrealGameState();

	FItem GetItemById(int32 Id);
};
