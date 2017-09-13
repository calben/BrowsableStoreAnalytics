// Fill out your copyright notice in the Description page of Project Settings.

#include "FrequencyIndicatorBox.h"
#include "EngineMinimal.h"

// Sets default values
AFrequencyIndicatorBox::AFrequencyIndicatorBox()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	RootComponent = Scene;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Scene);

}

// Called when the game starts or when spawned
void AFrequencyIndicatorBox::BeginPlay()
{
	Super::BeginPlay();

	if (Mesh)
	{
		DynamicMaterial = Mesh->CreateAndSetMaterialInstanceDynamic(0);;
		if (DynamicMaterial)
		{
			Mesh->SetMaterial(0, DynamicMaterial);
		}
	}
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "hello world from a new voxel");
}

// Called every frame
void AFrequencyIndicatorBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ACharacter* myCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	FVector PlayerLocation;
	if (myCharacter)
		PlayerLocation = myCharacter->GetActorLocation();
	//UE_LOG(LogTemp, Warning, TEXT("DISTANCE IS %f"), FVector::Dist(GetActorLocation(), PlayerLocation));
	if (FVector::Dist(GetActorLocation(), PlayerLocation) > PlayerDistanceRenderingThreshold)
	{
		Mesh->SetVisibility(false);
	}
	else
	{
		Mesh->SetVisibility(true);
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "hello world from a new voxel.  i should be visible.");
	}
}

void AFrequencyIndicatorBox::SetValue(float NewValue)
{
	Value = NewValue;
	//float r, g, b;
	//GetHeatMapColor(NewValue, &r, &g, &b);
	if (DynamicMaterial)
	{
		//DynamicMaterial->SetScalarParameterValue(FName("OpacityParam"), BaseOpacity + (Value * OpacityMultiplier));
		//DynamicMaterial->SetVectorParameterValue(FName("ColorParam"), FVector(r, g, b));
		DynamicMaterial->SetScalarParameterValue(FName("GradientParameter"), Value);
		//UE_LOG(LogTemp, Warning, TEXT("SETTING COLOUR TO %f %f %f for %f"), r, g, b, NewValue);
	}
}

int AFrequencyIndicatorBox::GetHitsIncludingAdjacentBoxes(int AdjacencyJumps)
{
	int Result = Hits;
	if (AdjacencyJumps)
	{
		for (AFrequencyIndicatorBox* box : AdjacentBoxes)
		{
			Result += box->GetHitsIncludingAdjacentBoxes(AdjacencyJumps - 1);
		}
	}
	return Result;
}

// based on
// http://www.andrewnoske.com/wiki/Code_-_heatmaps_and_color_gradients
//void AFrequencyIndicatorBox::GetHeatMapColor(float HeatValue, float *red, float *green, float *blue)
//{
//	const int NUM_COLORS = 4;
//	static float color[NUM_COLORS][3] = { { 0,0,1 }, { 0, 1, 0}, { 1,1,0 }, {1, 0, 0} };
//
//	int idx1;
//	int idx2;
//	float fractBetween = 0;
//
//	if (HeatValue <= 0) { idx1 = idx2 = 0; }
//	else if (HeatValue >= 1) { idx1 = idx2 = NUM_COLORS - 1; }
//	else
//	{
//		HeatValue = HeatValue * (NUM_COLORS - 1);
//		idx1 = floor(HeatValue);
//		idx2 = idx1 + 1;
//		fractBetween = HeatValue - float(idx1);
//	}
//
//	*red = (color[idx2][0] - color[idx1][0])*fractBetween + color[idx1][0];
//	*green = (color[idx2][1] - color[idx1][1])*fractBetween + color[idx1][1];
//	*blue = (color[idx2][2] - color[idx1][2])*fractBetween + color[idx1][2];
//}
