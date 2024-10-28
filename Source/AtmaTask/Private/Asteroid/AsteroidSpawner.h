#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AsteroidSpawner.generated.h"

class AAsteroid;

UCLASS()
class AAsteroidSpawner : public AActor
{
	GENERATED_BODY()
	
public:
	AAsteroidSpawner();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AtmaTask|Asteroid")
	TSubclassOf<AAsteroid> AsteroidClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AtmaTask|Asteroid")
	TSubclassOf<AAsteroid> BackgroundAsteroidClass;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AtmaTask|Asteroid")
	float SpawnInterval = 1.0f;

private:
	FTimerHandle AsteroidSpawnTimerHandle;
	FTimerHandle BackgroundAsteroidSpawnTimerHandle;
	
	void SpawnAsteroid();
	void SpawnBackgroundAsteroid();

};
