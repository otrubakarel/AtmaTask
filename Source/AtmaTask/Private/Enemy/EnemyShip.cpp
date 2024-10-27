#include "Enemy/EnemyShip.h"

#include "AI/AtmaTaskAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Combat/HealthComponent.h"
#include "GameFramework/FloatingPawnMovement.h"

AEnemyShip::AEnemyShip()
{
	PrimaryActorTick.bCanEverTick = false;

	MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>("MovementComponent");
	
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	SetRootComponent(Root);
	
	ShipMesh = CreateDefaultSubobject<UStaticMeshComponent>("Ship");
	ShipMesh->SetupAttachment(GetRootComponent());
	
	HealthComponent = CreateDefaultSubobject<UHealthComponent>("HealthComponent");
	HealthComponent->SetupAttachment(GetRootComponent());
}

void AEnemyShip::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEnemyShip::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	AtmaTaskAIController = Cast<AAtmaTaskAIController>(NewController);
	AtmaTaskAIController->GetBlackboardComponent()->InitializeBlackboard(*BehaviorTree->BlackboardAsset);
	AtmaTaskAIController->RunBehaviorTree(BehaviorTree);
}

