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
}

void AAsteroidSpawner::SpawnAsteroid()
{
	// Spawn an asteroid at a random location outside of the screen
	FVector SpawnLocation = FVector(0.0f, FMath::RandRange(-2500.0f, 2500.0f), 3000.0f);
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	GetWorld()->SpawnActor<AAsteroid>(AsteroidClass, SpawnLocation, FRotator::ZeroRotator, SpawnParams);
}

void AAsteroidSpawner::SpawnBackgroundAsteroid()
{
	// TODO: Implement
}

