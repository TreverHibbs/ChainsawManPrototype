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
		//apply convenience values for tuning jump.
		CharacterMovementPointer->JumpZVelocity = 2.f * (JumpHeight / TimeToApex);
		const auto WorldGravity = GetWorld()->GetGravityZ();
		CharacterMovementPointer->GravityScale = (-2.f * (JumpHeight / powf(TimeToApex, 2)))
			/ WorldGravity;
	}
}

// Called every frame
void AChainsawCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//It seems as though gravity scale is set somewhere while the game is ticking.
	//therefore, continue to reset it here for it to stay consistent.
	//Not a great solution but it seems to work.
	UCharacterMovementComponent* CharacterMovementPointer = GetCharacterMovement();
	if (CharacterMovementPointer != nullptr)
	{
		//apply convenience values for tuning jump.
		CharacterMovementPointer->JumpZVelocity = 2.f * (JumpHeight / TimeToApex);
		const auto WorldGravity = GetWorld()->GetGravityZ();
		CharacterMovementPointer->GravityScale = (-2.f * (JumpHeight / powf(TimeToApex, 2)))
			/ WorldGravity;
	}
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

void AChainsawCharacter::OnMovementModeChanged(EMovementMode PrevMovementMode, uint8 PreviousCustomMode)
{
	Super::OnMovementModeChanged(PrevMovementMode, PreviousCustomMode);
	const auto WorldGravity = GetWorld()->GetGravityZ();
	UCharacterMovementComponent* MovementComponentPointer = GetCharacterMovement();
	if (PrevMovementMode != MOVE_Falling)
	{
		//Must set this here because it is cleared after every time NofityJumpApex is fired.
		//Thus, if we want it to trigger at the apex of a jump, we must set it at the start
		//of that jump.
		MovementComponentPointer->bNotifyApex = true;
	}
	else
	{
		//Must return gravity to normal because it is changed in NotifyJumpApex for design control
		MovementComponentPointer->GravityScale = (-2.f * (JumpHeight / TimeToApex)) / WorldGravity;
	}
}

void AChainsawCharacter::NotifyJumpApex()
{
	Super::NotifyJumpApex();
	const auto WorldGravity = GetWorld()->GetGravityZ();
	UCharacterMovementComponent* MovementComponentPointer = GetCharacterMovement();
	MovementComponentPointer->GravityScale = ((-2.f * (JumpHeight / TimeToApex)) / WorldGravity) *
		FallingGravMultiplier;
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
