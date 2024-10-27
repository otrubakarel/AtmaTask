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
	void UpdateHealth(float HealthChange);

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AtmaTask|Combat", meta = (ClampMin = "0.0"))
	float MaxHealth = 100.0f;
	
	UPROPERTY(BlueprintReadOnly, Category = "AtmaTask|Combat")
	float Health = MaxHealth;

private:
	UPROPERTY()
	UHealthWidget* HealthWidget;
	
};
