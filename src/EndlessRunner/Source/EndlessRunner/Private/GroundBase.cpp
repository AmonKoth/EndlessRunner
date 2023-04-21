// Fill out your copyright notice in the Description page of Project Settings.


#include "GroundBase.h"
#include "ObstacleBase.h"
#include "Characters/RunnerCharacter.h"

#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AGroundBase::AGroundBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Component"));
	RootComponent = BoxComponent;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ground Mesh"));
	BaseMesh->SetupAttachment(BoxComponent);

	DespawnCollider =CreateDefaultSubobject<UBoxComponent>(TEXT("Despawn Component"));
	DespawnCollider->SetupAttachment(RootComponent);




}

// Called when the game starts or when spawned
void AGroundBase::BeginPlay()
{
	Super::BeginPlay();

	if (ObstacleClass && BoxComponent)
	{
		FVector SpawnLocation = UKismetMathLibrary::RandomPointInBoundingBox(BoxComponent->Bounds.Origin, BoxComponent->Bounds.BoxExtent);
		UE_LOG(LogTemp, Warning, TEXT("Random spawn loc %s"), *SpawnLocation.ToString());

		AObstacleBase* Obstacle = GetWorld()->SpawnActor<AObstacleBase>(ObstacleClass, SpawnLocation, FRotator::ZeroRotator);
		Obstacle->SetOwner(this);
		Obstacle->AttachToActor(this,FAttachmentTransformRules::KeepRelativeTransform);
		
		FVector ObstacleOrigin;
		FVector ObstacleExtent;
		Obstacle->GetActorBounds(false, ObstacleOrigin, ObstacleExtent);
		UE_LOG(LogTemp, Warning, TEXT("ObstacleOrigin  %s"), *ObstacleOrigin.ToString());
		UE_LOG(LogTemp, Warning, TEXT("ObstacleExtent  %s"), *ObstacleExtent.ToString());
		Obstacle->SetActorLocation(FVector(SpawnLocation.X, SpawnLocation.Y, ObstacleExtent.Z));

	}

	DespawnCollider->OnComponentBeginOverlap.AddDynamic(this, &AGroundBase::OnBoxBeginOverlap);

}

// Called every frame
void AGroundBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector MoveLocation = GetActorLocation();
	MoveLocation.X -= (MoveSpeed * DeltaTime * 100.f);
	SetActorLocation(MoveLocation);

}
void AGroundBase::Destroyed()
{
	TArray<AActor*> AttachedActors;
	GetAttachedActors(AttachedActors);

	for (AActor* AttachedActor : AttachedActors)
	{
		AttachedActor->Destroy();
	}
}

void AGroundBase::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ARunnerCharacter* Character = Cast<ARunnerCharacter>(OtherActor);
	if (Character)
	{
		Destroy();
	}
}
