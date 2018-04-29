// Fill out your copyright notice in the Description page of Project Settings.

#include "blueprintTestProject.h"
#include "GameController.h"
#include "SoundVisComponent.h"


// Sets default values
AGameController::AGameController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGameController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGameController::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AGameController::DeleteEnemiesArray(TArray<AActor * >  toDelete)
{
	for (AActor* Actor : toDelete)
	{
		if (ensure(Actor)) {
			Actor->Destroy();
		}
	}
	toDelete.Empty();
}

FTransform AGameController::GetWorldTransform(float MaxSpawnOffset, UStaticMeshComponent * EnemySpawnPoint)
{
	auto loc = EnemySpawnPoint->GetComponentLocation();
	auto rot = EnemySpawnPoint->GetComponentRotation();

	FVector newVec(0.0, FMath::RandRange(MaxSpawnOffset * -1, MaxSpawnOffset), 0.0);
	newVec = AGameController::GetActorRotation().UnrotateVector(newVec);
	return FTransform(rot, newVec + loc, FVector( 1, 1, 1));
}

/// FOR MUSIC MODE ONLY
void AGameController::UpdateDynMaterials(TArray<float> Frequencies, USoundWave * ToAnalyze) {
	//getting current values for frequencies
	float SubBassValue, BassValue, LowMidValue, MidValue, UpperMidValue, PresenceValue, BrillianceValue;

	USoundVisComponent::BP_GetAverageSubBassValue(ToAnalyze, Frequencies, SubBassValue);
	USoundVisComponent::BP_GetAverageBassValue(ToAnalyze, Frequencies, BassValue);
	GetAverageLowMidValue(ToAnalyze, Frequencies, LowMidValue);
	GetAverageMidValue(ToAnalyze, Frequencies, MidValue);
	GetAverageUpperMidValue(ToAnalyze, Frequencies, UpperMidValue);
	GetAveragePresenceValue(ToAnalyze, Frequencies, PresenceValue);
	GetAverageBrillianceValue(ToAnalyze, Frequencies, BrillianceValue);
	
	//setting material parameters by average values
	UpdateMaterial(SubBass, SubBassValue, SubBassValueMax, SubBassValueMin);
	UpdateMaterial(Bass, BassValue, BassValueMax, BassValueMin);
	UpdateMaterial(LowMid, LowMidValue, LowMidValueMax, LowMidValueMin);
	UpdateMaterial(Mid, MidValue, MidValueMax, MidValueMin);
	UpdateMaterial(UpperMid, UpperMidValue, UpperMidValueMax, UpperMidValueMin);
	UpdateMaterial(Presence, PresenceValue, PresenceValueMax, PresenceValueMin);
	UpdateMaterial(Brilliance, BrillianceValue, BrillianceValueMax, BrillianceValueMin);
	/*UE_LOG(LogTemp, Warning, TEXT("SubBass : %f, Bass : %f, LowMid  : %f, Mid : %f, UpperMid : %f, Presence : %f,"
		"Brilliance : %f"), SubBassValue, BassValue, LowMidValue, MidValue, UpperMidValue, PresenceValue, BrillianceValue);*/
}

void AGameController::UpdateMaterial(UMaterialInstanceDynamic* ToUpdate, float Value, float & MaxValue, float & MinValue) {
	if (MaxValue < Value) {
		MaxValue = Value;
	}
	//if (MinValue > Value || MinValue == 0) {
		MinValue = MaxValue - 10;
	//}
	//float cur;
	ToUpdate->SetScalarParameterValue("Brigtness", ArrowBrightnessMultiplyValue * (Value - MinValue) / (MaxValue  - MinValue));
	//FMath::FInterpTo(cur, 0.05 *  (Value - MinValue) / (MaxValue - MinValue), 0.1, 4)
	//ToUpdate->GetScalarParameterValue("Speed", cur);
	if (bArrowsMovementEnabled) {
		ToUpdate->SetScalarParameterValue("Speed",
			ArrowMovementAddSpeed + ArrowMovementMultiplySpeed *  (Value - MinValue) / (MaxValue - MinValue));
	}
}

void AGameController::SetFreqDataToDEfaults() {
	SubBassValueMax = BassValueMax = LowMidValueMax =  MidValueMax =  UpperMidValueMax = 
		PresenceValueMax = BrillianceValueMax = 0;

	SubBassValueMin =  BassValueMin =  LowMidValueMin = MidValueMin =  UpperMidValueMin = 
		PresenceValueMin =  BrillianceValueMin = 0;
}

void AGameController::GetAverageLowMidValue(USoundWave* InSoundWave, TArray<float> InFrequencies, float& OutAverageLowMid) {
	USoundVisComponent::BP_GetAverageFrequencyValueInRange(InSoundWave, InFrequencies, 250, 500, OutAverageLowMid);
}

void AGameController::GetAverageMidValue(USoundWave* InSoundWave, TArray<float> InFrequencies, float& OutAverageMid) {
	USoundVisComponent::BP_GetAverageFrequencyValueInRange(InSoundWave, InFrequencies, 500, 2000, OutAverageMid);
}

void AGameController::GetAverageUpperMidValue(USoundWave* InSoundWave, TArray<float> InFrequencies, float& OutAverageUpperMid) {
	USoundVisComponent::BP_GetAverageFrequencyValueInRange(InSoundWave, InFrequencies, 2000, 4000, OutAverageUpperMid);
}

void AGameController::GetAverageBrillianceValue(USoundWave* InSoundWave, TArray<float> InFrequencies, float& OutAverageBrilliance) {
	USoundVisComponent::BP_GetAverageFrequencyValueInRange(InSoundWave, InFrequencies, 6000, 20000, OutAverageBrilliance);
}

void AGameController::GetAveragePresenceValue(USoundWave* InSoundWave, TArray<float> InFrequencies, float& OutAveragePresence) {
	USoundVisComponent::BP_GetAverageFrequencyValueInRange(InSoundWave, InFrequencies, 4000, 6000, OutAveragePresence);
}