// Fill out your copyright notice in the Description page of Project Settings.


#include "Entity/Weapons/EntityWeapon.h"

// Sets default values
AEntityWeapon::AEntityWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEntityWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEntityWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

