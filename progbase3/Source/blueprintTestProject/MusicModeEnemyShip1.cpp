// Fill out your copyright notice in the Description page of Project Settings.

#include "blueprintTestProject.h"
#include "MusicModeEnemyShip1.h"


// Sets default values
AMusicModeEnemyShip1::AMusicModeEnemyShip1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AMusicModeEnemyShip1::SpawnAnimation(float Lerp) {
	auto NewLocation = FMath::Lerp(SpawnLocation, SpawnLocation + FVector(0, 0, -60), Lerp);
	AActor::SetActorLocation(NewLocation);

	auto NewRotation = FMath::Lerp(FVector(0, 0, 0), FVector(0, 0, Yaw + 720), Lerp);
	//UE_LOG(LogTemp, Warning, TEXT("Rotation  : %f  %f  %f"), NewRotation.X, NewRotation.Y, NewRotation.Z);

	AActor::SetActorRelativeRotation(FRotator(0, 360 * Lerp, 0));
}

float AMusicModeEnemyShip1::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser) {
	// Call the base class - this will tell us how much damage to apply  

	Health -= FMath::Clamp(Damage, 0.f, 100.f);
	const float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
	return ActualDamage;
}

// Called when the game starts or when spawned
void AMusicModeEnemyShip1::BeginPlay()
{
	//CAUSES ERRORS
	//auto inst = AEnemyShip_1::GetInstigator();
	//if (!ensure(inst)) {
	//	UE_LOG(LogTemp, Warning, TEXT("instigator caput"));
	//}
	//auto rot = inst->GetActorRotation();
	//Yaw = rot.Yaw;

	auto inst = AMusicModeEnemyShip1::GetOwner();
	auto rot = inst->GetActorRotation();
	Yaw = rot.Yaw;
	SpawnLocation = AMusicModeEnemyShip1::GetActorLocation();

	//UE_LOG(LogTemp, Warning, TEXT("spawn loc %f %f %f"), SpawnLocation.X, SpawnLocation.Y, SpawnLocation.Z);
	bMoveDirection = FMath::RandRange(0, 1) == 0;
	MovementSpeed = FMath::FRandRange(25, 200);

	Super::BeginPlay();
	
}

// Called every frame
void AMusicModeEnemyShip1::Tick( float DeltaTime )
{
	Super::Tick(DeltaTime);
	if (bMovementEnabled) {

		int dir = bMoveDirection ? 1 : -1;

		FRotator rotatorForLoc(0, Yaw, 0);
		FVector vec = rotatorForLoc.RotateVector(FVector(0, MovementSpeed * dir, 0) * DeltaTime);
		AActor::SetActorLocation(vec + AActor::GetActorLocation(), true);

		//checks if enemy ship is close enough to player
		auto Player = GetWorld()->GetFirstPlayerController()->GetPawn();
		if (!ensure(Player)) {
			bCanReachPlayer = false;
			return;
		}

		auto difInLocs = Player->GetActorLocation() - this->GetActorLocation();
		bCanReachPlayer = FMath::Abs(difInLocs.X) <= 120 ? true : false;
	}

}

