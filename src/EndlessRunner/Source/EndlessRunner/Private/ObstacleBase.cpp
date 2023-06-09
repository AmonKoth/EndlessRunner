// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstacleBase.h"
#include "Components/BoxComponent.h"
#include "Characters/RunnerCharacter.h"
#include "Obstacle/ObstacleManager.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
AObstacleBase::AObstacleBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Component"));
	RootComponent = BoxComponent;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(BoxComponent);

}

// Called when the game starts or when spawned
void AObstacleBase::BeginPlay()
{
	Super::BeginPlay();
	BaseMesh->OnComponentHit.AddDynamic(this, &AObstacleBase::OnHit);
	if (!Manager)
	{
		Manager = Cast<AObstacleManager>(UGameplayStatics::GetActorOfClass(this, AObstacleManager::StaticClass()));
	}
	if (Manager)
	{
		Manager->AddToList(this);
	}
	
}

// Called every frame
void AObstacleBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AObstacleBase::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
	FVector NormalImpluse, const FHitResult& Hit)
{
	AActor* MyOwner = GetOwner();
	if (MyOwner == nullptr)
	{	return;	}

	AController* MyOwnerInstigator = MyOwner->GetInstigatorController();
	UClass* DamageTypeClass = UDamageType::StaticClass();

	ARunnerCharacter* HitCharacter = Cast<ARunnerCharacter>(OtherActor);
	if (HitCharacter)
	{
		bPassSuccess = false;
		UGameplayStatics::ApplyDamage(OtherActor, Damage, MyOwnerInstigator, this, DamageTypeClass);
	}
}

void AObstacleBase::DestroyedByManager()
{
	bPassSuccess = false;
	Destroy();
}
void AObstacleBase::Destroyed()
{
	Super::Destroyed();

	if (Manager && bPassSuccess)
	{
		Manager->PassSuccesfull();
	}
}



