// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/MainCharacter.h"
#include "Characters/RunnerCharacter.h"
#include "EndlessRunnerGameModeBase.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Arm"));
	SpringArmComponent->SetupAttachment(RootComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent);

}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> Players;
	UGameplayStatics::GetAllActorsOfClass(this, ARunnerCharacter::StaticClass(), Players);
	FirstPlayer = Cast<ARunnerCharacter>(Players[0]);
	SecondPlayer = Cast<ARunnerCharacter>(Players[1]);

	GameMode = Cast<AEndlessRunnerGameModeBase>(UGameplayStatics::GetGameMode(this));
	
	
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	Score += (DeltaTime);
	if (GameMode)
	{
		GameMode->UpdateScore(Score);
	}

}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(FName("LeftRight"), this, &AMainCharacter::FirstPlayerMove);
	PlayerInputComponent->BindAxis(FName("SecondPlayerLeftRight"), this, &AMainCharacter::SecondPlayerMove);

}

void AMainCharacter::FirstPlayerMove(float Value)
{
	if (FirstPlayer)
	{
	FirstPlayer->MoveForward(Value);
	}
}
void AMainCharacter::SecondPlayerMove(float Value)
{
	if (SecondPlayer)
	{
		SecondPlayer->MoveForward(Value);
	}
}
