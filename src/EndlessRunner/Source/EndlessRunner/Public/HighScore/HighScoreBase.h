// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "HighScoreBase.generated.h"

/**
 * 
 */
UCLASS()
class ENDLESSRUNNER_API UHighScoreBase : public USaveGame
{
	GENERATED_BODY()


public:

	UPROPERTY()
	int32 HighScore;
	
};
