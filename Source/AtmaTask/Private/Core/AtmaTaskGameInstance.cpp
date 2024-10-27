#include "Core/AtmaTaskGameInstance.h"

#include "AtmaTaskSaveGame.h"
#include "Kismet/GameplayStatics.h"

void UAtmaTaskGameInstance::Init()
{
	Super::Init();

	LoadScore();
}

void UAtmaTaskGameInstance::SaveScore()
{
	UAtmaTaskSaveGame* SaveGameInstance = Cast<UAtmaTaskSaveGame>(UGameplayStatics::CreateSaveGameObject(UAtmaTaskSaveGame::StaticClass()));
	if (SaveGameInstance)
	{
		SaveGameInstance->Wins = Wins;
		SaveGameInstance->Losses = Losses;
		UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("AtmaTaskSlot1"), 0);
	}
}

void UAtmaTaskGameInstance::LoadScore()
{
	UAtmaTaskSaveGame* LoadGameInstance = Cast<UAtmaTaskSaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("AtmaTaskSlot1"), 0));
	if (LoadGameInstance)
	{
		Wins = LoadGameInstance->Wins;
		Losses = LoadGameInstance->Losses;
	}
}
