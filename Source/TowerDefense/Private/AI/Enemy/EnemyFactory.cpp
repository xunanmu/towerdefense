// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Enemy/EnemyFactory.h"


// Sets default values
AEnemyFactory::AEnemyFactory()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEnemyFactory::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyFactory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void UEnemyFactory::CreateEnemy(int InitNumber, int Seconds)
{
	const auto BehaviorTree = LoadObject<UBehaviorTree>(nullptr,
		TEXT("BehaviorTree'/Game/TowerDefense/AI/Enemy/EnemyBehaviorTree.EnemyBehaviorTree'"));
	for (int i = 0; i < InitNumber; ++i)
	{
		ABaseCharacter* EnemyPawn = Cast<ABaseCharacter>(RandomCreatePawn());
		AAIController* AIController = CreateEnemyAIController();
		AIController->Possess(EnemyPawn);
		EnemyPawn->BehaviorTree = BehaviorTree;
	}
}

APawn* UEnemyFactory::RandomCreatePawn()
{
	const int RandomNumber = rand() % 1;
	const FRotator ActorRotation(0.0f, -90.0f, 0.f);
	const FVector ActorLocation(968.514099, 37239.257812f, 24555.097656f);
	switch (RandomNumber)
	{
	case 0: return World->SpawnActor<AParagonTwinblastCharacter>(ActorLocation,ActorRotation);
	default: ;
	}
	return nullptr;
}

AAIController* UEnemyFactory::CreateEnemyAIController()
{
	const FActorSpawnParameters SpawnParameters;
	return World->SpawnActor<AEnemyAIController>(SpawnParameters);
}

