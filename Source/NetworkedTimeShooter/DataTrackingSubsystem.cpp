// Fill out your copyright notice in the Description page of Project Settings.


#include "DataTrackingSubsystem.h"

void UDataTrackingSubsystem::WriteToFile()
{

    AddToDataArray("total headshots: " + TotalHeadshots);
    AddToDataArray("total bodyshots: " + TotalBodyshots);

 
    // Find Results folder, if it does not exists create it
        const FString Path = FPaths::ConvertRelativePathToFull(FPaths::Combine(FPaths::ProjectSavedDir(), FString("Results")));
    IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
    if (!PlatformFile.DirectoryExists(*Path))
    {
        PlatformFile.CreateDirectory(*Path);
    }

    // Find the correct participant number, based on the number of files in the directory
    TArray<FString> Results;
    PlatformFile.FindFiles(Results, *Path, TEXT(".csv"));
    int32 ParticipantNumber = 0;

    if (Results.Num() > 0)
    {
        ParticipantNumber = FMath::Floor((float)(Results.Num()) / 3.f);
    }

    // Prepare and write to file
    const FString FileName = FString::Printf(TEXT("Round%d.csv"), ParticipantNumber);
    const FString FullPath = FPaths::Combine(Path, FileName);


    FFileHelper::SaveStringArrayToFile(data, *FullPath);
	

	
}

void UDataTrackingSubsystem::AddToDataArray(const FString InputData)
{
	data.Add(InputData + LINE_TERMINATOR);

}

