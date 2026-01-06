// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BulletBillSpawner.generated.h"

UCLASS()
class CHAINSAWMANPROTOTYPE_API ABulletBillSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABulletBillSpawner();
	
	FTimerHandle SpawnRateTimerHandle;
	
	UPROPERTY(EditAnywhere, Category=Spawn)
	TSubclassOf<AActor> BlueprintToSpawn;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SpawnBulletBill();
};
