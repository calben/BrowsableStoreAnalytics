// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "ActorFloatPairWidget.generated.h"

/**
 *
 */
UCLASS()
class UActorFloatPairWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Value;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AActor* Actor;

};
