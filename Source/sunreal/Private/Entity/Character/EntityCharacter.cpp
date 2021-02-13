// Fill out your copyright notice in the Description page of Project Settings.


#include "Entity/Character/EntityCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Engine/DemoNetDriver.h"
#include "Entity/Item/InventoryActorComponent.h"


AEntityCharacter::AEntityCharacter()
{
	bReplicates = true;

	// Set this character to call Tick() every frame.
	PrimaryActorTick.bCanEverTick = true;

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	// Create a CameraComponent	
	FPSCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FPSCamera"));
	FPSCamera->SetupAttachment(GetCapsuleComponent());
	FPSCamera->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.f)); // Position the camera
	FPSCamera->bUsePawnControlRotation = true;

	// Create skeletal mesh component
	FPSMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FPSMesh"));
	FPSMesh->SetOnlyOwnerSee(true);
	FPSMesh->SetupAttachment(FPSCamera);
	FPSMesh->bCastDynamicShadow = false;
	FPSMesh->CastShadow = false;
	FPSMesh->SetRelativeRotation(FRotator(1.9f, -19.19f, 5.2f));
	FPSMesh->SetRelativeLocation(FVector(-0.5f, -4.4f, -155.7f));

	// Create an inventory component
	Inventory = CreateDefaultSubobject<UInventoryActorComponent>(TEXT("Inventory"));
}

void AEntityCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AEntityCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Bind movement events
	PlayerInputComponent->BindAxis("MoveForBack", this, &AEntityCharacter::MoveForBack);
	PlayerInputComponent->BindAxis("MoveLeftRight", this, &AEntityCharacter::MoveLeftRight);

	// Bind camera events
	PlayerInputComponent->BindAxis("CameraPitch", this, &AEntityCharacter::CameraPitch);
	PlayerInputComponent->BindAxis("CameraYaw", this, &AEntityCharacter::CameraYaw);
	PlayerInputComponent->BindAxis("CameraPitchRate", this, &AEntityCharacter::CameraPitchRate);
	PlayerInputComponent->BindAxis("CameraYawRate", this, &AEntityCharacter::CameraYawRate);

	// Bind jump events
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
}


// Possess events
void AEntityCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	EntityController = Cast<APC_EntityController>(NewController);
}

void AEntityCharacter::UnPossessed()
{
	Super::UnPossessed();

	EntityController = NULL;
}


// Movement events
void AEntityCharacter::MoveForBack(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AEntityCharacter::MoveLeftRight(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(GetActorRightVector(), Value);
	}
}


// Camera events
void AEntityCharacter::CameraPitch(float Rate)
{
	AddControllerPitchInput(Rate * EntityController->PitchScaleMKB);
}

void AEntityCharacter::CameraPitchRate(float Rate)
{
	AddControllerPitchInput(Rate * EntityController->PitchScaleCON * GetWorld()->GetDeltaSeconds());
}

void AEntityCharacter::CameraYaw(float Rate)
{
	AddControllerYawInput(Rate * EntityController->YawScaleMKB);
}

void AEntityCharacter::CameraYawRate(float Rate)
{
	AddControllerYawInput(Rate * EntityController->YawScaleCON * GetWorld()->GetDeltaSeconds());
}


// Tick event
void AEntityCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}