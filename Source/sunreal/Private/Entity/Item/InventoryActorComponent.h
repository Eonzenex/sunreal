#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Model/Item/ItemStack.h"
#include "InventoryActorComponent.generated.h"

/**
 * UInventoryActorComponent is a reusable actor component which allows interfacing with an Inventory object.
 * 
 * @see Inventory
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UInventoryActorComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(Replicated)
	int32 Rows;

	UPROPERTY(Replicated)
	int32 Cols;
	
	UPROPERTY()
	TArray<FItemStack> Items;
public:
	// Sets default values for this component's properties
	UInventoryActorComponent();

	UInventoryActorComponent(int32 Rows, int32 Cols);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	/** Get a 1D array index */
	int32 GetIndexFromRowCol(int32 Row, int32 Col) const;

	FItemStack GetItemInInventorySlot(int32 Row, int32 Col);

	void SetItemInInventorySlot(int32 Row, int32 Col, int32 ItemId, int32 ItemQuantity);

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;
};
