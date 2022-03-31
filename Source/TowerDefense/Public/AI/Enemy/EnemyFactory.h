// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EnemyFactory.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API UEnemyFactory : public UObject
{
	GENERATED_BODY()
public:
	/*可以设置设计时间*/
	static void CreateEnemy(UWorld* World = GEngine->GetWorld(),int InitNumber = 1,int Seconds = 1);
	/*随机生成Pawn的种类*/
	static class ABaseCharacter* RandomCreatePawn(UWorld* World = GEngine->GetWorld());
	/*创建AI控制器*/
	static class AAIController* CreateEnemyAIController(UWorld* World = GEngine->GetWorld());
};
