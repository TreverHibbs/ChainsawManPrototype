// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletBillSpawner.h"
#include "TimerManager.h"

// Sets default values
ABulletBillSpawner::ABulletBillSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABulletBillSpawner::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(SpawnRateTimerHandle, this, &ABulletBillSpawner::SpawnBulletBill, 1.0f, true, 2.0f);
}

// Called every frame
void ABulletBillSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABulletBillSpawner::SpawnBulletBill()
{
	UE_LOG(LogTemp, Warning, TEXT("Hello spawner"));
}

