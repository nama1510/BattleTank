// Copyright Ignacio Martinez.

#include "Public/Tank.h"
#include "Particles/ParticleSystemComponent.h"

#include "BattleTank.h"



// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//DeathFire->bAutoActivate = false;
}
void ATank::BeginPlay() {
	Super::BeginPlay();
	CurrentHealth = StartingHealth;
}
float ATank::TakeDamage(float DamageAmount, FDamageEvent const &DamageEvent, AController *EventInstigator, AActor *DamageCauser)
{
	Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmount);
	int32 DamageToApply = FMath::Clamp(DamagePoints, 0, CurrentHealth);

	CurrentHealth -= DamageToApply;
	if (CurrentHealth <= 0) {
		//UE_LOG(LogTemp, Warning, TEXT("Tank DIED!"))
		//DeathFire->Activate();
		OnDeath.Broadcast();
	}
	return DamageToApply;
}
float ATank::GetHealthPercent() const
{
	return (float)CurrentHealth / (float)StartingHealth;
}