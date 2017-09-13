// Fill out your copyright notice in the Description page of Project Settings.

#include "VoxelManager.h"
#include "FrequencyIndicatorBox.h"


// Sets default values
AVoxelManager::AVoxelManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AVoxelManager::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(SetManagedBoxesValuesTimer, this, &AVoxelManager::SetManagedBoxesValues, .1f, true);
}

// Called every frame
void AVoxelManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

AActor* AVoxelManager::GetActorAtLocation(FVector Location)
{
	//UE_LOG(LogTemp, Warning, TEXT("LOOKING FOR ACTOR AT LOCATION %s, MAP HAS %d ACTORS"), *Location.ToString(), ManagedActorsMap.Num());
	AActor** RetrievedActor = ManagedActorsMap.Find(Location);
	if (RetrievedActor)
	{
		//UE_LOG(LogTemp, Warning, TEXT("FOUND %s"), *((*RetrievedActor)->GetName()));
		return (*RetrievedActor);
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("FOUND NO ACTOR"));
		return nullptr;
	}
}

AActor* AVoxelManager::PlaceActorForLocation(FVector Location, bool bPlaceAdjacentBoxes, int AdjacencyJumps)
{
	AActor* PotentialExisting = GetActorAtLocation(Location);
	if (PotentialExisting == nullptr && ActorType != nullptr)
	{
		AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(ActorType, Location, FRotator::ZeroRotator);
		ManagedActorsMap.Add(Location, SpawnedActor);
		AFrequencyIndicatorBox* Box = Cast<AFrequencyIndicatorBox>(SpawnedActor);
		if (Box)
		{
			IndicatorBoxes.Add(Box);
			TArray<FVector> AdjacentPositions =
			{
				Location + FVector(SpacingBetweenPoints, 0.f, 0.f),
				Location + FVector(-SpacingBetweenPoints, 0.f, 0.f),
				Location + FVector(0.f,  SpacingBetweenPoints, 0.f),
				Location + FVector(0.f, -SpacingBetweenPoints, 0.f),
				Location + FVector(0.f, 0.f,  SpacingBetweenPoints),
				Location + FVector(0.f, 0.f, -SpacingBetweenPoints)
			};
			if (bPlaceAdjacentBoxes && AdjacencyJumps)
			{
				// spawns all the boxes recursively
				for (FVector Position : AdjacentPositions)
				{
					auto AdjacentBox = Cast<AFrequencyIndicatorBox>(PlaceActorForLocation(Position, true, AdjacencyJumps - 1));
				}
			}
			// post recursion, adds to adjacency lists
			if (bPlaceAdjacentBoxes)
			{
				for (FVector Position : AdjacentPositions)
				{
					//UE_LOG(LogTemp, Warning, TEXT("CHECKING ADJACENT"));
					auto AdjacentBox = Cast<AFrequencyIndicatorBox>(GetActorAtLocation(Position));
					if (AdjacentBox)
					{
						Box->AdjacentBoxes.Add(AdjacentBox);
						if (!AdjacentBox->AdjacentBoxes.Contains(Box))
						{
							AdjacentBox->AdjacentBoxes.Add(Box);
						}
					}
				}
			}
		}
		return SpawnedActor;
	}
	else
	{
		return nullptr;
	}
}

FVector AVoxelManager::GetGridLocationForOffGridLocation(FVector Location)
{
	const auto X = FMath::RoundToInt(((Location.X + SpacingBetweenPoints / 2) / SpacingBetweenPoints)) * SpacingBetweenPoints;
	const auto Y = FMath::RoundToInt(((Location.Y + SpacingBetweenPoints / 2) / SpacingBetweenPoints)) * SpacingBetweenPoints;
	const auto Z = FMath::RoundToInt(((Location.Z + SpacingBetweenPoints / 2) / SpacingBetweenPoints)) * SpacingBetweenPoints;
	return FVector(X, Y, Z);
}

void AVoxelManager::SetManagedBoxesValues()
{
	for (auto Box : IndicatorBoxes)
	{
		Box->SetValue(FMath::Clamp((float)Box->GetHitsIncludingAdjacentBoxes(2) / (float)TotalHits * 2, 0.f, 1.f));
	}
}

