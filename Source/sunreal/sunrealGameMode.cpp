// Copyright Epic Games, Inc. All Rights Reserved.

#include "sunrealGameMode.h"
#include "sunrealHUD.h"
#include "sunrealCharacter.h"
#include "UObject/ConstructorHelpers.h"

AsunrealGameMode::AsunrealGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AsunrealHUD::StaticClass();
}
