// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "BulletBillActor.generated.h"

UCLASS()
class CHAINSAWMANPROTOTYPE_API ABulletBillActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABulletBillActor();

	UPROPERTY(EditAnywhere, Category=Input)
	TSoftObjectPtr<UProjectileMovementComponent> HomingMovementComponent;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void PostInitializeComponents() override;
};
