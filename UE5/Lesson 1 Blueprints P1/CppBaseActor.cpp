// Fill out your copyright notice in the Description page of Project Settings.


#include "CppBaseActor.h"
// Sets default values
ACppBaseActor::ACppBaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	EnemyNum = FMath::RandRange(0, 20);
	IsAlive = FMath::RandBool();
}

// Called when the game starts or when spawned
void ACppBaseActor::BeginPlay()
{
	Super::BeginPlay();
	ShowInformation();
}

// Called every frame
void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ACppBaseActor::ShowInformation() 
{
	FString IntanceName = GetName();

	UE_LOG(LogTemp, Display, TEXT("IntanceName: %s"), *IntanceName);
	UE_LOG(LogTemp, Display, TEXT("EnemyNum: %d"), EnemyNum);
	UE_LOG(LogTemp, Display, TEXT("IsAlive: %i"), IsAlive);
}


