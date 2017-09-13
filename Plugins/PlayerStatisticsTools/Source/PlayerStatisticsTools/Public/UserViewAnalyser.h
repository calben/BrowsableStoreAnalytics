//// Fill out your copyright notice in the Description page of Project Settings.
//
//#pragma once
//
//#include "Components/SceneComponent.h"
//#include "UserViewAnalyser.generated.h"
//
//
//UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
//class USERANALYSISTOOLKIT_API UUserViewAnalyser : public USceneComponent
//{
//	GENERATED_BODY()
//
//public:
//	// Sets default values for this component's properties
//	UUserViewAnalyser();
//
//	// Called when the game starts
//	virtual void BeginPlay() override;
//
//	// Called every frame
//	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//		TSubclassOf<AActor> LookAtIndicatorActor;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//		class AVoxelManager* VoxelManager = nullptr;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//		class UMeshTargetingSystemComponent* MeshTargetingSystem;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//		TSubclassOf<class UActorFloatPairWidget> FloatPairWidgetClass;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//		class UUserAnalysisDashboardWidget* UserAnalysisDashboardWidget;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//		bool bPlaceVoxels = true;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//		bool bCountHitsPerActor = true;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//		bool bDrawDebug;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//		TMap<AActor*, int> ViewedActorsHitCounts;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//		TMap<AActor*, class UActorFloatPairWidget*> ViewedActorsFloatPairWidgets;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//		TMap<FString, int> ViewedTagsHitCounts;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//		TMap<FString, class UStringFloatPairWidget*> ViewedTagsFloatPairWidgets;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//		float JointAttentionScore;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//		float SearchSpecificity;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//		float SearchSensivity;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//		float MeanProductAttention;
//
//	UFUNCTION()
//		void AddHitToViewedActors(AActor* actor);
//
//	UFUNCTION()
//		void UpdateWidgets();
//
//	UFUNCTION()
//		void UpdateScores();
//
//};
