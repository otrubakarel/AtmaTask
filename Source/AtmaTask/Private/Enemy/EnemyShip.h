#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "EnemyShip.generated.h"

class AAtmaTaskAIController;
class UStaticMeshComponent;
class UFloatingPawnMovement;
class UHealthComponent;
class UBehaviorTree;

UCLASS()
class AEnemyShip : public APawn
{
	GENERATED_BODY()

public:
	AEnemyShip();

	virtual void PossessedBy(AController* NewController) override;

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AtmaTask|Ship")
	USceneComponent* Root;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AtmaTask|Camera")
	UFloatingPawnMovement* MovementComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AtmaTask|Ship")
	UStaticMeshComponent* ShipMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AtmaTask|Ship")
	UHealthComponent* HealthComponent;

	UPROPERTY(BlueprintReadOnly, Category = "AtmaTask|AI")
	TObjectPtr<AAtmaTaskAIController> AtmaTaskAIController;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "AtmaTask|AI")
	TObjectPtr<UBehaviorTree> BehaviorTree;
};