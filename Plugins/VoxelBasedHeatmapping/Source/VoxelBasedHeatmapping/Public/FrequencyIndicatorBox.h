// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "FrequencyIndicatorBox.generated.h"

UCLASS()
class AFrequencyIndicatorBox : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFrequencyIndicatorBox();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere)
		USceneComponent* Scene;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
		UMaterialInstanceDynamic* DynamicMaterial = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Value;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float BaseOpacity = 0.01f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float OpacityMultiplier = 0.1f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float PlayerDistanceRenderingThreshold = 800.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Hits;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<class AFrequencyIndicatorBox*> AdjacentBoxes;

	UFUNCTION()
		int GetHitsIncludingAdjacentBoxes(int AdjacencyJumps = 1);

	UFUNCTION()
		void SetValue(float NewValue);

	void GetHeatMapColor(float HeatValue, float *red, float *green, float *blue);

};
