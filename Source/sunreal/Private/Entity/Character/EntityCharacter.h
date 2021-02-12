// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"

#include "../PC_EntityController.h"


#include "EntityCharacter.generated.h"


class USkeletalMeshComponent;


UCLASS()
class AEntityCharacter : public ACharacter
{
	GENERATED_BODY()


	/** First person mesh */
	UPROPERTY(EditAnywhere, Category="Mesh")
	USkeletalMeshComponent* FPSMesh;

	/** First person camera */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FPSCamera;


// functions
public:
	AEntityCharacter();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void PossessedBy(AController* NewController) override;
	virtual void UnPossessed() override;
	virtual void Tick(float DeltaTime) override;

	/** Returns Mesh1P subobject **/
	USkeletalMeshComponent* GetFPSMesh() const { return FPSMesh; }
	/** Returns FirstPersonCameraComponent subobject **/
	UCameraComponent* GetFPSCamera() const { return FPSCamera; }

protected:
	virtual void BeginPlay() override;


	/** Movement */
	/** Handles moving forward/backward */
	UFUNCTION()
	void MoveForBack(float Value);

	/** Handles stafing movement, left and right */
	UFUNCTION()
	void MoveLeftRight(float Value);


	/** Camera */
	/** Handles camera pitch */
	UFUNCTION()
	void CameraPitch(float Value);

	/** Handles camera pitch rate */
	UFUNCTION()
	void CameraPitchRate(float Value);

	/** Handles camera yaw */
	UFUNCTION()
	void CameraYaw(float Value);

	/** Handles camera yaw rate */
	UFUNCTION()
	void CameraYawRate(float Value);


// variables
protected:
	APC_EntityController* EntityController;
};
