// Copyright Ignacio Martinez.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"

#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
public:
	void Elevate(float RelativeSpeed);
private:
	UPROPERTY(EditAnywhere, Category = "Setup")
	float MaxDegreesPerSecond = 10.0f;

	UPROPERTY(EditAnywhere, Category = "Setup")
	float MaxElevationDegrees = 40.0f;

	UPROPERTY(EditAnywhere, Category = "Setup")
	float MinEleveationDegrees = 0.0f;

};
