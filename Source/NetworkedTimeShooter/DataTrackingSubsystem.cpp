// Fill out your copyright notice in the Description page of Project Settings.


#include "DataTrackingSubsystem.h"

void UDataTrackingSubsystem::WriteToFile(FString FilePath, bool& bOutputSuccessful, FString& OutInfoMessage)
{
	//try to write to a file
	if (!FFileHelper::SaveStringArrayToFile(data, *FilePath)) {
		bOutputSuccessful = false;
		OutInfoMessage = FString::Printf(TEXT("Write to file failed - was not able to write to file. Is your file ready only? is the path valid - '%s'"), *FilePath);
		return;
	}

	bOutputSuccessful = true;
	OutInfoMessage = FString::Printf(TEXT("Write to file succeeded = '%s'"), *FilePath);
}

void UDataTrackingSubsystem::AddToDataArray(const FString InputData)
{
	data.Add(InputData);

}

