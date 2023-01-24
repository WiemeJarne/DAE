// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "HealthComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Laser.generated.h"

UCLASS()
class LASERPUZZLEGAME_API ALaser : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALaser();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Laser")
	float AmountOfDamage;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UMaterialInstanceDynamic* m_pMaterialInstance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Laser")
	bool m_IsDead;

	UHealthComponent* m_pHealthComponent;

	FLinearColor m_Red{ 1.f, 0.f, 0.f, 1.f };
	FLinearColor m_Green{ 0.f, 1.f, 0.f, 1.f };

	USphereComponent* m_pSphereCollision;
	UProjectileMovementComponent* m_pMovementComponent;
	UStaticMeshComponent* m_pStaticMeshComponent;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
