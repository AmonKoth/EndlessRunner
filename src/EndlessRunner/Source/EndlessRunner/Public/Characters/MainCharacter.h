// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class ARunnerCharacter;
class AEndlessRunnerGameModeBase;

UCLASS()
class ENDLESSRUNNER_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UFUNCTION(BlueprintCallable)
	ARunnerCharacter* GetFirstPlayer() { return FirstPlayer; }
	UFUNCTION(BlueprintCallable)
	ARunnerCharacter* GetSecondPlayer() { return SecondPlayer; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


private:
	UPROPERTY(VisibleAnywhere, Category = "Camera Components")
		USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, Category = "Camera Components")
		UCameraComponent* CameraComponent;

	ARunnerCharacter* FirstPlayer;
	ARunnerCharacter* SecondPlayer;

	AEndlessRunnerGameModeBase* GameMode;

	void FirstPlayerMove(float Value);
	void SecondPlayerMove(float Value);

	float Score;

};
