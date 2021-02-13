// Fill out your copyright notice in the Description page of Project Settings.


#include "Entity/Item/InventoryActorComponent.h"

#include "Engine/DemoNetDriver.h"

// Sets default values for this component's properties
UInventoryActorComponent::UInventoryActorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	
	this->Rows = 5;
	this->Cols = 10;

	Items.Init(FItemStack(0, 0), Rows*Cols*sizeof(FItemStack));
	
	for(int Row = 0; Row < this->Rows; Row++)
	{
		for(int Col = 0; Col < this->Cols; Col++)
		{
			Items[GetIndexFromRowCol(Row, Col)] = FItemStack(0, 0);
		}
	}
}

UInventoryActorComponent::UInventoryActorComponent(const int32 Rows=5, const int32 Cols=10)
{
	PrimaryComponentTick.bCanEverTick = false;
	
	this->Rows = Rows;
	this->Cols = Cols;

	Items.Init(FItemStack(0, 0), Rows*Cols*sizeof(FItemStack));
	
	for(int Row = 0; Row < this->Rows; Row++)
	{
		for(int Col = 0; Col < this->Cols; Col++)
		{
			const int32 Index = GetIndexFromRowCol(Row, Col);
			Items[Index] = FItemStack(0, 0);
		}
	}
}

// Called when the game starts
void UInventoryActorComponent::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void UInventoryActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

// Inventory Functions
int32 UInventoryActorComponent::GetIndexFromRowCol(const int32 Row, const int32 Col) const
{
	return (Row * this->Cols) + Col;
}

FItemStack UInventoryActorComponent::GetItemInInventorySlot(int32 Row, int32 Col)
{
	const int32 Index = GetIndexFromRowCol(Row, Col);
	return Items[Index];
}

void UInventoryActorComponent::SetItemInInventorySlot(int32 Row, int32 Col, int32 ItemId, int32 ItemQuantity)
{
	const FItemStack ItemStack = FItemStack(ItemId, ItemQuantity);
	const int32 Index = GetIndexFromRowCol(Row, Col);
	Items[Index] = ItemStack;
}

void UInventoryActorComponent::GetLifetimeReplicatedProps( TArray< FLifetimeProperty > & OutLifetimeProps ) const
{
	DOREPLIFETIME( AActor, GetOwner() );
}
