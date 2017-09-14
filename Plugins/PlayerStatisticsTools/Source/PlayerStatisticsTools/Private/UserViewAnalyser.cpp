// Fill out your copyright notice in the Description page of Project Settings.

#include "UserViewAnalyser.h"
#include "VoxelManager.h"
#include "FrequencyIndicatorBox.h"
#include "MeshTargetingSystemComponent.h"
#include "ActorFloatPairWidget.h"
#include "UserAnalysisDashboardWidget.h"


// Sets default values for this component's properties
UUserViewAnalyser::UUserViewAnalyser()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UUserViewAnalyser::BeginPlay()
{
	Super::BeginPlay();

	MeshTargetingSystem = Cast<UMeshTargetingSystemComponent>(GetOwner()->GetComponentByClass(UMeshTargetingSystemComponent::StaticClass()));
	// ...

}

void UUserViewAnalyser::AddHitToViewedActors(AActor* actor)
{
	if (actor)
	{
		if (true)
		{
			int* RetrievedCount = ViewedActorsHitCounts.Find(actor);
			if (RetrievedCount)
			{
				ViewedActorsHitCounts[actor] = (*RetrievedCount) + 1;
			}
			else
			{
				ViewedActorsHitCounts.Add(actor, 1);
				if (FloatPairWidgetClass)
				{
					UActorFloatPairWidget* ActorFloatPairWidget = CreateWidget<UActorFloatPairWidget>(GetWorld(), FloatPairWidgetClass);
					if (ActorFloatPairWidget)
					{
						//ActorFloatPairWidget->AddToViewport();
						ViewedActorsFloatPairWidgets.Add(actor, ActorFloatPairWidget);
						ActorFloatPairWidget->Actor = actor;
						ActorFloatPairWidget->Value = 0.f;
						if (UserAnalysisDashboardWidget)
						{
							if (UserAnalysisDashboardWidget->ActorFloatPairVerticalBox)
							{
								UserAnalysisDashboardWidget->ActorFloatPairVerticalBox->AddChild(ActorFloatPairWidget);
							}
						}
					}
				}
			}
		}
	}
}

// Called every frame 
void UUserViewAnalyser::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//FHitResult f(ForceInit);
	//FVector start = this->GetComponentLocation();
	//FVector direction = this->GetForwardVector();
	//FCollisionQueryParams  params = FCollisionQueryParams(FName(TEXT("TargetingTrace")), true, NULL);
	//params.bTraceAsyncScene = true;
	//start = start + (direction * 10.0f);
	//FVector end = start + (direction * 2000.0f);
	//GetWorld()->LineTraceSingleByChannel(f, start, end, ECC_Visibility, params);
	if (bDrawDebug)
	{
		GetWorld()->DebugDrawTraceTag = "TargetingTrace";
	}

	if (bCountHitsPerActor)
	{
		if (MeshTargetingSystem->CurrentTarget != nullptr)
		{
			AddHitToViewedActors(MeshTargetingSystem->CurrentTarget);
			UpdateWidgets();
			UpdateScores();
		}
	}
}

void UUserViewAnalyser::UpdateWidgets()
{
	for (auto& Elem : ViewedActorsFloatPairWidgets)
	{
		UActorFloatPairWidget* Widget = Elem.Value;
		if (Widget)
		{
			Widget->Value = (float)*ViewedActorsHitCounts.Find(Elem.Key) / (float)VoxelManager->TotalHits;
		}
	}
	ViewedActorsHitCounts.ValueSort([](const int& A, const int& B) {
		return A > B;
	});
	if (UserAnalysisDashboardWidget)
	{
		if (UserAnalysisDashboardWidget->ActorFloatPairVerticalBox)
		{
			UserAnalysisDashboardWidget->ActorFloatPairVerticalBox->ClearChildren();
			for (auto& Elem : ViewedActorsHitCounts)
			{
				UActorFloatPairWidget** ActorFloatPairWidget = ViewedActorsFloatPairWidgets.Find(Elem.Key);
				if (ActorFloatPairWidget)
				{
					UserAnalysisDashboardWidget->ActorFloatPairVerticalBox->AddChild(*ActorFloatPairWidget);
				}
			}
		}
	}
}

void UUserViewAnalyser::UpdateScores()
{
	float sum = 0.f, mean, variance = 0.f, stdev = 0.f;

	TArray<float> Values;

	for (auto& Elem : ViewedActorsFloatPairWidgets)
	{
		UActorFloatPairWidget* Widget = Elem.Value;
		if (Widget)
		{
			Values.Add(Widget->Value);
		}
	}

	for (float v : Values)
	{
		sum += v;
	}

	mean = sum / (float)ViewedActorsFloatPairWidgets.Num();

	for (int v : Values)
		variance += pow(v - mean, 2);

	stdev = sqrt(variance / 10);

	JointAttentionScore = mean * 100;

	SearchSpecificity = variance * 100;

	SearchSensivity = stdev * 100;
}
