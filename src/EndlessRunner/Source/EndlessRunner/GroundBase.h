// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GroundBase.generated.h"

class UBoxComponent;
class AObstacleBase;

UCLASS()
class ENDLESSRUNNER_API AGroundBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGroundBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditDefaultsOnly, Category = "Components")
		UStaticMeshComponent* BaseMesh;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
		UBoxComponent* BoxComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Obstacles")
		TSubclassOf<AObstacleBase> ObstacleClass;

	UPROPERTY(EditDefaultsOnly, Category = "Movement")
	float MoveSpeed = 10.f;

	UPROPERTY(EditDefaultsOnly, Category = "Movement")
		UBoxComponent* DespawnCollider;

	UFUNCTION()
		void OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, 
			AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
			bool bFromSweep, const FHitResult& SweepResult);

};
