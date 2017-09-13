// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InfluxDbDataEntry.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/UMG/Public/UMGStyle.h"
#include "Runtime/UMG/Public/Slate/SObjectWidget.h"
#include "Runtime/UMG/Public/IUMGModule.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "InfluxDbDataEntrySimpleWidget.generated.h"

/**
 *
 */
UCLASS()
class INFLUXDBTOOLS_API UInfluxDbDataEntrySimpleWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	InfluxDbDataEntry<float>* DataEntry;

	UFUNCTION(BlueprintCallable, BlueprintPure)
		FString GetDataEntrySeriesAsFString();

	UFUNCTION(BlueprintCallable, BlueprintPure)
		FString GetDataEntryTagsAsFString();

	UFUNCTION(BlueprintCallable, BlueprintPure)
		FString GetDataEntryNameAsFString();

	UFUNCTION(BlueprintCallable, BlueprintPure)
		FString GetDataEntryValueAsFString();

	UFUNCTION(BlueprintCallable, BlueprintPure)
		float GetDataEntryValueAsFloat();

	UFUNCTION(BlueprintCallable, BlueprintPure)
		FString GetDataEntryTimeAsFString();

};
