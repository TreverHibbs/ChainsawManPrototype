// Fill out your copyright notice in the Description page of Project Settings.


#include "ChainsawManPrototype/Public/ChainsawCharacter.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AChainsawCharacter::AChainsawCharacter()
{
}

// Called when the game starts or when spawned
void AChainsawCharacter::BeginPlay()
{
	Super::BeginPlay();

	UCharacterMovementComponent* CharacterMovementPointer = GetCharacterMovement();
	if (CharacterMovementPointer != nullptr)
	{
		CharacterMovementPointer->JumpZVelocity = 2.f * (JumpHeight / TimeToApex);
		const auto WorldGravity = GetWorld()->GetGravityZ();
		CharacterMovementPointer->GravityScale = (-2.f * (JumpHeight / TimeToApex)) / WorldGravity;
	}
}

// Called every frame
void AChainsawCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AChainsawCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (MoveAction.IsValid())
	{
		Input->BindAction(MoveAction.Get(), ETriggerEvent::Triggered, this, &AChainsawCharacter::Move);
	}
	if (JumpAction.IsValid())
	{
		Input->BindAction(JumpAction.Get(), ETriggerEvent::Triggered, this, &AChainsawCharacter::Jump);
	}
	if (LookAction.IsValid())
	{
		Input->BindAction(LookAction.Get(), ETriggerEvent::Triggered, this, &AChainsawCharacter::Look);
	}
}

void AChainsawCharacter::Move(const FInputActionValue& ActionValue)
{
	AddMovementInput(GetActorForwardVector(), ActionValue[0]);
	AddMovementInput(GetActorRightVector(), ActionValue[1]);
}

void AChainsawCharacter::Look(const FInputActionValue& ActionValue)
{
	AddControllerPitchInput(ActionValue[1]);
	AddControllerYawInput(ActionValue[0]);
}
