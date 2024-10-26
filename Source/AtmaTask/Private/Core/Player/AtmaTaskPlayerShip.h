#pragma once

#include "CoreMinimal.h"
#include "Combat/CombatInterface.h"
#include "GameFramework/Pawn.h"
#include "AtmaTaskPlayerShip.generated.h"

class UFloatingPawnMovement;
class UCameraComponent;
class USpringArmComponent;
class USkeletalMeshComponent;

UCLASS()
class AAtmaTaskPlayerShip : public APawn, public ICombatInterface
{
	GENERATED_BODY()

public:
	AAtmaTaskPlayerShip();
	
	/* Interaction Interface */
	virtual void Die_Implementation();
	/* End Interaction Interface */

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AtmaTask|Ship")
	USceneComponent* Root;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AtmaTask|Camera")
	UFloatingPawnMovement* MovementComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AtmaTask|Camera")
	UCameraComponent* CameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AtmaTask|Camera")
	USpringArmComponent* CameraBoom;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AtmaTask|Ship")
	USkeletalMeshComponent* ShipMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AtmaTask|Camera")
	float CameraDistance = 1000.0f;

};
