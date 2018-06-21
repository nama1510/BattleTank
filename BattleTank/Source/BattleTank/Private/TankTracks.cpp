// Copyright Ignacio Martinez.

#include "Public/TankTracks.h"
#include "Components/PrimitiveComponent.h"
void UTankTracks::SetThrottle(float Throttle) {

	//UE_LOG(LogTemp, Warning, TEXT("%s throttle: %f"), *GetName(), Throttle);

	Throttle = FMath::Clamp<float>(Throttle, -1, 1);

	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}



