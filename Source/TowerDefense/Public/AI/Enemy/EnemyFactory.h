// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyFactory.generated.h"

UCLASS()
class TOWERDEFENSE_API AEnemyFactory : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEnemyFactory();
	class UBehaviorTree* BehaviorTree;
	int Number;
	int Count;
	FTimerHandle TimerHandle;
	FTimerHandle TimerHandle2;
	
	/**
	 * @brief 生成敌人，可以多种扩展多种怪物多种AI控制器·
	 * @param World 获取当前世界
	 * @param Number 生成敌方的总数
	 */
	void CreateEnemy(int Number = 1);
	/*随机生成Pawn的种类*/
	class ABaseCharacter* RandomCreatePawn();
	/*创建AI控制器*/
	class AAIController* CreateEnemyAIController();
	/*每隔5分钟生成敌方，数量翻倍*/
	void spawnEnemiesEvery5Minutes();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void SpawnEnemiesEvery5Minutes_1();
	void SpawnEnemiesEvery5Minutes_2();
};
