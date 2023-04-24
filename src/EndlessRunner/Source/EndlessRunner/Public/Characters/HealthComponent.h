// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


class AEndlessRunnerGameModeBase;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ENDLESSRUNNER_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;



protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:

	UFUNCTION()
		void DamageTaken(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* Instigator, AActor* DamageCauser);

	UPROPERTY(EditDefaultsOnly, Category = "Health")
	float StartHealth = 3.0f;


	UPROPERTY(EditDefaultsOnly, Category = "Health")
	float GracePeriod = 3.0f;

	float CurrentHealth = 0.0f;
	float CurrentGraceTime = 0.0f;

	AEndlessRunnerGameModeBase* GameMode;


};
