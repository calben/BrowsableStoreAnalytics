// Fill out your copyright notice in the Description page of Project Settings.

#include "InfluxDbDataEntry.h"
#include <string>
#include <vector>
#include <sstream>

template <class T>
InfluxDbDataEntry<T>::InfluxDbDataEntry(std::string Series, std::vector<std::string> Tags, std::string Name, T Value, long Time)
{
	this->Series = Series;
	this->Tags = Tags;
	this->Name = Name;
	this->Value = Value;
	this->Time = Time;
}

template<class T>
InfluxDbDataEntry<T>::~InfluxDbDataEntry()
{
}

template<class T>
FString InfluxDbDataEntry<T>::GetSeriesAsFString()
{
	return FString(Series.c_str());
}

template<class T>
FString InfluxDbDataEntry<T>::GetTagsAsFString()
{
	std::stringstream convert;
	for (int i = 0; i < Tags.size(); i++)
	{
		convert << Tags[i];
		if (i < Tags.size() - 1)
		{
			convert << ",";
		}
	}
	return FString(convert.str().c_str());
}

template<class T>
FString InfluxDbDataEntry<T>::GetNameAsFString()
{
	return FString(Name.c_str());
}

template<class T>
FString InfluxDbDataEntry<T>::GetValueAsFString()
{
	std::stringstream convert;
	convert << Value;
	return FString(convert.str().c_str());
}

template<class T>
FString InfluxDbDataEntry<T>::GetTimeAsFString()
{
	std::stringstream convert;
	convert << Time;
	return FString(convert.str().c_str());
}

template<class T>
FString InfluxDbDataEntry<T>::ToLineProtocolString()
{
	std::stringstream convert;
	convert << Series << " " << Name << "=" << Value << " " << Time;
	return FString(convert.c_str());
}


