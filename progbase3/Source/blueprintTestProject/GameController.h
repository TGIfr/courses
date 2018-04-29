// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "GameController.generated.h"

UCLASS()
class BLUEPRINTTESTPROJECT_API AGameController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameController();

	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintCallable, Category = GameFlowControl)
	void DeleteEnemiesArray(TArray<AActor * >  toDelete);
	
	UFUNCTION(BlueprintCallable, Category = GameFlowControl)
	FTransform GetWorldTransform(float MaxSpawnOffset, UStaticMeshComponent * EnemySpawnPoint);



	///   FOR MUSIC MODE ONLY ///

private:
	//used for updatedynmaterials
	float SubBassValueMax = 0, BassValueMax = 0, LowMidValueMax = 0, MidValueMax = 0, UpperMidValueMax = 0,
		PresenceValueMax = 0, BrillianceValueMax = 0;

	float SubBassValueMin = 0, BassValueMin = 0, LowMidValueMin = 0, MidValueMin = 0, UpperMidValueMin = 0,
		PresenceValueMin = 0, BrillianceValueMin = 0;

	void UpdateMaterial(UMaterialInstanceDynamic* ToUpdate, float Value, float & MaxValue, float & MinValue);

	void GetAverageLowMidValue(USoundWave* InSoundWave, TArray<float> InFrequencies, float& OutAverageLowMid);

	void GetAverageMidValue(USoundWave* InSoundWave, TArray<float> InFrequencies, float& OutAverageMid);

	void GetAverageUpperMidValue(USoundWave* InSoundWave, TArray<float> InFrequencies, float& OutAverageUpperMid);

	void GetAverageBrillianceValue(USoundWave* InSoundWave, TArray<float> InFrequencies, float& OutAverageBrilliance);

	void GetAveragePresenceValue(USoundWave* InSoundWave, TArray<float> InFrequencies, float& OutAveragePresence);

public:
	//FUNCTIONS//
	UFUNCTION(BlueprintCallable, Category = MusicControl)
	void UpdateDynMaterials(TArray<float> Frequencies, USoundWave * ToAnalyze);
	UFUNCTION(BlueprintCallable, Category = MusicControl)
	void SetFreqDataToDEfaults();

	//PROPERTIES//
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = MusicControl)
	float ArrowBrightnessMultiplyValue = 5;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = MusicControl)
	float ArrowMovementAddSpeed = 0.5;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = MusicControl)
	float ArrowMovementMultiplySpeed = 0.005;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = MusicControl)
	bool bArrowsMovementEnabled = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MusicControl)
	UMaterialInstanceDynamic* SubBass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MusicControl)
	UMaterialInstanceDynamic* Bass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MusicControl)
	UMaterialInstanceDynamic* LowMid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MusicControl)
	UMaterialInstanceDynamic* Mid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MusicControl)
	UMaterialInstanceDynamic* UpperMid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MusicControl)
	UMaterialInstanceDynamic* Brilliance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MusicControl)
	UMaterialInstanceDynamic* Presence;
};
