#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "AtmaTaskSaveGame.generated.h"

UCLASS()
class ATMATASK_API UAtmaTaskSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category = "Score")
	int32 Wins;

	UPROPERTY(BlueprintReadWrite, Category = "Score")
	int32 Losses;
};
