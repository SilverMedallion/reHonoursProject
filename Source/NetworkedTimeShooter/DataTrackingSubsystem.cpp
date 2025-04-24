// Fill out your copyright notice in the Description page of Project Settings.


#include "DataTrackingSubsystem.h"

void UDataTrackingSubsystem::WriteToFile()
{

    /*
    AddToDataArray("total shots fired: " + FString::FromInt(TotalShotsFired));
    AddToDataArray("total headshots: " + FString::FromInt(TotalHeadshots));
    AddToDataArray("total bodyshots: " + FString::FromInt(TotalBodyshots));
    */

    AddToDataArray("TotalShotsFired,TotalHeadshots,TotalBodyshots");
    AddToDataArray(FString::Printf(TEXT("%d,%d,%d"), TotalShotsFired, TotalHeadshots, TotalBodyshots));
 
    // Find Results folder, if it does not exists create it
        const FString Path = FPaths::ConvertRelativePathToFull(FPaths::Combine(FPaths::ProjectSavedDir(), FString("Results")));
    IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
    if (!PlatformFile.DirectoryExists(*Path))
    {
        PlatformFile.CreateDirectory(*Path);
    }

    // Ensure unique file name based on date/time
    const FString Timestamp = FDateTime::Now().ToString(TEXT("%Y-%m-%d_%H-%M-%S"));
    const FString FileName = FString::Printf(TEXT("Round_%s.csv"), *Timestamp);
    const FString FullPath = FPaths::Combine(Path, FileName);

    FFileHelper::SaveStringArrayToFile(data, *FullPath);

    ResetTrackingData();

    /* OLD STUFF THAT WASN'T WORKING
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
	*/

	
}

void UDataTrackingSubsystem::AddToDataArray(const FString InputData)
{
	data.Add(InputData + LINE_TERMINATOR);

}

void UDataTrackingSubsystem::RegisterFiredShot()
{
    TotalShotsFired++;
}

void UDataTrackingSubsystem::RegisterBodyShot()
{
    TotalBodyshots++;
}

void UDataTrackingSubsystem::RegisterHeadShot()
{
    TotalHeadshots++;
}



void UDataTrackingSubsystem::ResetTrackingData()
{
    TotalShotsFired = 0;
    TotalHeadshots = 0;
    TotalBodyshots = 0;
    data.Empty(); // Clears previous strings if any
}

