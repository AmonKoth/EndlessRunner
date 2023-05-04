// Fill out your copyright notice in the Description page of Project Settings.

#include "EndlessRunnerGameModeBase.h"
#include "Characters/RunnerCharacter.h"
#include "HighScore/HighScoreBase.h"

#include "Kismet/GameplayStatics.h"
#include "JsonUtilities.h"

void AEndlessRunnerGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	HandleGameStart();
}

void AEndlessRunnerGameModeBase::UpdateScore(float Value)
{
	CurrentScore = Value;
}

void AEndlessRunnerGameModeBase::ActorDied(AActor *DeadActor)
{
	if (DeadActor)
	{
		GameOver(); 
		if (CurrentScore > HighestScore)
		{
			SaveScore("EndlessRunner", CurrentScore);
		}
		GetWorldTimerManager().SetTimer(RestartTimerHandle, this, &AEndlessRunnerGameModeBase::RestartLevel, 1.5f, true);
	}
}

void AEndlessRunnerGameModeBase::HandleGameStart()
{
	Player = Cast<ARunnerCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	LoadSavedScores("EndlessRunner");
	UE_LOG(LogTemp, Warning, TEXT("HIGHEST SCORE IS : %d"), HighestScore);
}

void AEndlessRunnerGameModeBase::RestartLevel()
{
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), true);
}

void AEndlessRunnerGameModeBase::SaveScore(const FString & GameName, const float &ScoreEntry)
{
		UHighScoreBase* Saving = Cast<UHighScoreBase>(UGameplayStatics::CreateSaveGameObject(UHighScoreBase::StaticClass()));
		Saving->HighScore = FMath::RoundToInt32(ScoreEntry);
		UGameplayStatics::SaveGameToSlot(Saving, GameName, -1);
}

void AEndlessRunnerGameModeBase::LoadSavedScores(const FString & GameName)
{
	if (UGameplayStatics::DoesSaveGameExist(GameName, -1))
	{
		UHighScoreBase* load = Cast<UHighScoreBase>(UGameplayStatics::LoadGameFromSlot(GameName, -1));
		HighestScore = load->HighScore;
	}
	else
	{
		HighestScore = 0;
	}
}