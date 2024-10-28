#include "Core/AtmaTaskGameInstance.h"
#include "AtmaTaskSaveGame.h"
#include "Kismet/GameplayStatics.h"
#include "Player/AtmaTaskPlayerController.h"

void UAtmaTaskGameInstance::Init()
{
	Super::Init();

	LoadScore();
	UE_LOG(LogTemp, Warning, TEXT("Wins: %d, Losses: %d"), Wins, Losses);
}

void UAtmaTaskGameInstance::EndGame(bool bIsWin)
{
	// Update and save score
	bIsWin ? Wins++ : Losses++;
	SaveScore();

	// Pause game, show end game screen
	UGameplayStatics::SetGamePaused(GetWorld(), true);

	// Show end game screen
	AAtmaTaskPlayerController* PlayerController = Cast<AAtmaTaskPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	PlayerController->ShowEndGameScreen(bIsWin);
}

void UAtmaTaskGameInstance::SaveScore()
{
	UAtmaTaskSaveGame* SaveGameInstance = Cast<UAtmaTaskSaveGame>(UGameplayStatics::CreateSaveGameObject(UAtmaTaskSaveGame::StaticClass()));
	if (SaveGameInstance)
	{
		SaveGameInstance->Wins = Wins;
		SaveGameInstance->Losses = Losses;
		UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("AtmaTaskSlot"), 0);
	}
}

void UAtmaTaskGameInstance::LoadScore()
{
	UAtmaTaskSaveGame* LoadGameInstance = Cast<UAtmaTaskSaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("AtmaTaskSlot"), 0));
	if (LoadGameInstance)
	{
		Wins = LoadGameInstance->Wins;
		Losses = LoadGameInstance->Losses;
	}
}
