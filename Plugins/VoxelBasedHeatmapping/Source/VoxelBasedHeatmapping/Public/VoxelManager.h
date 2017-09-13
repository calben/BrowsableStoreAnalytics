// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "VoxelManager.generated.h"

UCLASS()
class AVoxelManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AVoxelManager();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float SpacingBetweenPoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector Origin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int TotalHits = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<class AFrequencyIndicatorBox*> IndicatorBoxes;

	FTimerHandle SetManagedBoxesValuesTimer;

	TMap<FVector, AActor*> ManagedActorsMap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<AActor> ActorType;

	UFUNCTION()
		AActor* GetActorAtLocation(FVector Location); //! returns null if no actor there

	UFUNCTION()
		AActor* PlaceActorForLocation(FVector Location, bool bPlaceAdjacentBoxes = true, int AdjacencyJumps = 1); //! returns null if fail

	UFUNCTION()
		FVector GetGridLocationForOffGridLocation(FVector Location);

	UFUNCTION()
		void SetManagedBoxesValues();
};
