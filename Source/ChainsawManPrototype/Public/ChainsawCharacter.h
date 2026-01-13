// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnhancedInput/Public/InputAction.h"
#include "ChainsawCharacter.generated.h"

UCLASS(Blueprintable)
class CHAINSAWMANPROTOTYPE_API AChainsawCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AChainsawCharacter();

	UPROPERTY(EditAnywhere, Category=Input)
	TSoftObjectPtr<UInputAction> MoveAction;
	UPROPERTY(EditAnywhere, Category=Input)
	TSoftObjectPtr<UInputAction> JumpAction;
	UPROPERTY(EditAnywhere, Category=Input)
	TSoftObjectPtr<UInputAction> LookAction;
	UPROPERTY(EditAnywhere, Category="Character Movement: Jumping / Falling")
	float JumpHeight; //units are cm
	UPROPERTY(EditAnywhere, Category="Character Movement: Jumping / Falling")
	float TimeToApex; //units are seconds
	UPROPERTY(EditAnywhere, Category="Character Movement: Jumping / Falling")
	float FallingGravMultiplier; //units are cm

	UFUNCTION()
	void Move(const FInputActionValue& ActionValue);
	UFUNCTION()
	void Look(const FInputActionValue& ActionValue);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	virtual void OnMovementModeChanged(EMovementMode PrevMovementMode, uint8 PreviousCustomMode = 0) override;
	
	virtual void NotifyJumpApex() override;
};
