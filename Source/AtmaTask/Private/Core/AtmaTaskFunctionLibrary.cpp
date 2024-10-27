// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/AtmaTaskFunctionLibrary.h"

#include "AtmaTaskGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Player/AtmaTaskPlayerController.h"

AAtmaTaskPlayerController* UAtmaTaskFunctionLibrary::GetAtmaTaskPlayerController(UObject* WorldContextObject)
{
	return Cast<AAtmaTaskPlayerController>(UGameplayStatics::GetPlayerController(WorldContextObject, 0));
}

UAtmaTaskGameInstance* UAtmaTaskFunctionLibrary::GetAtmaTaskGameInstance(UObject* WorldContextObject)
{
	return Cast<UAtmaTaskGameInstance>(UGameplayStatics::GetGameInstance(WorldContextObject));
}
