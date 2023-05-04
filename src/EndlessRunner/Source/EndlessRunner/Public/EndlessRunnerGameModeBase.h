// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EndlessRunnerGameModeBase.generated.h"

class ARunnerCharacter;
class UHighScoreBase;

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
		float GetScore() { return CurrentScore; }

	UFUNCTION(BlueprintCallable)
	int32 GetHighestScore() { return HighestScore; }

	//UFUNCTION(BlueprintCallable)
	//	void SetPlayerName(FString Name) { PlayerName = Name; return; }

private:
	
	void HandleGameStart();
	void RestartLevel();
	void SaveScore(const FString& GameName, const float& Score);
	void LoadSavedScores(const FString& GameName);


	ARunnerCharacter* Player;
	FTimerHandle RestartTimerHandle;
	TArray<UHighScoreBase*> HighScores;

	int32 HighestScore;
	float CurrentScore = 0.0f;


};
