// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/AtmaTaskFunctionLibrary.h"

#include "Kismet/GameplayStatics.h"
#include "Player/AtmaTaskPlayerController.h"

AAtmaTaskPlayerController* UAtmaTaskFunctionLibrary::GetAtmaTaskPlayerController(UObject* WorldContextObject)
{
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(WorldContextObject, 0);
	return Cast<AAtmaTaskPlayerController>(PlayerController);
}
