// Fill out your copyright notice in the Description page of Project Settings.


#include "EndlessRunnerGameModeBase.h"
#include "Characters/RunnerCharacter.h"

#include "Kismet/GameplayStatics.h"


void AEndlessRunnerGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	HandleGameStart();

}



void AEndlessRunnerGameModeBase::ActorDied(AActor* DeadActor)
{
	if (DeadActor == Player)
	{
		GameOver();
		GetWorldTimerManager().SetTimer(RestartTimerHandle, this, &AEndlessRunnerGameModeBase::RestartLevel, 1.5f, true);
	}
}

void AEndlessRunnerGameModeBase::HandleGameStart()
{
	Player = Cast<ARunnerCharacter>(UGameplayStatics::GetPlayerPawn(this,0));
}

void AEndlessRunnerGameModeBase::RestartLevel()
{
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), true);
}