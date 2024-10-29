#include "Enemy/EnemySpawner.h"

#include "EnemyShip.h"

AEnemySpawner::AEnemySpawner()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();

	// Create a timer to spawn enemies
	GetWorldTimerManager().SetTimer(EnemySpawnTimerHandle, this, &AEnemySpawner::SpawnEnemy, SpawnInterval, true, 1.0f);
}

void AEnemySpawner::SpawnEnemy()
{
	// Spawn an asteroid at a random location outside the screen
	FVector SpawnLocation = FVector(0.0f, FMath::RandRange(-2500.0f, 2500.0f), 2700.0f);
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	GetWorld()->SpawnActor<AEnemyShip>(EnemyClass, SpawnLocation, FRotator::ZeroRotator, SpawnParams);
}

