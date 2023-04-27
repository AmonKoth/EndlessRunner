// Fill out your copyright notice in the Description page of Project Settings.


#include "Ground/GroundSpawner.h"
#include "GroundBase.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AGroundSpawner::AGroundSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGroundSpawner::BeginPlay()
{
	Super::BeginPlay();
	SpawnNewFloor();
	if (LastSpawn)
	{
		GroundSize = LastSpawn->GetSizeOfTheFloor();
	}
}

// Called every frame
void AGroundSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (LastSpawn)
	{
		LastSpawnDistance = UKismetMathLibrary::Vector_Distance(GetActorLocation(), LastSpawn->GetActorLocation());
	if (LastSpawnDistance  >= GroundSize*2)
		{
			SpawnNewFloor();
		}
	}	

}


void AGroundSpawner::SpawnNewFloor()
{
	if (SpawnedGroundClass)
	{
		AGroundBase* SpawnedGround = GetWorld()->SpawnActor<AGroundBase>(SpawnedGroundClass, GetActorLocation(), FRotator::ZeroRotator);
		SpawnedGround->SetOwner(this);
		SpawnedGround->SetMoveSpeed(PlatformSpeed);
		PlatformSpeed += 0.5f;
		LastSpawn = SpawnedGround;
	}

}
