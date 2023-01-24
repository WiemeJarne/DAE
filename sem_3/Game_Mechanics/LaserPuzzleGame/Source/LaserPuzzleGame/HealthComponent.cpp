// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	m_CurrentHealth = MaxHealth;
}

// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthComponent::ResetHealth()
{
	m_CurrentHealth = MaxHealth;
}

float UHealthComponent::GetHealthPercentage() const
{
	return static_cast<float>(m_CurrentHealth) / static_cast<float>(MaxHealth);
}

bool UHealthComponent::IsDead() const
{
	if (GetHealthPercentage() <= 0.0f)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void UHealthComponent::DoDamage_Implementation(int amount, bool& isDead)
{
	int originalHealth = m_CurrentHealth;

	m_CurrentHealth -= amount;
	m_CurrentHealth = FMath::Clamp(m_CurrentHealth, 0, MaxHealth);

	OnDamage.Broadcast(amount);

	isDead = IsDead();
	if (isDead && originalHealth > m_CurrentHealth)
	{
		OnDeath.Broadcast();
	}
}