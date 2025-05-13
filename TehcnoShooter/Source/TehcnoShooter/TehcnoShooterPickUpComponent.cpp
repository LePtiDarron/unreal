// Copyright Epic Games, Inc. All Rights Reserved.

#include "TehcnoShooterPickUpComponent.h"

UTehcnoShooterPickUpComponent::UTehcnoShooterPickUpComponent()
{
	// Setup the Sphere Collision
	SphereRadius = 32.f;
}

void UTehcnoShooterPickUpComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register our Overlap Event
	OnComponentBeginOverlap.AddDynamic(this, &UTehcnoShooterPickUpComponent::OnSphereBeginOverlap);
}

void UTehcnoShooterPickUpComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	ATehcnoShooterCharacter* Character = Cast<ATehcnoShooterCharacter>(OtherActor);
	if(Character != nullptr)
	{
		// Notify that the actor is being picked up
		OnPickUp.Broadcast(Character);

		// Unregister from the Overlap Event so it is no longer triggered
		OnComponentBeginOverlap.RemoveAll(this);
	}
}
