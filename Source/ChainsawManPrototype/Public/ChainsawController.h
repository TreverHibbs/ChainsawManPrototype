// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInput/Public/InputMappingContext.h"
#include "EnhancedInput/Public/EnhancedInputSubsystems.h"
#include "ChainsawController.generated.h"


/**
 * 
 */
UCLASS(Blueprintable)
class CHAINSAWMANPROTOTYPE_API AChainsawController : public APlayerController
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category=Input)
	TSoftObjectPtr<UInputMappingContext> InputMapping;

	virtual void BeginPlay() override;
};
