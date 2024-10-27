// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "HealthComponent.generated.h"

class UHealthWidget;

UCLASS()
class UHealthComponent : public UWidgetComponent
{
	GENERATED_BODY()

public:
	UHealthComponent();
	
	UFUNCTION(BlueprintCallable)
	void TakeDamage(float DamageAmount);

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AtmaTask|Combat", meta = (ClampMin = "0.0"))
	float MaxHealth = 100.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AtmaTask|Combat", meta = (ClampMin = "0.0"))
	float Regeneration = 10.0f;
	
	UPROPERTY(BlueprintReadOnly, Category = "AtmaTask|Combat")
	float Health;

private:
	UPROPERTY()
	UHealthWidget* HealthWidget;

	FTimerHandle RegenTimer;

	void RegenerateHealth();
	void UpdateHealth(float HealthChange);
	
};
