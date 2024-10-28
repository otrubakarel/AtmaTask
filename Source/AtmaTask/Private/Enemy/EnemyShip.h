#pragma once

#include "CoreMinimal.h"
#include "Combat/CombatInterface.h"
#include "GameFramework/Pawn.h"
#include "EnemyShip.generated.h"

class AAtmaTaskAIController;
class UStaticMeshComponent;
class UFloatingPawnMovement;
class UHealthComponent;
class UBehaviorTree;

UCLASS()
class AEnemyShip : public APawn, public ICombatInterface
{
	GENERATED_BODY()

public:
	AEnemyShip();

	virtual void PossessedBy(AController* NewController) override;
	
	/* Interaction Interface */
	virtual void Die_Implementation() override;
	virtual void Damage_Implementation(float DamageAmount, FVector HitLocation = FVector::ZeroVector) override;
	virtual float GetAttackDamage_Implementation() override;
	/* End Interaction Interface */

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AtmaTask|Ship")
	USceneComponent* Root;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AtmaTask|Camera")
	UFloatingPawnMovement* MovementComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AtmaTask|Ship")
	UStaticMeshComponent* ShipMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AtmaTask|Ship")
	USceneComponent* ShipWrapper;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AtmaTask|Ship")
	UHealthComponent* HealthComponent;

	UPROPERTY(BlueprintReadOnly, Category = "AtmaTask|AI")
	TObjectPtr<AAtmaTaskAIController> AtmaTaskAIController;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "AtmaTask|AI")
	TObjectPtr<UBehaviorTree> BehaviorTree;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AtmaTask|Combat")
	float AttackDamage = 50.0f;
};