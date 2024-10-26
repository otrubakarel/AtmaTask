#include "Asteroid/Asteroid.h"

AAsteroid::AAsteroid()
{
	PrimaryActorTick.bCanEverTick = true;
	
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	SetRootComponent(Root);
	
	AsteroidMesh = CreateDefaultSubobject<UStaticMeshComponent>("AsteroidMesh");
	AsteroidMesh->SetupAttachment(GetRootComponent());
}

void AAsteroid::BeginPlay()
{
	Super::BeginPlay();
	
	SetRandomRotation();
	SetRandomSize();
}

void AAsteroid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Just a simple translation downwards
	// TODO: Connect to player speed
	AddActorWorldOffset(FVector(0.0f, 0.0f, -1000.0f * DeltaTime));
}

void AAsteroid::SetRandomRotation()
{
	SetActorRotation(FRotator(0.0f, 0.0f, FMath::RandRange(0.0f, 360.0f)));
}

void AAsteroid::SetRandomSize()
{
	SetActorScale3D(FVector(FMath::RandRange(1.0f, 3.0f)));
}
