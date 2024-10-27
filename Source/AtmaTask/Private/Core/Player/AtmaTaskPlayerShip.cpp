#include "Core/Player/AtmaTaskPlayerShip.h"
#include "Camera/CameraComponent.h"
#include "Core/AtmaTaskFunctionLibrary.h"
#include "Core/AtmaTaskGameInstance.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"

AAtmaTaskPlayerShip::AAtmaTaskPlayerShip()
{
	PrimaryActorTick.bCanEverTick = false;

	MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>("MovementComponent");
	
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	SetRootComponent(Root);
	
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->SetUsingAbsoluteRotation(true);
	CameraBoom->SetUsingAbsoluteLocation(true);
	CameraBoom->TargetArmLength = CameraDistance;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera");
	CameraComponent->SetupAttachment(CameraBoom);
	CameraComponent->bUsePawnControlRotation = false;

	ShipMesh = CreateDefaultSubobject<USkeletalMeshComponent>("Ship");
	ShipMesh->SetupAttachment(GetRootComponent());
}

void AAtmaTaskPlayerShip::BeginPlay()
{
	Super::BeginPlay();	
}

void AAtmaTaskPlayerShip::Die_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("Player Ship has died!"));
	SetActorHiddenInGame(true);
	UAtmaTaskFunctionLibrary::GetAtmaTaskGameInstance(this)->EndGame(false);
}
