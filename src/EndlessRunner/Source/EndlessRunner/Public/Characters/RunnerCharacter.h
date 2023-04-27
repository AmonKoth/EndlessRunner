// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RunnerCharacter.generated.h"




UCLASS()
class ENDLESSRUNNER_API ARunnerCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	ARunnerCharacter();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float Value);

protected:

	virtual void BeginPlay() override;


private:

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MoveSpeed = 600.0f;



};
