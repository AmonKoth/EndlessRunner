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

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent)
	void GameOver();

private:
	

	ARunnerCharacter* Player;

	void HandleGameStart();

	void RestartLevel();

	FTimerHandle RestartTimerHandle;


};
