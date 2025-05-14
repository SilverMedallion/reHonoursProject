// Fill out your copyright notice in the Description page of Project Settings.


#include "SplitScreenFunctionLibrary.h"

void USplitScreenFunctionLibrary::DisableSplitScreen(AActor* Context, bool bDisable)
{
	if (Context)
	{
		Context->GetWorld()->GetGameViewport()->SetForceDisableSplitscreen(bDisable);
	}
}
