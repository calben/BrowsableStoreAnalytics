// Fill out your copyright notice in the Description page of Project Settings.

#include "InfluxDbDataEntrySimpleWidget.h"


FString UInfluxDbDataEntrySimpleWidget::GetDataEntrySeriesAsFString()
{
	if (this->DataEntry != nullptr)
	{
		return this->DataEntry->GetSeriesAsFString();
	}
	else
	{
		return FString("");
	}
}

FString UInfluxDbDataEntrySimpleWidget::GetDataEntryTagsAsFString()
{
	if (this->DataEntry != nullptr)
	{
		return this->DataEntry->GetTagsAsFString();
	}
	else
	{
		return FString("");
	}
}

FString UInfluxDbDataEntrySimpleWidget::GetDataEntryNameAsFString()
{
	if (this->DataEntry != nullptr)
	{
		return this->DataEntry->GetNameAsFString();
	}
	else
	{
		return FString("");
	}
}

FString UInfluxDbDataEntrySimpleWidget::GetDataEntryValueAsFString()
{
	if (this->DataEntry != nullptr)
	{
		return this->DataEntry->GetValueAsFString();
	}
	else
	{
		return FString("");
	}
}

float UInfluxDbDataEntrySimpleWidget::GetDataEntryValueAsFloat()
{
	if (this->DataEntry != nullptr)
	{
		return this->DataEntry->Value;
	}
	else
	{
		return 0.f;
	}
}

FString UInfluxDbDataEntrySimpleWidget::GetDataEntryTimeAsFString()
{
	if (this->DataEntry != nullptr)
	{
		return this->DataEntry->GetTimeAsFString();
	}
	else
	{
		return FString("");
	}
}

