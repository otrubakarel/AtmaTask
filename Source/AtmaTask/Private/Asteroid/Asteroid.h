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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AtmaTask|Asteroid")
	float Speed = 2000.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AtmaTask|Asteroid")
	float AsteroidDamage = 50.0f;

private:
	void SetRandomRotation();
	void SetRandomSize();

	UFUNCTION()
	void OnSpeedChange(int32 Direction);

	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
