#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "AtmaTaskPlayerShip.generated.h"

class UFloatingPawnMovement;
class UCameraComponent;
class USpringArmComponent;
class USkeletalMeshComponent;

UCLASS()
class AAtmaTaskPlayerShip : public APawn
{
	GENERATED_BODY()

public:
	AAtmaTaskPlayerShip();

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
