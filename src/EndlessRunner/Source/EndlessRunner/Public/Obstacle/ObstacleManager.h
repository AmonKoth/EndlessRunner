// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "ObstacleManager.generated.h"

class AObstacleBase;

UCLASS()
class ENDLESSRUNNER_API AObstacleManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObstacleManager();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void AddToList(AObstacleBase* ToAdd) { Obstacles.Add(ToAdd); }
	void PassSuccesfull();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	TArray<AObstacleBase*> Obstacles;

};
