#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AsteroidSpawner.generated.h"

UCLASS()
class AAsteroidSpawner : public AActor
{
	GENERATED_BODY()
	
public:
	AAsteroidSpawner();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AtmaTask|Asteroid")
	TSubclassOf<class AAsteroid> AsteroidClass;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AtmaTask|Asteroid")
	float SpawnInterval = 1.0f;

private:
	FTimerHandle SpawnTimerHandle;
	
	void SpawnAsteroid();

};