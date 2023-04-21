// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObstacleBase.generated.h"

class UBoxComponent;

UCLASS()
class ENDLESSRUNNER_API AObstacleBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObstacleBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditDefaultsOnly, Category ="Components")
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(EditDefaultsOnly,Category = "Components")
	UBoxComponent* BoxComponent;
};
