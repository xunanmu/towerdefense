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

private:
	FBlackboard::FKey PlayerPawnKey = 0;
	FBlackboard::FKey PositionKey = 0;
	
};
