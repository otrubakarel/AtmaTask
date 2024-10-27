#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AtmaTaskAIController.generated.h"

class UBehaviorTreeComponent;

UCLASS()
class AAtmaTaskAIController : public AAIController
{
	GENERATED_BODY()

	AAtmaTaskAIController();
	
protected:
	UPROPERTY()
	TObjectPtr<UBehaviorTreeComponent> BehaviorTreeComponent;	
	
};
