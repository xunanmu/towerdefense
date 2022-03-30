// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "GetPlayerPositionBTTask.generated.h"

/**
 * 
 */
UCLASS(DisplayName="获取玩家pawn位置")
class TOWERDEFENSE_API UGetPlayerPositionBTTask : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
