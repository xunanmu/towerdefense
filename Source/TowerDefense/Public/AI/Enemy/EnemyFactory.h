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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	/*可以设置设计时间*/
	void CreateEnemy(int InitNumber = 1,int Seconds = 1);
	/*随机生成Pawn的种类*/
	class APawn* RandomCreatePawn();
	/*创建AI控制器*/
	class AAIController* CreateEnemyAIController();
};
