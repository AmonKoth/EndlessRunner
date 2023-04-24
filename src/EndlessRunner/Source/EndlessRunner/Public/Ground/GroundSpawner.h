// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GroundSpawner.generated.h"

class AGroundBase;

UCLASS()
class ENDLESSRUNNER_API AGroundSpawner : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGroundSpawner();
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditDefaultsOnly, Category = "Obstacles")
		TSubclassOf<AGroundBase> SpawnedGroundClass;

	AGroundBase* LastSpawn;

	void SpawnNewFloor();

	float LastSpawnDistance = 0.0f;
	float GroundSize = 0.0f;

};
