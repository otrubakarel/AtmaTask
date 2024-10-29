#include "Enemy/EnemyShip.h"

#include "AI/AtmaTaskAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Combat/HealthComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Kismet/GameplayStatics.h"

AEnemyShip::AEnemyShip()
{
	PrimaryActorTick.bCanEverTick = false;

	MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>("MovementComponent");
	
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	SetRootComponent(Root);

	// The ship model is not centered at the origin, so for sake of simplicity
	// we add a wrapper component and attach the ship to it
	ShipWrapper = CreateDefaultSubobject<USceneComponent>("ShipWrapper");
	ShipWrapper->SetupAttachment(GetRootComponent());
	ShipMesh = CreateDefaultSubobject<UStaticMeshComponent>("Ship");
	ShipMesh->SetupAttachment(ShipWrapper);
	
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

void AEnemyShip::Die_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("Enemy destroyed!"));
	// TODO: Implement death behavior
	Destroy();
}

void AEnemyShip::Damage_Implementation(float DamageAmount, FVector HitLocation)
{
	HealthComponent->TakeDamage(DamageAmount);
}

float AEnemyShip::GetAttackDamage_Implementation()
{
	return AttackDamage;
}

void AEnemyShip::Attack()
{
	UE_LOG(LogTemp, Warning, TEXT("Enemy Attack"));
	UE_LOG(LogTemp, Warning, TEXT("Enemy Attack %s"), *ShipMesh->GetSocketLocation(FName("Weapon")).ToString());
	UE_LOG(LogTemp, Warning, TEXT("Enemy Attack %s"), *UGameplayStatics::GetPlayerPawn(GetWorld(), 0)->GetName());

	AActor* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	UE_LOG(LogTemp, Warning, TEXT("PlayerPawn: %s"), *PlayerPawn->GetName());
	ICombatInterface::Execute_Damage(PlayerPawn, AttackDamage, PlayerPawn->GetActorLocation());
	ShowAttackEffect(ShipMesh->GetSocketLocation(FName("Weapon")), PlayerPawn->GetActorLocation());
}
