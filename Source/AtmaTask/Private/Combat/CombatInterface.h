#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CombatInterface.generated.h"

UINTERFACE(MinimalAPI)
class UCombatInterface : public UInterface
{
	GENERATED_BODY()
};

class ICombatInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Combat")
	void Damage(float DamageAmount, FVector HitLocation = FVector::ZeroVector);
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Combat")
	void Die();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Combat")
	float GetAttackDamage();
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Combat")
	float GetAttackCooldown();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Combat")
	FVector GetWeaponSocket();
};
