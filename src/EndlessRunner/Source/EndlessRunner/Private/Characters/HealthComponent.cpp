// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/HealthComponent.h"
#include "EndlessRunnerGameModeBase.h"

#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = StartHealth;
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::DamageTaken);
	GameMode = Cast<AEndlessRunnerGameModeBase>(UGameplayStatics::GetGameMode(this));


	// ...
	
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	if (CurrentGraceTime > 0)
	{
		CurrentGraceTime -= DeltaTime;
	}
	// ...
}

void UHealthComponent::DamageTaken(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* Instigator, AActor* DamageCauser)
{
	if (Damage <= 0.0f) return;
	if (CurrentGraceTime > 0)return;	



	CurrentHealth -= Damage;
		CurrentGraceTime = GracePeriod;
	if (CurrentHealth <= 0.0f)
	{
		GameMode->ActorDied(DamagedActor);
	}
}


