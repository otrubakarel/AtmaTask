#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Asteroid.generated.h"

UCLASS()
class AAsteroid : public AActor
{
	GENERATED_BODY()
	
public:	
	AAsteroid();	
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AtmaTask|Asteroid")
	USceneComponent* Root;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AtmaTask|Asteroid")
	UStaticMeshComponent* AsteroidMesh;

private:
	void SetRandomRotation();
	void SetRandomSize();

};
