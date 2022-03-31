// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Enemy/EnemyFactory.h"
#include "BehaviorTree/BehaviorTree.h"
#include "AI/Enemy/EnemyAIController.h"
#include "Character/ParagonTwinblastCharacter.h"

// Sets default values
AEnemyFactory::AEnemyFactory()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	/*如果敌人个体有单独变量，行为树需要独立绑定*/
	BehaviorTree = LoadObject<UBehaviorTree>(nullptr,
	TEXT("BehaviorTree'/Game/TowerDefense/AI/Enemy/EnemyBehaviorTree.EnemyBehaviorTree'"));
	/*初始敌人数*/
	Number = 1;
	Count = 0;
}

void AEnemyFactory::CreateEnemy(int number)
{
	for (int i = 0; i < number; ++i)
	{
		ABaseCharacter* EnemyPawn = RandomCreatePawn();
		AAIController* AIController = CreateEnemyAIController();
		/*玄学 行为树绑定必须在控制器绑定之前*/
		EnemyPawn->BehaviorTree = BehaviorTree;
		AIController->Possess(EnemyPawn);
	}
	UE_LOG(LogTemp,Error,TEXT("生成敌人人数%d"),number);
}

ABaseCharacter* AEnemyFactory::RandomCreatePawn()
{
	const int RandomNumber = rand() % 1;
	const FRotator ActorRotation(0.0f, -90.0f, 0.f);
	const FVector ActorLocation(968.514099, 37239.257812f, 24585.097656f);
	/*以后维护switch就好了*/
	switch (RandomNumber)
	{
	case 0: return GetWorld()->SpawnActor<AParagonTwinblastCharacter>(ActorLocation,ActorRotation);
	default: ;
	}
	return nullptr;
}

AAIController* AEnemyFactory::CreateEnemyAIController()
{
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.Instigator = nullptr;
	return GetWorld()->SpawnActor<AEnemyAIController>(SpawnParameters);
}

void AEnemyFactory::spawnEnemiesEvery5Minutes()
{
	// GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
	GetWorld()->GetTimerManager().SetTimer(TimerHandle,this,&AEnemyFactory::SpawnEnemiesEvery5Minutes_1,300,true,0);
}

void AEnemyFactory::BeginPlay()
{
	Super::BeginPlay();
	spawnEnemiesEvery5Minutes();
}

void AEnemyFactory::SpawnEnemiesEvery5Minutes_1()
{
	Number <<= 1;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle2,this,&AEnemyFactory::SpawnEnemiesEvery5Minutes_2,1,true,0);
}

void AEnemyFactory::SpawnEnemiesEvery5Minutes_2()
{
	if (Count<Number)
	{
		CreateEnemy(1);
		Count++;
	}
	else
	{
		Count = 0;
		// GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
		GetWorld()->GetTimerManager().ClearTimer(TimerHandle2);
	}
	
}

