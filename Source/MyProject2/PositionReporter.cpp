// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject2.h"
#include "PositionReporter.h"


// Sets default values for this component's properties
UPositionReporter::UPositionReporter()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.

	PrimaryComponentTick.bCanEverTick = true;


	// ...
}


// Called when the game starts
void UPositionReporter::BeginPlay()
{
	Super::BeginPlay();

	FString name = GetOwner()->GetName();
	auto position = GetOwner()->GetActorTransform().GetLocation().ToString();
	UE_LOG(LogTemp, Warning, TEXT("Position reporter for %s with pos: %s"), *name, *position);
	// ...
	
}


// Called every frame
void UPositionReporter::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

