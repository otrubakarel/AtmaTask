#include "Asteroid/Asteroid.h"

#include "Combat/CombatInterface.h"
#include "Core/AtmaTaskFunctionLibrary.h"
#include "Core/Player/AtmaTaskPlayerController.h"

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

	// Bind the OnSpeedChange event to the PlayerController
	AAtmaTaskPlayerController* PC = UAtmaTaskFunctionLibrary::GetAtmaTaskPlayerController(this);
	if (PC)
	{
		PC->OnSpeedChange.AddDynamic(this, &AAsteroid::OnSpeedChange);
	}

	AsteroidMesh->OnComponentBeginOverlap.AddDynamic(this, &AAsteroid::OnOverlap);
	
	SetRandomRotation();
	SetRandomSize();
}

void AAsteroid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Just a simple translation downwards
	AddActorWorldOffset(FVector(0.0f, 0.0f, -Speed * DeltaTime));

	// Destroy the asteroid if it goes below a certain Z value
	if (GetActorLocation().Z < -4000.0f) Destroy();
}

void AAsteroid::SetRandomRotation()
{
	SetActorRotation(FRotator(0.0f, 0.0f, FMath::RandRange(0.0f, 360.0f)));
}

void AAsteroid::SetRandomSize()
{
	SetActorScale3D(FVector(FMath::RandRange(1.0f, 3.0f)));
}

void AAsteroid::OnSpeedChange(int32 Direction)
{
	// Change the speed based on the player's current speed
	if (Direction == -1)
	{
		Speed = 500.0f;
		return;
	}
	
	if (Direction == 0)
	{
		Speed = 2000.0f;
		return;
	}
	
	if (Direction == 1)
	{
		Speed = 3000.0f;
	}
}

void AAsteroid::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Asteroid Overlap with %s"), *OtherActor->GetName());
	
	// Check if the overlapped actor has Combat Interface, if so, apply damage
	if (OtherActor->Implements<UCombatInterface>())
	{
		ICombatInterface::Execute_Damage(OtherActor, AsteroidDamage, FVector::ZeroVector); // Apply damage to the collided actor
	}
}
