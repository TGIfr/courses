// Fill out your copyright notice in the Description page of Project Settings.

#include "blueprintTestProject.h"
#include "PlayerShip.h"


// Sets default values
APlayerShip::APlayerShip()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerShip::BeginPlay()
{
	auto inst = AActor::GetInstigator();
	auto rot = inst->GetActorRotation();
	Yaw = rot.Yaw;
	SpawnLocation = APawn::GetActorLocation();
	Super::BeginPlay();
	
}

void APlayerShip::SpawnAnimation(float Lerp) {
	auto NewLocation = FMath::Lerp(SpawnLocation, SpawnLocation + FVector(0, 0, 60), Lerp);
	AActor::SetActorLocation(NewLocation);


	//auto NewRotation = FMath::Lerp(FVector(0, 0, 0), FVector(0, 0, Yaw + 720), Lerp);
	//UE_LOG(LogTemp, Warning, TEXT("Rotation  : %f  %f  %f"), NewRotation.X, NewRotation.Y, NewRotation.Z);
	AActor::SetActorRelativeRotation(FRotator(0, Yaw + 720 * Lerp, 0));
}

// Called every frame
void APlayerShip::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	if (bMovementEnabled) {
		//MOVEMENT
		HozSpeed = Movement(HozSpeed, MovementInput.X, DeltaTime);
		VerticalSpeed = Movement(VerticalSpeed, MovementInput.Y, DeltaTime);
		auto location = AActor::GetActorLocation();
		auto rotation = AActor::GetActorRotation();

		FRotator rotatorForLoc(0, Yaw, 0);
		FVector vec = rotatorForLoc.RotateVector(FVector(HozSpeed, 0, VerticalSpeed));
		AActor::SetActorLocation(location + vec);

		FRotator rotatorForRot(0, -10 * HozSpeed + Yaw, 0);
		auto finalRot = FMath::RInterpTo(rotation, rotatorForRot, DeltaTime, 4);
		AActor::SetActorRotation(finalRot);
		//Here Goes Clamp now not from blueprint

		//getting camera world location
		FVector cameraWorldLocation; //out
		FVector cameraWorldDirection; //out
		auto player = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		auto viewport = FVector2D(GEngine->GameViewport->Viewport->GetSizeXY());
		player->DeprojectScreenPositionToWorld(viewport.X, viewport.Y, cameraWorldLocation, cameraWorldDirection);

		//clamping the location
		auto curLoc = GetActorLocation();
		float resX;
		float resZ;
		resX = FMath::Clamp(curLoc.X, cameraWorldLocation.X * - 25, cameraWorldLocation.X * 25);
		resZ = FMath::Clamp(curLoc.Z, cameraWorldLocation.Z * - 25 / 12, cameraWorldLocation.Z * 25 / 6);
		SetActorLocation(FVector(resX, curLoc.Y, resZ));
		//UE_LOG(LogTemp, Warning, TEXT("Movent input : %f , %f, %f"), cameraWorldLocation.Z / 12, cameraWorldLocation.Z / 6, curLoc.Z);
		//curLoc = GetActorLocation();
		//UE_LOG(LogTemp, Warning, TEXT("Loc : %f , %f, %f"), resX, curLoc.Y, resZ);

		//SHIELD
		if (!bShieldDamaged) {
			ShieldHealth += ShieldHealRate * DeltaTime;
			if (ShieldHealth > MaxShieldHealth)
				ShieldHealth = MaxShieldHealth;
		}
	}

}

void APlayerShip::ShieldTimerExpired() {
	bShieldDamaged = false;
}

float APlayerShip::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser) {
	// Call the base class - this will tell us how much damage to apply  
	const float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

	//choose what to damage
	//last shield hit absorbs all the damage dealt
	if (ShieldHealth > 0) {
		ShieldHealth -= FMath::Clamp(ActualDamage, 0.f, MaxShieldHealth);
		if (ShieldHealth < 0) 
			ShieldHealth = 0;
	} else {
		Health -= FMath::Clamp(ActualDamage, 0.f, 100.f);
	}

	//kicks player
	HozSpeed *= -2;
	VerticalSpeed *= -2;

	//starts timer of shield recharge delay
	GetWorldTimerManager().SetTimer(shieldTimer, this, & APlayerShip::ShieldTimerExpired , ShieldChargeDelay, false);
	
	bShieldDamaged = true;

	//kills in case of death
	if (Health <= 0) {
		APlayerShip::Destroy();
		if (Explosion != nullptr) {
			UGameplayStatics::PlaySoundAtLocation(GetWorld(),  Explosion, APlayerShip::GetActorLocation());
		}
	}
	return ActualDamage;

}

void APlayerShip::MoveForward(float AxisValue) {
	MovementInput.Y = AxisValue;
}

void APlayerShip::MoveRight(float AxisValue) {
	MovementInput.X = AxisValue;
}

// Called to bind functionality to input
void APlayerShip::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAxis("MoveForward", this, &APlayerShip::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &APlayerShip::MoveRight);
}

float APlayerShip::Movement(float Speed, float Direction, float DeltaTime) {
	float interp = FMath::FInterpTo(Speed, Direction * MovementSpeed * DeltaTime, DeltaTime, 4);
	//if (Speed != 0 || Direction != 0) {
	//	UE_LOG(LogTemp, Warning, TEXT("Movent input : %d , %d, %d"), Speed, Direction, DeltaTime);
	//	UE_LOG(LogTemp, Warning, TEXT("Movent returns : %d"), interp);
	//}
	return interp;
}
