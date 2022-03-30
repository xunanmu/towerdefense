// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AI/BaseAIController.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API AEnemyAIController : public ABaseAIController
{
	GENERATED_BODY()
public:
	AEnemyAIController();
	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;

	/*寻找玩家，用与*/
	void FindPlayer();
	/*攻击玩家*/
	void AttactPlayer();
	
private:
	FBlackboard::FKey PlayerPawnKey = 0;
	FBlackboard::FKey PositionKey = 0;
	
};
