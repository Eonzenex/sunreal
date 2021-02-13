#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryAC.generated.h"

/**
 * UInventoryAC is a reusable actor component which allows interfacing with an Inventory object.
 * 
 * @see Inventory
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UInventoryAC : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryAC();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
