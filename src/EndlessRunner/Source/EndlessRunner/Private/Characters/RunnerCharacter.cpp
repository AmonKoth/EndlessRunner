// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/RunnerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ARunnerCharacter::ARunnerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Arm"));
	SpringArmComponent->SetupAttachment(RootComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent);

}

// Called when the game starts or when spawned
void ARunnerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARunnerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARunnerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(FName("LeftRight"), this, &ARunnerCharacter::MoveForward);

}

void ARunnerCharacter::MoveForward(float Value)
{
	if (Controller && (Value != 0.0f))
	{
		FVector Right = GetActorRightVector();
		float Speed = Value * MoveSpeed * UGameplayStatics::GetWorldDeltaSeconds(this);
		AddMovementInput(Right, Speed);

	}

}

