// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SplitScreenFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class NETWORKEDTIMESHOOTER_API USplitScreenFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

		UFUNCTION(BlueprintCallable, Category = "Viewport")
		static void DisableSplitScreen(AActor* Context, bool bDisable);


	
};
