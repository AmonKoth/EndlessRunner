// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObstacleBase.generated.h"

class UBoxComponent;
class AObstacleManager;

UCLASS()
class ENDLESSRUNNER_API AObstacleBase : public AActor
{
	GENERATED_BODY()
	
public:	

	AObstacleBase();	
	virtual void Tick(float DeltaTime) override;
	void AssignManager(AObstacleManager* ToAssign) { Manager = ToAssign; }
	void DestroyedByManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Destroyed() override;

private:

	UPROPERTY(EditDefaultsOnly, Category ="Components")
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(EditDefaultsOnly,Category = "Components")
	UBoxComponent* BoxComponent;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float Damage = 1.0f;

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
			FVector NormalImpluse, const FHitResult& Hit);

	bool bPassSuccess = true;

	AObstacleManager* Manager;
};
