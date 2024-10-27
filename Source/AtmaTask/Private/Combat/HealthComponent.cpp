// Fill out your copyright notice in the Description page of Project Settings.


#include "Combat/HealthComponent.h"

#include "CombatInterface.h"
#include "HealthWidget.h"

UHealthComponent::UHealthComponent()
{
	// Set the Health's widget to be a WBP_Health
	// Not the best solution as it is hardcoded, but fine for a prototype
	static ConstructorHelpers::FClassFinder<UUserWidget> HealthWidgetClass(TEXT("/Game/AtmaTask/Combat/WBP_Health"));
	SetWidgetClass(HealthWidgetClass.Class);
	SetWidgetSpace(EWidgetSpace::Screen);
	SetDrawAtDesiredSize(true);
	
	CastShadow = false;
}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	HealthWidget = Cast<UHealthWidget>(GetUserWidgetObject());
}

void UHealthComponent::UpdateHealth(float HealthChange)
{
	// Called by damage or regeneration
	Health += HealthChange;
	Health = FMath::Clamp(Health, 0.0f, MaxHealth); // Clamp the health value so we don't overflow
	
	if (HealthWidget) HealthWidget->SetHealthPercent(Health / MaxHealth);

	// Call death function if health goes below 0
	if (Health <= 0.0f)
	{
		ICombatInterface::Execute_Die(GetOwner());
	}
}


