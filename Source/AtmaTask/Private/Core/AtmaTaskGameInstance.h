#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "AtmaTaskGameInstance.generated.h"

UCLASS()
class ATMATASK_API UAtmaTaskGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;

	UPROPERTY(BlueprintReadWrite, Category = "Score")
	int32 Wins = 0;
	
	UPROPERTY(BlueprintReadWrite, Category = "Score")
	int32 Losses = 0;

	UFUNCTION(BlueprintCallable, Category = "Score")
	void EndGame(bool bIsWin);

	// Load and save user score
	void SaveScore();
	void LoadScore();	
};
