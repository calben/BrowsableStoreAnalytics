// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/UMG.h"
#include "UserAnalysisDashboardWidget.generated.h"

/**
 *
 */
UCLASS()
class UUserAnalysisDashboardWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UVerticalBox* ActorFloatPairVerticalBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UUserViewAnalyser* UserViewAnalyser;

};
