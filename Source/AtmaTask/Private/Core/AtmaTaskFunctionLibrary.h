// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AtmaTaskFunctionLibrary.generated.h"

class AAtmaTaskPlayerController;
/**
 * 
 */
UCLASS()
class UAtmaTaskFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AtmaTask", meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	static AAtmaTaskPlayerController* GetAtmaTaskPlayerController(UObject* WorldContextObject);
	
};
