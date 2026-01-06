// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletBillActor.h"

#include "ChainsawCharacter.h"
#include "EngineUtils.h"
#include "Animation/SkeletalMeshActor.h"
#include "Engine/StaticMeshActor.h"

// Sets default values
ABulletBillActor::ABulletBillActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HomingMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	HomingMovementComponent->bIsHomingProjectile = true;
	HomingMovementComponent->HomingAccelerationMagnitude = 15000.f;
	HomingMovementComponent->ProjectileGravityScale = 0.f;
	HomingMovementComponent->MaxSpeed = 3000.f;
	HomingMovementComponent->InitialSpeed = 3000.f;
}

// Called when the game starts or when spawned
void ABulletBillActor::BeginPlay()
{
	Super::BeginPlay();
	for (TActorIterator<AChainsawCharacter> It(GetWorld()); It; ++It)
	{
		const AChainsawCharacter* Instance = *It;
		HomingMovementComponent->HomingTargetComponent = Cast<USceneComponent>(
			Instance->FindComponentByTag(USceneComponent::StaticClass(), TEXT("Target")));
	}
}

// Called every frame
void ABulletBillActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
