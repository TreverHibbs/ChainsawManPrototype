// Fill out your copyright notice in t->GetPlayerInput()he Description page of Project Settings.

#include "ChainsawController.h"

void AChainsawController::BeginPlay()
{
	const ULocalPlayer* LocalPlayer = GetLocalPlayer();
	if (LocalPlayer == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Local Player For Chainsaw Controller was null."));
	}
	UEnhancedInputLocalPlayerSubsystem* InputSystem = LocalPlayer->GetSubsystem<
		UEnhancedInputLocalPlayerSubsystem>();
	if (!InputMapping.IsValid())
	{
		TObjectPtr<UInputMappingContext> InputMappingInstance = InputMapping.LoadSynchronous();
	}
	if (InputSystem != nullptr && InputMapping.IsValid())
	{
		InputSystem->ClearAllMappings();
		InputSystem->AddMappingContext(InputMapping.Get(), 0);
	}
}
