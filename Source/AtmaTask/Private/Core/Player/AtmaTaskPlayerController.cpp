#include "Core/Player/AtmaTaskPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

void AAtmaTaskPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	checkf(IMC, TEXT("InputMappingContext is not set in AtmaTaskPlayerController"));
	
	// Add Enhanced Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* EnhancedInputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		EnhancedInputSubsystem->AddMappingContext(IMC, 0);
	}
}

void AAtmaTaskPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAtmaTaskPlayerController::Input_Move);
		EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Triggered, this, &AAtmaTaskPlayerController::Input_Attack);
	}
}

void AAtmaTaskPlayerController::Input_Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2d>();
	const FVector MovementVector = FVector(0.0f, -InputAxisVector.Y, InputAxisVector.X);

	if (APawn* ControlledPawn = GetPawn())
	{
		ControlledPawn->AddMovementInput(MovementVector, 1.f);
	}

	// TODO: Movement should be only left/right. Up/Down should accel/decelerate the world movement mainly
	// and maybe move the ship slightly up/down
}

void AAtmaTaskPlayerController::Input_Attack(const FInputActionValue& InputActionValue)
{
	// Player ship attack
	// TODO: Fire a projectile / laser into the cursor direction
}