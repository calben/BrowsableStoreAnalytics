// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <string>
#include <vector>

/**
 *
 */
template <class T>
class InfluxDbDataEntry
{
public:

	InfluxDbDataEntry(std::string Series, std::vector<std::string> Tags, std::string Name, T Value, long Time);
	~InfluxDbDataEntry();

	std::string Series;
	std::vector<std::string> Tags;
	std::string Name;
	T Value;
	long Time;

	FString GetSeriesAsFString();

	FString GetTagsAsFString();

	FString GetNameAsFString();

	FString GetValueAsFString();

	FString GetTimeAsFString();

	FString ToLineProtocolString();
};
