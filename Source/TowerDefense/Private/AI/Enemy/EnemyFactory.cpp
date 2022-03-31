// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Enemy/EnemyFactory.h"

#include "AI/Enemy/EnemyAIController.h"
#include "Character/ParagonTwinblastCharacter.h"
#include "BehaviorTree/BehaviorTree.h"

void UEnemyFactory::CreateEnemy(UWorld* World, int InitNumber, int Seconds)
{
	/*如果敌人个体有单独变量，行为树需要独立绑定*/
	UBehaviorTree* BehaviorTree = LoadObject<UBehaviorTree>(nullptr,
	TEXT("BehaviorTree'/Game/TowerDefense/AI/Enemy/EnemyBehaviorTree.EnemyBehaviorTree'"));
	for (int i = 0; i < InitNumber; ++i)
	{
		ABaseCharacter* EnemyPawn = RandomCreatePawn(World);
		AAIController* AIController = CreateEnemyAIController(World);
		/*玄学 行为树绑定必须在控制器绑定之前*/
		EnemyPawn->BehaviorTree = BehaviorTree;
		AIController->Possess(EnemyPawn);
		
	}
}

ABaseCharacter* UEnemyFactory::RandomCreatePawn(UWorld* World)
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

AAIController* UEnemyFactory::CreateEnemyAIController(UWorld* World)
{
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.Instigator = nullptr;
	return World->SpawnActor<AEnemyAIController>(SpawnParameters);
}
