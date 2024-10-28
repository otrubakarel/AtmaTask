#include "Asteroid/AsteroidSpawner.h"
#include "Asteroid.h"

AAsteroidSpawner::AAsteroidSpawner()
{
	PrimaryActorTick.bCanEverTick = false;

}

void AAsteroidSpawner::BeginPlay()
{
	Super::BeginPlay();

	// Create a timer to spawn asteroids
	GetWorldTimerManager().SetTimer(AsteroidSpawnTimerHandle, this, &AAsteroidSpawner::SpawnAsteroid, SpawnInterval, true);
	GetWorldTimerManager().SetTimer(BackgroundAsteroidSpawnTimerHandle, this, &AAsteroidSpawner::SpawnBackgroundAsteroid, SpawnInterval * 2.0f, true);
}

void AAsteroidSpawner::SpawnAsteroid()
{
	// Spawn an asteroid at a random location outside the screen
	FVector SpawnLocation = FVector(0.0f, FMath::RandRange(-2500.0f, 2500.0f), 3000.0f);
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	GetWorld()->SpawnActor<AAsteroid>(AsteroidClass, SpawnLocation, FRotator::ZeroRotator, SpawnParams);
}

void AAsteroidSpawner::SpawnBackgroundAsteroid()
{
	// Spawn a background asteroid at a random location outside the screen
	float RandomDepth = FMath::RandRange(7000.0f, 8000.0f);
	FVector SpawnLocation = FVector(RandomDepth, FMath::RandRange(-3500.0f, 3500.0f), 8000.0f);
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	GetWorld()->SpawnActor<AAsteroid>(BackgroundAsteroidClass, SpawnLocation, FRotator::ZeroRotator, SpawnParams);
}

