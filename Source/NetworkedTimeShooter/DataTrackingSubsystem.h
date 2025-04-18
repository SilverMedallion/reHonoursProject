// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "DataTrackingSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class NETWORKEDTIMESHOOTER_API UDataTrackingSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Liam Laverty|1 - Write File")
		 void WriteToFile(); 

	UFUNCTION(BlueprintCallable)
		void AddToDataArray(const FString InputData);


	TArray<FString> data; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TotalHeadshots = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TotalBodyshots = 0;


	
};
