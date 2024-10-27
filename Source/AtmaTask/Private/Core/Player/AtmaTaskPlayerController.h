#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AtmaTaskPlayerController.generated.h"

// 0 = back to default idle speed, 1 = Accelerate, -1 = Stop
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSpeedChangeSignature, int32, Direction);

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class AAtmaTaskPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category = "Input")
	FOnSpeedChangeSignature OnSpeedChange;

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputMappingContext> IMC;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> AttackAction;
	
	UPROPERTY(BlueprintReadOnly, Category = "Input")
	int32 SpeedDirection = 0;

private:
	
	void Input_Move(const FInputActionValue& InputActionValue);
	void Input_StopMove();
	void Input_Attack(const FInputActionValue& InputActionValue);
};
