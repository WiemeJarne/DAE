// Fill out your copyright notice in the Description page of Project Settings.


#include "Laser.h"
#include "Engine/Engine.h" //Debug messages
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleEmitter.h"

// Sets default values
ALaser::ALaser()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	m_pHealthComponent = CreateDefaultSubobject<UHealthComponent>(FName("HealthComponent"));
	m_pHealthComponent->MaxHealth = 5;
	//m_pHealthComponent->OnDeath.Add(OnDeath());
	m_pSphereCollision = CreateDefaultSubobject<USphereComponent>(FName("SphereCollision"));
	m_pSphereCollision->InitSphereRadius(10.f);
	m_pSphereCollision->SetEnableGravity(false);
	m_pSphereCollision->SetConstraintMode(EDOFMode::XYPlane);
	m_pSphereCollision->CanCharacterStepUpOn = ECanBeCharacterBase::ECB_No;
	m_pSphereCollision->SetNotifyRigidBodyCollision(true);
	m_pSphereCollision->SetCollisionProfileName(FName("OverLapOnlyPawn"));
	SetRootComponent(m_pSphereCollision);

	m_pMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("MovementComponent");
	m_pMovementComponent->InitialSpeed = 500.f;
	m_pMovementComponent->bRotationFollowsVelocity = true;
	m_pMovementComponent->ProjectileGravityScale = 0.f;
	m_pMovementComponent->bShouldBounce = true;
	m_pMovementComponent->Bounciness = 1.f;
	m_pMovementComponent->Friction = 0.f;
	m_pMovementComponent->BounceVelocityStopSimulatingThreshold = 0.f;

	m_pStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(FName("MeshComponent"));
	ConstructorHelpers::FObjectFinder<UStaticMesh> sphereMeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	m_pStaticMeshComponent->SetStaticMesh(sphereMeshAsset.Object);
	m_pStaticMeshComponent->SetWorldScale3D(FVector(0.3f, 0.1f, 0.1f));
	m_pStaticMeshComponent->SetEnableGravity(false);
	m_pStaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	m_pStaticMeshComponent->SetCastShadow(false);
	m_pStaticMeshComponent->SetupAttachment(m_pSphereCollision);
	m_pStaticMeshComponent->SetConstraintMode(EDOFMode::XYPlane);

	m_pMaterialInstance = CreateDefaultSubobject<UMaterialInstanceDynamic>(FName("Material"));
	m_pMaterialInstance->SetVectorParameterValue(FName("Color"), FMath::Lerp(m_Red, m_Green, 1));

	m_pStaticMeshComponent->SetMaterial(0, m_pMaterialInstance);
}

// Called when the game starts or when spawned
void ALaser::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ALaser::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	m_pMaterialInstance->SetVectorParameterValue(FName("Color"), FMath::Lerp(m_Red, m_Green, m_pHealthComponent->GetHealthPercentage()));
}

void ALaser::OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor && OtherActor != this && OtherComp)
	{
		//can't do this because it is not possible to cast to a blueprint in c++
	}
}