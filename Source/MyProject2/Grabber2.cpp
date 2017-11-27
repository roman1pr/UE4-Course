// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject2.h"
#include "Grabber2.h"

#define OUT

// Sets default values for this component's properties
UGrabber2::UGrabber2()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber2::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Grabber reporter for duty"));
	// ...
	
}


// Called every frame
void UGrabber2::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	FVector Location;
	FRotator Rotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT Location,
		OUT Rotation
	);

	FVector LineTraceEnd = Location + (Rotation.Vector() * Reach);

	DrawDebugLine(
		GetWorld(),
		Location,
		LineTraceEnd,
		FColor(
			255, 0, 0
		),
		false,
		0.0f,
		0.0f,
		10.f
	);

	FHitResult HitResult;

	FCollisionQueryParams TraceParameters(
		FName(TEXT("")),
		false,
		GetOwner()
	);

	GetWorld()->LineTraceSingleByObjectType(
		OUT HitResult,
		Location,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParameters
	);

	AActor* ActorHit = HitResult.GetActor();

	if (ActorHit)
	{
		UE_LOG(LogTemp, Warning, TEXT("Line trace hit : %s"),
			*(ActorHit->GetName())
		);
	}



	//UE_LOG(LogTemp, Warning, TEXT("Location: %s Position: %s"), 
	//	*Location.ToString(), 
	//	*Rotation.ToString()
	//);


}

