// Fill out your copyright notice in the Description page of Project Settings.


#include "Entity/PC_EntityController.h"


APC_EntityController::APC_EntityController()
{
	// camera sensitivity settings
	YawScaleMKB = 0.33f;
	PitchScaleMKB = 0.33f;

	YawScaleCON = 1.f;
	PitchScaleCON = 1.f;
}