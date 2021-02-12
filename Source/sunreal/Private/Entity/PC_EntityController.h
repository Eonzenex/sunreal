// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PC_EntityController.generated.h"

/**
 * 
 */
UCLASS()
class APC_EntityController : public APlayerController
{
	GENERATED_BODY()
	

// functions
public:
	APC_EntityController();

// variables
public:
	/** MKB yaw scale, in deg/sec. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera|MKB")
	float YawScaleMKB;

	/** MKB pitch scale, in deg/sec. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera|MKB")
	float PitchScaleMKB;

	/** CON yaw scale, in deg/sec. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera|Controller")
	float YawScaleCON;

	/** CON pitch scale, in deg/sec. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera|Controller")
	float PitchScaleCON;
};
