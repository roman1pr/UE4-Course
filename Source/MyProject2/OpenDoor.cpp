// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject2.h"
#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UOpenDoor::OpenDoor()
{

	FRotator doorRotator = FRotator(0.0f, openAngle, 0.0f);

	Owner->SetActorRotation(doorRotator);
}

void UOpenDoor::CloseDoor()
{

	FRotator doorRotator = FRotator(0.0f, 0.0f, 0.0f);

	Owner->SetActorRotation(doorRotator);
}

// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	Owner = GetOwner();

	ActorOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
	// ...
	
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (PressurePlate->IsOverlappingActor(ActorOpens))
	{
		OpenDoor();
		lastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}
	
	if (GetWorld()->GetTimeSeconds() - lastDoorOpenTime >  DoorClosedDelay)
	{
		CloseDoor();
	}
	// ...
}

