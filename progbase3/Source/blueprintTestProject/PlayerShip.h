// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "PlayerShip.generated.h"


UCLASS()
class BLUEPRINTTESTPROJECT_API APlayerShip : public APawn
{
	GENERATED_BODY()

private:
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void ShieldTimerExpired();

	float CurrentSpeed = 0;

	float HozSpeed = 0;

	float VerticalSpeed = 0;

	float MovementSpeed = 250;

	float Yaw = 0;

	FVector2D MovementInput;
	


	FVector SpawnLocation;

	FTimerHandle shieldTimer;

	bool bShieldDamaged;

	
public:
	// Sets default values for this pawn's properties
	APlayerShip();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	float TakeDamage(float Damage, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser);

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;


	float Movement(float Speed, float Direction, float DeltaTime);

	UFUNCTION(BlueprintCallable, Category = Movement)
	void SpawnAnimation(float Lerp);

	UPROPERTY(EditDefaultsOnly, Category = Sounds)
	USoundWave* Explosion;

	UPROPERTY(BlueprintReadOnly, Category = HP)
	float ShieldHealth = 100;

	UPROPERTY(BlueprintReadOnly, Category = HP)
	float Health = 100;

	UPROPERTY(EditDefaultsOnly, Category = Shield)
	float ShieldChargeDelay = 5;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Shield)
	float MaxShieldHealth = 100;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Shield)
	float ShieldHealRate = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement)
	bool bMovementEnabled = false;

};
