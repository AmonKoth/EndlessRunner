// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstacle/ObstacleManager.h"
#include "ObstacleBase.h"


// Sets default values
AObstacleManager::AObstacleManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AObstacleManager::BeginPlay()
{
	Super::BeginPlay();
	
}

void AObstacleManager::PassSuccesfull()
{
	if (FMath::RandRange(0, 100) < 20)
	{
		if (!Obstacles.IsEmpty())
		{ 
			int32 NumToDelete = FMath::RandRange(0, Obstacles.Num() - 1);
			AObstacleBase* Obstacle = Obstacles[NumToDelete];
			if (Obstacle)
			{
			Obstacles.Remove(Obstacle);
			Obstacle->DestroyedByManager();
			}
		}
	}
}

// Called every frame
void AObstacleManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

