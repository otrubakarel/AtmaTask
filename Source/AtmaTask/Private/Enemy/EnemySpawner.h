#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

class AEnemyShip;

UCLASS()
class AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	AEnemySpawner();

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AtmaTask|Enemy")
	TSubclassOf<AEnemyShip> EnemyClass;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AtmaTask|Enemy")
	float SpawnInterval = 6.0f;

private:
	FTimerHandle EnemySpawnTimerHandle;
	
	void SpawnEnemy();

};
