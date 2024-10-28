#pragma once

#include "CoreMinimal.h"
#include "Combat/CombatInterface.h"
#include "GameFramework/Pawn.h"
#include "AtmaTaskPlayerShip.generated.h"

class UHealthComponent;
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
	virtual void Die_Implementation() override;
	virtual void Damage_Implementation(float DamageAmount, FVector HitLocation = FVector::ZeroVector) override;
	virtual float GetAttackDamage_Implementation() override;
	virtual float GetAttackCooldown_Implementation() override { return AttackCooldown; }
	virtual FVector GetWeaponSocket_Implementation() override { return ShipMesh->GetSocketLocation(FName("Weapon")); }
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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AtmaTask|Ship")
	UHealthComponent* HealthComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AtmaTask|Camera")
	float CameraDistance = 1000.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AtmaTask|Combat")
	float AttackDamage = 50.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AtmaTask|Combat")
	float AttackCooldown = 1.0f;

};
