#include "Core/Player/AtmaTaskPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Combat/CombatInterface.h"

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

	// Bind all Input Events to Functions
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAtmaTaskPlayerController::Input_Move);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Completed, this, &AAtmaTaskPlayerController::Input_StopMove);
		EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Completed, this, &AAtmaTaskPlayerController::Input_Attack);
		EnhancedInputComponent->BindAction(ExitAction, ETriggerEvent::Started, this, &AAtmaTaskPlayerController::Input_Exit);
	}
}

void AAtmaTaskPlayerController::Input_Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2d>();
	const FVector MovementVector = FVector(0.0f, -InputAxisVector.Y, 0.0f);

	if (APawn* ControlledPawn = GetPawn())
	{
		// Move left/right only when in bounds
		if (ControlledPawn->GetActorLocation().Y < -2500.f && MovementVector.Y < 0) return;
		if (ControlledPawn->GetActorLocation().Y > 2500.f && MovementVector.Y > 0) return;
		ControlledPawn->AddMovementInput(MovementVector, 1.f);
	}

	// Broadcast speed change
	int32 Direction = InputAxisVector.X > 0 ? 1 : InputAxisVector.X < 0 ? -1 : 0;
	SpeedDirection = Direction;
	OnSpeedChange.Broadcast(SpeedDirection);
}

void AAtmaTaskPlayerController::Input_StopMove()
{
	SpeedDirection = 0;
	OnSpeedChange.Broadcast(SpeedDirection);
}

void AAtmaTaskPlayerController::Input_Attack(const FInputActionValue& InputActionValue)
{
	// We only attack successfully when we actually target an enemy undert the cursor, otherwise do nothing
	
	// Check if we can attack (cooldown)
	if (!bCanAttack) return;
	
	// Player ship attack
	UE_LOG(LogTemp, Warning, TEXT("Player ship attack"));

	// Get hit result under cursor
	FHitResult HitResult;

	if (GetHitResultUnderCursor(ECC_GameTraceChannel2, false, HitResult))
	{
		AActor* HitActor = HitResult.GetActor();

		if (!HitActor) return;

		// There is an actor at the mouse cursor position
		UE_LOG(LogTemp, Warning, TEXT("Actor under cursor: %s"), *HitActor->GetName());

		// Check if the actor can be damaged, if so, apply damage
		if (HitActor->Implements<UCombatInterface>())
		{
			UE_LOG(LogTemp, Warning, TEXT("Damaging actor for %f"), ICombatInterface::Execute_GetAttackDamage(GetPawn()));
			ICombatInterface::Execute_Damage(HitActor, ICombatInterface::Execute_GetAttackDamage(GetPawn()), HitResult.ImpactPoint);
			
			// Set attack cooldown
			bCanAttack = false;
			OnAttackCooldown.Broadcast(bCanAttack);
			GetWorldTimerManager().SetTimer(AttackCooldownTimerHandle, this, &AAtmaTaskPlayerController::AttackCooldownFinished, ICombatInterface::Execute_GetAttackCooldown(GetPawn()), false);

			// Show attack effect
			ShowAttackEffect(ICombatInterface::Execute_GetWeaponSocket(GetPawn()), HitResult.ImpactPoint);
		}
	}
}

void AAtmaTaskPlayerController::Input_Exit()
{
	// Exit the game
	FGenericPlatformMisc::RequestExit(false);
}

void AAtmaTaskPlayerController::AttackCooldownFinished()
{
	bCanAttack = true;
	OnAttackCooldown.Broadcast(bCanAttack);
}
