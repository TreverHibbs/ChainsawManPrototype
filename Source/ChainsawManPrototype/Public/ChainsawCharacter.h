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
	//TODO group my favorite movement properties by creating custom properties that
	//act as proxies for the actual values they edit
	//TODO wind down the game design exploration. Take some time to reflect on it
	//TODO before start of next exploration perhaps explore how to disable most UE5 graphics
	//features so that I am forced to be intentional about the look of the prototype.
	//Don't use art that will skew how I think the finished game might look to much.
	
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
