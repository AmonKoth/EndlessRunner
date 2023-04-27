// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EndlessRunnerGameModeBase.generated.h"

class ARunnerCharacter;

UCLASS()
class ENDLESSRUNNER_API AEndlessRunnerGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	
	void ActorDied(AActor* DeadActor);
	
	void UpdateScore(float Value);
protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent)
	void GameOver();

	UFUNCTION(BlueprintCallable)
		float GetScore() { return Score; }

private:
	

	ARunnerCharacter* Player;

	void HandleGameStart();

	void RestartLevel();

	FTimerHandle RestartTimerHandle;


	float Score = 0.0f;


};
