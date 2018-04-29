// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MusicModeEnemyShip1.generated.h"

UCLASS()
class BLUEPRINTTESTPROJECT_API AMusicModeEnemyShip1 : public AActor
{
	GENERATED_BODY()
	
private:

	float MovementSpeed;

	float Yaw = 0;

	FVector SpawnLocation;

public:
	// Sets default values for this actor's properties
	AMusicModeEnemyShip1();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = Movement)
		void SpawnAnimation(float Lerp);

	float TakeDamage(float Damage, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser);

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement)
		bool bMovementEnabled = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement)
		bool bMoveDirection = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Shooting)
		bool bCanReachPlayer = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HP)
		float Health = 100;

	
	
};
